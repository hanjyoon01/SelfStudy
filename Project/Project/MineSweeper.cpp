#include "MineSweeper.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <iomanip>
#include <Windows.h>
#include <conio.h>
#include <fstream>

using namespace std;

namespace jyhan {
	void printName() {
		std::cout << " �й�:202011390 �̸�:������" << std::endl;
	}
}
void setCursorView(bool visible) {
	CONSOLE_CURSOR_INFO cursor = { 1,visible };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}
void gotoxy(int x, int y) {
	COORD Pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

//�⺻ ������
MineSweeper::MineSweeper()
{
	//saveCount �ʱ�ȭ
	loadSaveCount();
}

//�Ҹ���
MineSweeper::~MineSweeper()
{
}

//�޴� ȭ�� ���
void MineSweeper::start()
{
	system("cls");
	cout << "\n";
	jyhan::printName();
	cout << "\n";

	int menu;
	ifstream fin;
	ofstream fout;

	cout << " �ڡڡڡڡڡڡ� ���� ã�� �ڡڡڡڡڡڡ�\n" << endl;
	cout << " 1)���� �÷���	2)�̾��ϱ�   3)����\n" << endl;
	cout << " �޴��� �����ϼ���: ";
	cin >> menu;

	// 1)���� �÷���
	if (menu == 1) {
		system("cls");
		cout << "\n";
		jyhan::printName();
		cout << "\n";

		//�� ũ��, ���̵� �Է�
		char dif;
		cout << " ���� ũ�⸦ �Է��ϼ���(��� �� ���ʷ� �Է�, ���� ũ��� 10 �̻�): ";
		cin >> row >> col;

		system("cls");
		cout << "\n";
		jyhan::printName();
		cout << "\n";

		cout << " ���̵��� �Է��ϼ��� (E,N,H): ";
		cin >> dif;
		switch (dif) {
		case 'E':
			ratio = 0.1;
			break;
		case 'N':
			ratio = 0.2;
			break;
		case 'H':
			ratio = 0.3; 
			break;
		}

		// �� ���� �� ���� ����
		makeMap();
		cout << "\n ������ �ε����Դϴ�... ";
		Sleep(2000);
		play();
	}

	// 2)�̾��ϱ�
	else if (menu == 2) {
		system("cls");
		cout << "\n";
		jyhan::printName();
		cout << "\n";

		//����� ���� ��� ��� (�ִ� 3��)
		cout << " ********** ����� ���� ********** \n" << endl;
		for (int i = 0; i < 3; i++) {
			cout << " " << i + 1 << ") ";
			fin.open("save" + to_string(i+1) + ".txt");

			//����� ���� �����ϴ��� ���� Ȯ��
			int isSaved;
			fin >> isSaved;

			//���� �����Ѵٸ�
			if (isSaved == 1) {
				//�� ũ��� ���̵� ��� 
				double diff;
				int r, c;
				fin >> diff >> r >> c;

				if (diff == 0.1)
					cout << "�� ũ�� (" << r << " X " << c << "), ���̵�: E" << endl;
				else if (diff == 0.2)
					cout << "�� ũ�� (" << r << " X " << c << "), ���̵�: N" << endl;
				else if (diff == 0.3)
					cout << "�� ũ�� (" << r << " X " << c << "), ���̵�: H" << endl;
			}
			//���� �������� �ʴ´ٸ�
			else if (isSaved == 0) {
				cout << "����� �� ����\n";
			}
			fin.close();
			cout << endl;
		}
		cout << " 4) ����� �� �ʱ�ȭ\n" << endl;

		int m;
		cout << " ����� ������ �����ϼ���: ";
		cin >> m;
		cout << "\n ";
		
		// 1~3)����� �� ����
		if (m <= 3) {
			loadSavedMap(m - 1);
			cout << "������ �ε����Դϴ�... ";
			Sleep(2000);
			play();
		}

		// 4)����� �� �ʱ�ȭ
		else if (m == 4) {
			//�ʱ�ȭ ���� Ȯ��
			cout << "����� ������ ��� �����Ͻðڽ��ϱ�? (Y, N): ";
			char m;
			cin >> m;
			cout << "\n ";
			switch (m) {
			//�ʱ�ȭ �� ��
			case 'Y':
				// 3���� ���̺� ������ ��� �ʱ�ȭ
				for (int i = 0; i < 3; i++) {
					fout.open("save" + to_string(i + 1) + ".txt");
					fout << 0;
					fout.close();
				}
				cout << "����� ������ ��� �ʱ�ȭ�մϴ�. �޴��� ���ư��ϴ�...";
				Sleep(2000);
				isEnd = false;
				isClear = false;
				deleteMap();
				start();
				break;
			//�ʱ�ȭ���� ���� ��
			case 'N':
				//�ʱ�ȭ���� �ʰ� �޴� ȭ������ ����
				cout << "�޴��� ���ư��ϴ�...";
				Sleep(2000);
				isEnd = false;
				isClear = false;
				deleteMap();
				start();
				break;
			}
		}
	}

	// 3)����
	else if (menu == 3) {
		cout << "\n ������ �����մϴ�...\n\n ";
		exit(0);
	}
}

//�÷��� ȭ��
void MineSweeper::play()
{
	//�� ���
	printMap();
	
	//���� ��ġ
	int x = 0;
	int y = 3;
	gotoxy(x, y);

	//������ ����� ������ ���� �ݺ�
	while (!isEnd) { //������ ������ �ʾҴٸ�
		if (_kbhit()) {
			int keycode = _getch();

			//����Ű�� ���� �� (�̵�)
			if (keycode == 224) {
				keycode = _getch();
				switch (keycode) {
				case 75: 
					if(x > 0)
						x -= 2; 
					break;
				case 77:
					if (x < 2*(col-1))
						x += 2; 
					break;
				case 72: 
					if (y > 3)
						y -= 1; 
					break;
				case 80:
					if (y < 3 + (row-1))
						y += 1; 
					break;
				}
			}
			//Enter�� ���� �� (����)
			if (keycode == 13) {
				openMine(y - 3, x / 2);
				printMap();
			}
			//Tab�� ���� �� (���)
			if (keycode == 9) {
				checkMine(y - 3, x / 2);
				printMap();
			}
			//Esc�� ���� �� (����)
			if (keycode == 27) {
				isEnd = true;
			}
			gotoxy(x, y);
		}
	}

	//���� �ݺ��� ����Ǿ��� �� (���� ����, ���� Ŭ����, ���� ����)
	//���� ����
	if (Status[y - 3][x / 2] == 2 && Map[y - 3][x / 2] == 9 && !isClear) {
		printMap();
		Sleep(2000);
		gotoxy(0, row + 6);
		char m;
		//����� ���� Ȯ��
		cout << " ���ڸ� ��� ���ӿ��� �й��߽��ϴ�. �ٽ� �Ͻðڽ��ϱ�? (Y, N): ";
		cin >> m;
		cout << "\n ";
		switch (m) {
		//������� ��
		case 'Y':
			//������ ������ �����
			cout << "������ ������ ������մϴ�...";
			Sleep(2000);
			isEnd = false;
			isClear = false;
			for (int i = 0; i < row; i++) {
				for (int j = 0; j < col; j++) {
					Status[i][j] = 0;
				}
			}
			play();
			break;
		//��������� ���� ��
		case 'N':
			//�޴� ȭ������ ����
			cout << "�޴��� ���ư��ϴ�...";
			Sleep(2000);
			isEnd = false;
			isClear = false;
			deleteMap();
			start();
			break;
		}
	}

	//���� Ŭ����
	else if (((Status[y - 3][x / 2] == 1 && Map[y - 3][x / 2] == 9) || (Status[y - 3][x / 2] == 2 && Map[y - 3][x / 2] != 9)) && isClear) {
		//�޴� ȭ������ ����
		printMap();
		Sleep(2000);
		gotoxy(0, row + 6);
		cout << " ��� ���ڸ� ã�� ���ӿ��� �¸��߽��ϴ�. �޴��� ���ư����� �ƹ� Ű�� ��������...\n" << endl;
		_getch();
		cout << " �޴��� ���ư��ϴ�...";
		Sleep(2000);
		isEnd = false;
		isClear = false;
		deleteMap();
		start();
	}

	//���� ����
	else {
		char m;
		ofstream fout;
		gotoxy(0, row + 6);
		//���� ���� ���� Ȯ��
		cout << " �޴��� ���ư��ϴ�. �÷����ϴ� ������ �����Ͻðڽ��ϱ�? (Y, N): ";
		cin >> m;
		cout << "\n ";
		switch (m) {
		//������ ��
		case 'Y':
			//saveCount ���� ���� ���� ���� ����
			switch (saveCount) {
			case 0:
				//�� ���� ����, ����, Map �迭, Status �迭 ����
				fout.open("save1.txt");
				fout << 1 << " " << ratio << endl;
				fout << row << " " << col << endl;
				for (int i = 0; i < row; i++) {
					for (int j = 0; j < col; j++) {
						fout << Map[i][j] << " ";
					}
				}
				fout << endl;
				for (int i = 0; i < row; i++) {
					for (int j = 0; j < col; j++) {
						fout << Status[i][j] << " ";
					}
				}
				fout.close();
				cout << "�÷����ϴ� ������ �����ϰ� �޴��� ���ư��ϴ�... ";
				saveCount++;
				break;
			case 1:
				//�� ���� ����, ����, Map �迭, Status �迭 ����
				fout.open("save2.txt");
				fout << 1 << " " << ratio << endl;
				fout << row << " " << col << endl;
				for (int i = 0; i < row; i++) {
					for (int j = 0; j < col; j++) {
						fout << Map[i][j] << " ";
					}
				}
				fout << endl;
				for (int i = 0; i < row; i++) {
					for (int j = 0; j < col; j++) {
						fout << Status[i][j] << " ";
					}
				}
				fout.close();
				cout << "�÷����ϴ� ������ �����ϰ� �޴��� ���ư��ϴ�... ";
				saveCount++;
				break;
			case 2:
				//�� ���� ����, ����, Map �迭, Status �迭 ����
				fout.open("save3.txt");
				fout << 1 << " " << ratio << endl;
				fout << row << " " << col << endl;
				for (int i = 0; i < row; i++) {
					for (int j = 0; j < col; j++) {
						fout << Map[i][j] << " ";
					}
				}
				fout << endl;
				for (int i = 0; i < row; i++) {
					for (int j = 0; j < col; j++) {
						fout << Status[i][j] << " ";
					}
				}
				fout.close();
				cout << "�÷����ϴ� ������ �����ϰ� �޴��� ���ư��ϴ�... ";
				saveCount++;
				break;
			//���� �̹� 3�� ����Ǿ����� ��
			case 3:
				//������ �� �����Ƿ� ������� ���� Ȯ��
				cout << "���� �̹� 3�� ����Ǿ� ������ �� �����ϴ�. ���������� ����� ���ӿ� �����ðڽ��ϱ�? (Y, N): ";
				cin >> m;
				cout << "\n ";
				switch (m) {
				//����ﶧ
				case 'Y':
					//3�� ���Ͽ� ���� �� �޴� ȭ������ ����
					fout.open("save3.txt");
					fout << 1 << " " << ratio << endl;
					fout << row << " " << col << endl;
					for (int i = 0; i < row; i++) {
						for (int j = 0; j < col; j++) {
							fout << Map[i][j] << " ";
						}
					}
					fout << endl;
					for (int i = 0; i < row; i++) {
						for (int j = 0; j < col; j++) {
							fout << Status[i][j] << " ";
						}
					}
					fout.close();
					cout << "�÷����ϴ� ������ �����ϰ� �޴��� ���ư��ϴ�... ";
					break;
				//������� ���� ��
				case 'N':
					//�޴� ȭ������ ����
					cout << "�������� �ʰ� �޴��� ���ư��ϴ�... ";
					break;
				}
			}
			//�޴� ȭ������ ����
			Sleep(2000);
			isEnd = false;
			isClear = false;
			deleteMap();
			start();
			break;

		//�������� ���� ��
		case 'N':
			//�޴� ȭ������ ����
			cout << "�������� �ʰ� �޴��� ���ư��ϴ�... ";
			Sleep(2000);
			isEnd = false;
			isClear = false;
			deleteMap();
			start();
			break;
		}
	}
}

//�� ����
void MineSweeper::makeMap()
{
	srand(time(NULL));

	//���̵��� ���� ���� ���� ����
	int mines = int(row * col * ratio); 

	//���ڴ� 9, �������� 0���� ����
	Map = new int* [row];
	for (int i = 0; i < row; i++) {
		Map[i] = new int[col];
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			Map[i][j] = 0;
		}
	}

	//�ߺ� ����
	for (int i = 0; i < mines; i++) {
		int r = rand() % row;
		int c = rand() % col;
		if (Map[r][c] == 9) {
			i--;
		}
		Map[r][c] = 9;
	}

	//����, ���, �̿��� ���� ����
	Status = new int* [row];
	for (int i = 0; i < row; i++) {
		Status[i] = new int[col];
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			Status[i][j] = 0;
		}
	}

	//�ֺ��� ���� ���� ����ؼ� 1�� ����
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			for (int k = 0; k < row; k++) {
				for (int l = 0; l < col; l++) {
					if ((i != k || j != l) && (abs(i - k) <= 1 && abs(j - l) <= 1)) {
						if(Map[k][l] == 9 && Map[i][j] != 9)
							Map[i][j]++;
					}
				}
			}
		}
	}
}

