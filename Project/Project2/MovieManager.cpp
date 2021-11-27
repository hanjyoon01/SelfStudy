#include "MovieManager.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <ctime>
#include <stdlib.h>

using namespace std;

namespace jyhan2 {
	void printName() {
		std::cout << "  �й�:202011390 �̸�:������" << std::endl;
	}
}

MovieManager::MovieManager(const string& txt)
	:txt(txt)
{
	//cout << "MovieManager ������" << endl; //������ �׽�Ʈ��

	srand((unsigned)time(NULL));

	ifstream fin(this->txt);
	string end;

	if (!fin.is_open()) {
		cerr << "���� ���� ����" << endl;
		exit(0);
	}

	//��ȭ ���� ����
	fin >> count;
	getline(fin, end);

	movie = new Movie*[count];

	for (int i = 0; i < count; i++) {

		string n;
		int r, c;
		
		getline(fin, n);
		fin >> r >> c;
		
		movie[i] = new Movie(n, r, c);
		getline(fin, end);
	}
}

MovieManager::MovieManager(const MovieManager& MM)
{
	cout << "MovieManager ���� ������" << endl;
	count = MM.count;
	txt = MM.txt;
	movie = new Movie *[MM.count];
	for (int i = 0; i < count; i++) {
		movie[i] = new Movie(*MM.movie[i]);
	}
}

MovieManager::MovieManager(MovieManager&& MM) noexcept: count(MM.count), txt(MM.txt), movie(MM.movie)
{
	cout << "MovieManager �̵� ������" << endl;
	MM.count = 0;
	MM.txt = "";
	MM.movie = nullptr;
}

MovieManager::~MovieManager()
{
	//cout << "MovieManager �Ҹ���" << endl; //�Ҹ��� �׽�Ʈ��
	//movie �޸� ����
	for (int i = 0; i < count; i++) {
		delete movie[i];
		movie[i] = nullptr;
	}
	delete movie;
	movie = nullptr;
}

void MovieManager::ticketing()
{
	system("cls");

	cout << "\n";
	jyhan2::printName();
	cout << "\n";

	int s; //��ȭ ���� �Ű�����a
	cout << "========================��ȭ ����========================\n\n";

	//��ȭ ��� ���
	for (int i = 0; i < count; i++) {
		cout << "\t" << i + 1 << ")" << left << setw(20) << (*movie[i]).getName() << "\t\t"
			<< (*movie[i]).getLS() << "/" << (*movie[i]).getFS() << ((*movie[i]).getLS() == 0 ? "(����)" : "") << endl;
	}

	//��ȭ ����
	cout << "\n     ������ ��ȭ�� �����ϼ���(��ȣ): ";
	cin >> s;

	system("cls");

	cout << "\n";
	jyhan2::printName();
	cout << "\n";
	cout << "========================��ȭ ����========================\n\n";

	//�¼� ���
	(*movie[s-1]).printSeat();

	//���� �¼� �Է�
	cout << "  �¼� �Է� (ex ==> A1) : ";
	char x;
	int y;
	cin >> x >> y;

	//�¼� ����
	if (x < 'A' or x >= 'A' + (*movie[s - 1]).getRow() or y < 1 or y > (*movie[s - 1]).getCol()) {
		cout << "\n ���� �ڸ��Դϴ�. �ٽ� �Է��ϼ���.\n\n ";
	}
	else {
		int c = 0;
		if ((*movie[s - 1]).getSeat(x - 'A', y - 1) != 0) {
			cout << "\n �̹� ���ŵ� �ڸ��Դϴ�. (���Ź�ȣ: " << (*movie[s - 1]).getSeat(x - 'A', y - 1) << ")\n\n ";
		}

		//���� ��ȣ �ߺ� ����
		else {
			while (true) {
				(*movie[s - 1]).setSeat(x - 'A', y - 1, rand() % 999 + 1);
				for (int i = 1; i < c; i++) {
					for (int j = 0; j < (*movie[s - 1]).getRow(); j++) {
						for (int k = 0; k < (*movie[s - 1]).getCol(); k++) {
							if ((*movie[s - 1]).getSeat(x - 'A', y - 1) == (*movie[i]).getSeat(j, k))
								c++;
						}
					}
				}
				//���� �Ϸ�� �ܿ� �¼� ����
				if (c == 0) {
					cout << "\n ���Ű� �Ϸ�Ǿ����ϴ�. (���Ź�ȣ: " << (*movie[s - 1]).getSeat(x - 'A', y - 1) << ")\n\n ";
					(*movie[s - 1]).decrLS();
					break;
				}
			}
		}
	}
	system("pause");
	system("cls");
}