//Map�迭, Status�迭 ����
void MineSweeper::deleteMap()
{
	if (Map != nullptr) {
		for (int i = 0; i < row; i++) {
			delete[] Map[i];
		}
		delete[] Map;
		Map = nullptr;
	}
	if (Status != nullptr) {
		for (int i = 0; i < row; i++) {
			delete[] Status[i];
		}
		delete[] Status;
		Status = nullptr;
	}
}

//�� ȭ�� ���
void MineSweeper::printMap()
{
	system("cls");

	cout << "\n";
	jyhan::printName();
	cout << "\n";

	//Status�� ���� �ٸ��� ���
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			switch(Status[i][j]) {
			//���µ��� ����
			case 0:
				cout << "��";
				break;
			//���
			case 1:
				cout << "��";
				break;
			//���µ�
			case 2:
				cout << " " << Map[i][j];
				break;
			}
		}
		cout << endl;
	}
	cout << "\n �����:�̵� / Enter: ���� / Tab: ���";
}

//EnterŰ �Է� �� (����)
void MineSweeper::openMine(int mx, int my)
{
	//���µ��� �ʾҴٸ�
	if (Status[mx][my] == 0) {
		Status[mx][my] = 2; //������
		if (Map[mx][my] == 0) { //�ֺ��� ���ڰ� �������� �ʴ� ���̶��
			for (int i = 0; i < row; i++) {
				for (int j = 0; j < col; j++) {
					//8���� �����Լ� ��� ȣ��
					if ((i != mx || j != my) && (abs(i - mx) <= 1 && abs(j - my) <= 1)) {
						openMine(i, j);
					}
				}
			}
		}
		//���ڸ� �������� ��(���� ����)
		if (Map[mx][my] == 9) {
			isEnd = true;
		}
	}

	//���ڸ� ��� üũ�ϰ� �� ���� ���� ��� �������� ��(���� Ŭ����)
	int count = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if ((Map[i][j] != 9 && Status[i][j] == 2) || (Map[i][j] == 9 && Status[i][j] == 1)) {
				count++;
			}
		}
	}
	if (count == row * col) {
		isEnd = true;
		isClear = true;
	}
}

//TabŰ �Է� �� (���)
void MineSweeper::checkMine(int mx, int my)
{
	//�̿��»����� �� ��߷� ��ȯ
	if (Status[mx][my] == 0) {
		Status[mx][my] = 1;
	}
	//����� �� �̿��»��·� ��ȯ
	else if (Status[mx][my] == 1) {
		Status[mx][my] = 0;
	}

	//���ڸ� ��� üũ�ϰ� �� ���� ���� ��� �������� ��(���� Ŭ����)
	int count = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if ((Map[i][j] != 9 && Status[i][j] == 2) || (Map[i][j] == 9 && Status[i][j] == 1)) {
				count++;
			}
		}
	}
	if (count == row * col) {
		isEnd = true;
		isClear = true;
	}
}

//����� �� �ҷ�����
void MineSweeper::loadSavedMap(int i)
{
	ifstream fin;
	fin.open("save" + to_string(i + 1) + ".txt");
	int a; //�����Ⱚ

	//ratio ���� (���߿� ��� �� ���)
	fin >> a >> ratio;
	//��, �� �� ����
	fin >> row >> col;

	//����� �� ���� �� ����
	Map = new int* [row];
	for (int i = 0; i < row; i++) {
		Map[i] = new int[col];
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			fin >> Map[i][j];
		}
	}
	Status = new int* [row];
	for (int i = 0; i < row; i++) {
		Status[i] = new int[col];
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			fin >> Status[i][j];
		}
	}
	fin.close();
}

//saveCount �ʱ�ȭ
void MineSweeper::loadSaveCount()
{
	ifstream fin;
	for (int i = 0; i < 3; i++) {
		fin.open("save" + to_string(i + 1) + ".txt");
		int isSaved;
		fin >> isSaved;

		//���� �����Ѵٸ�
		if (isSaved == 1) {
			saveCount++; //�� ����
		}
		fin.close();
	}
}