void MovieManager::ticketCancel()
{
	system("cls");

	int cancelnum; //����� ��ȣ

	cout << "\n";
	jyhan2::printName();
	cout << "\n";
	cout << "====================���� ���====================\n\n";
	cout << " ���� ��ȣ�� �Է����ּ���: ";
	cin >> cancelnum;

	int c = 0; //���� ��ȣ ���� ���� Ȯ��

	//���� ��ȣ �� �� ���
	for (int i = 0; i < count; i++) {
		for (int j = 0; j < (*movie[i]).getRow(); j++) {
			for (int k = 0; k < (*movie[i]).getCol(); k++) {
				if (cancelnum == (*movie[i]).getSeat(j,k)) {
					cout << "\n ���� ��Ұ� �Ϸ�Ǿ����ϴ�.";
					cout << "(" << (*movie[i]).getName() << ", " << char('A' + j) << k + 1 << ")\n\n ";
					(*movie[i]).incrLS(); //�ܿ��¼� �߰�
					(*movie[i]).setSeat(j, k, 0); //���� ��ȣ �ʱ�ȭ
					c++;
					system("pause");
					system("cls");
				}
			}
		}
	}

	//���� ��ȣ �������
	if (c == 0) {
		cout << "\n ���� ��ȣ�� �������� �ʽ��ϴ�.\n\n ";
		system("pause");
		system("cls");
	}
}

void MovieManager::ticketCheck()
{
	system("cls");
	int checknum; //Ȯ���� ��ȣ
	int c = 0; //���� ��ȣ ���� ���� Ȯ��
	cout << "\n";
	jyhan2::printName();
	cout << "\n";
	cout << "====================���� Ȯ��====================\n\n";
	cout << " ���� ��ȣ�� �Է����ּ���: ";
	cin >> checknum;

	//���� ��ȣ �� �� ���� ���
	for (int i = 0; i < count; i++) {
		for (int j = 0; j < (*movie[i]).getRow(); j++) {
			for (int k = 0; k < (*movie[i]).getCol(); k++) {
				if (checknum == (*movie[i]).getSeat(j, k)) {

					//���� ���� ���
					cout << "\n �����Ͻ� ��ȭ: " << (*movie[i]).getName() << endl;
					cout << "\n �����Ͻ� �¼�: " << char('A' + j) << k + 1 << "\n\n";
					cout << "====================���� �¼�====================\n\n";

					//���� �¼� ���
					for (int l = 0; l < (*movie[i]).getCol(); l++)
						cout << "  " << '\t' << l + 1;
					cout << "\n\n ";

					for (int y = 0; y < (*movie[i]).getRow(); y++) {
						cout << "  " << static_cast<char>('A' + y) << '\t';
						for (int z = 0; z < (*movie[i]).getCol(); z++) {
							cout << (checknum == (*movie[i]).getSeat(y, z) ? "��" : "��") << '\t';
						}
						cout << "\n\n ";
						c++;
					}
					system("pause");
					system("cls");
				}
			}
		}
	}

	//���� ��ȣ �������
	if (c == 0) {
		cout << "\n ���� ��ȣ�� �������� �ʽ��ϴ�.\n\n ";
		system("pause");
		system("cls");
	}
}

void MovieManager::startMenu()
{
	int i = 0;
	while (true) {

		if (i != 0) {
			cout << "\n";
			jyhan2::printName();
			cout << "\n";
		}
		i++;

		int menu;
		cout << "===========================GGV===========================\n" << endl;
		cout << "  1) ��ȭ ����  2) ���� ���  3) ���� Ȯ��  4) ����\n" << endl;
		cout << "  �޴��� �����ϼ���: ";
		cin >> menu;

		//1�� �޴�
		if (menu == 1) {
			this->ticketing();
		}
		//2�� �޴�
		else if (menu == 2) {
			this->ticketCancel();
		}
		//3�� �޴�
		else if (menu == 3) {
			this->ticketCheck();
		}
		//����
		else if (menu == 4) {
			cout << "\n  ��ȭ ���Ÿ� �����մϴ�.\n\n";
			break;
		}
	}
}
