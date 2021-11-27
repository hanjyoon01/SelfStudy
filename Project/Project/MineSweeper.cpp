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
		std::cout << " 학번:202011390 이름:한재윤" << std::endl;
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

//기본 생성자
MineSweeper::MineSweeper()
{
	//saveCount 초기화
	loadSaveCount();
}

//소멸자
MineSweeper::~MineSweeper()
{
}

//메뉴 화면 출력
void MineSweeper::start()
{
	system("cls");
	cout << "\n";
	jyhan::printName();
	cout << "\n";

	int menu;
	ifstream fin;
	ofstream fout;

	cout << " ★★★★★★★ 지뢰 찾기 ★★★★★★★\n" << endl;
	cout << " 1)새로 플레이	2)이어하기   3)종료\n" << endl;
	cout << " 메뉴를 선택하세요: ";
	cin >> menu;

	// 1)새로 플레이
	if (menu == 1) {
		system("cls");
		cout << "\n";
		jyhan::printName();
		cout << "\n";

		//맵 크기, 난이도 입력
		char dif;
		cout << " 맵의 크기를 입력하세요(행과 열 차례로 입력, 맵의 크기는 10 이상): ";
		cin >> row >> col;

		system("cls");
		cout << "\n";
		jyhan::printName();
		cout << "\n";

		cout << " 난이도를 입력하세요 (E,N,H): ";
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

		// 맵 생성 후 게임 시작
		makeMap();
		cout << "\n 게임을 로딩중입니다... ";
		Sleep(2000);
		play();
	}

	// 2)이어하기
	else if (menu == 2) {
		system("cls");
		cout << "\n";
		jyhan::printName();
		cout << "\n";

		//저장된 게임 목록 출력 (최대 3개)
		cout << " ********** 저장된 게임 ********** \n" << endl;
		for (int i = 0; i < 3; i++) {
			cout << " " << i + 1 << ") ";
			fin.open("save" + to_string(i+1) + ".txt");

			//저장된 맵이 존재하는지 여부 확인
			int isSaved;
			fin >> isSaved;

			//맵이 존재한다면
			if (isSaved == 1) {
				//맵 크기와 난이도 출력 
				double diff;
				int r, c;
				fin >> diff >> r >> c;

				if (diff == 0.1)
					cout << "맵 크기 (" << r << " X " << c << "), 난이도: E" << endl;
				else if (diff == 0.2)
					cout << "맵 크기 (" << r << " X " << c << "), 난이도: N" << endl;
				else if (diff == 0.3)
					cout << "맵 크기 (" << r << " X " << c << "), 난이도: H" << endl;
			}
			//맵이 존재하지 않는다면
			else if (isSaved == 0) {
				cout << "저장된 맵 없음\n";
			}
			fin.close();
			cout << endl;
		}
		cout << " 4) 저장된 맵 초기화\n" << endl;

		int m;
		cout << " 저장된 게임을 선택하세요: ";
		cin >> m;
		cout << "\n ";
		
		// 1~3)저장된 맵 선택
		if (m <= 3) {
			loadSavedMap(m - 1);
			cout << "게임을 로딩중입니다... ";
			Sleep(2000);
			play();
		}

		// 4)저장된 맵 초기화
		else if (m == 4) {
			//초기화 여부 확인
			cout << "저장된 게임을 모두 삭제하시겠습니까? (Y, N): ";
			char m;
			cin >> m;
			cout << "\n ";
			switch (m) {
			//초기화 할 때
			case 'Y':
				// 3개의 세이브 파일을 모두 초기화
				for (int i = 0; i < 3; i++) {
					fout.open("save" + to_string(i + 1) + ".txt");
					fout << 0;
					fout.close();
				}
				cout << "저장된 게임을 모두 초기화합니다. 메뉴로 돌아갑니다...";
				Sleep(2000);
				isEnd = false;
				isClear = false;
				deleteMap();
				start();
				break;
			//초기화하지 않을 때
			case 'N':
				//초기화하지 않고 메뉴 화면으로 복귀
				cout << "메뉴로 돌아갑니다...";
				Sleep(2000);
				isEnd = false;
				isClear = false;
				deleteMap();
				start();
				break;
			}
		}
	}

	// 3)종료
	else if (menu == 3) {
		cout << "\n 게임을 종료합니다...\n\n ";
		exit(0);
	}
}

//플레이 화면
void MineSweeper::play()
{
	//맵 출력
	printMap();
	
	//시작 위치
	int x = 0;
	int y = 3;
	gotoxy(x, y);

	//게임이 종료될 때까지 무한 반복
	while (!isEnd) { //게임이 끝나지 않았다면
		if (_kbhit()) {
			int keycode = _getch();

			//방향키를 누를 때 (이동)
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
			//Enter를 누를 때 (오픈)
			if (keycode == 13) {
				openMine(y - 3, x / 2);
				printMap();
			}
			//Tab을 누를 때 (깃발)
			if (keycode == 9) {
				checkMine(y - 3, x / 2);
				printMap();
			}
			//Esc을 누를 때 (저장)
			if (keycode == 27) {
				isEnd = true;
			}
			gotoxy(x, y);
		}
	}

	//무한 반복이 종료되었을 때 (게임 오버, 게임 클리어, 게임 저장)
	//게임 오버
	if (Status[y - 3][x / 2] == 2 && Map[y - 3][x / 2] == 9 && !isClear) {
		printMap();
		Sleep(2000);
		gotoxy(0, row + 6);
		char m;
		//재시작 여부 확인
		cout << " 지뢰를 밟아 게임에서 패배했습니다. 다시 하시겠습니까? (Y, N): ";
		cin >> m;
		cout << "\n ";
		switch (m) {
		//재시작할 때
		case 'Y':
			//동일한 맵으로 재시작
			cout << "동일한 맵으로 재시작합니다...";
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
		//재시작하지 않을 때
		case 'N':
			//메뉴 화면으로 복귀
			cout << "메뉴로 돌아갑니다...";
			Sleep(2000);
			isEnd = false;
			isClear = false;
			deleteMap();
			start();
			break;
		}
	}

	//게임 클리어
	else if (((Status[y - 3][x / 2] == 1 && Map[y - 3][x / 2] == 9) || (Status[y - 3][x / 2] == 2 && Map[y - 3][x / 2] != 9)) && isClear) {
		//메뉴 화면으로 복귀
		printMap();
		Sleep(2000);
		gotoxy(0, row + 6);
		cout << " 모든 지뢰를 찾아 게임에서 승리했습니다. 메뉴로 돌아가려면 아무 키나 누르세요...\n" << endl;
		_getch();
		cout << " 메뉴로 돌아갑니다...";
		Sleep(2000);
		isEnd = false;
		isClear = false;
		deleteMap();
		start();
	}

	//게임 저장
	else {
		char m;
		ofstream fout;
		gotoxy(0, row + 6);
		//게임 저장 여부 확인
		cout << " 메뉴로 돌아갑니다. 플레이하던 게임을 저장하시겠습니까? (Y, N): ";
		cin >> m;
		cout << "\n ";
		switch (m) {
		//저장할 때
		case 'Y':
			//saveCount 값에 따른 저장 파일 선택
			switch (saveCount) {
			case 0:
				//맵 저장 여부, 비율, Map 배열, Status 배열 저장
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
				cout << "플레이하던 게임을 저장하고 메뉴로 돌아갑니다... ";
				saveCount++;
				break;
			case 1:
				//맵 저장 여부, 비율, Map 배열, Status 배열 저장
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
				cout << "플레이하던 게임을 저장하고 메뉴로 돌아갑니다... ";
				saveCount++;
				break;
			case 2:
				//맵 저장 여부, 비율, Map 배열, Status 배열 저장
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
				cout << "플레이하던 게임을 저장하고 메뉴로 돌아갑니다... ";
				saveCount++;
				break;
			//맵이 이미 3번 저장되어있을 때
			case 3:
				//저장할 수 없으므로 덮어씌울지 여부 확인
				cout << "맵이 이미 3번 저장되어 저장할 수 없습니다. 마지막으로 저장된 게임에 덮어씌우시겠습니까? (Y, N): ";
				cin >> m;
				cout << "\n ";
				switch (m) {
				//덮어씌울때
				case 'Y':
					//3번 파일에 저장 후 메뉴 화면으로 복귀
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
					cout << "플레이하던 게임을 저장하고 메뉴로 돌아갑니다... ";
					break;
				//덮어씌우지 않을 때
				case 'N':
					//메뉴 화면으로 복귀
					cout << "저장하지 않고 메뉴로 돌아갑니다... ";
					break;
				}
			}
			//메뉴 화면으로 복귀
			Sleep(2000);
			isEnd = false;
			isClear = false;
			deleteMap();
			start();
			break;

		//저장하지 않을 때
		case 'N':
			//메뉴 화면으로 복귀
			cout << "저장하지 않고 메뉴로 돌아갑니다... ";
			Sleep(2000);
			isEnd = false;
			isClear = false;
			deleteMap();
			start();
			break;
		}
	}
}

//맵 생성
void MineSweeper::makeMap()
{
	srand(time(NULL));

	//난이도에 따른 지뢰 갯수 저장
	int mines = int(row * col * ratio); 

	//지뢰는 9, 나머지는 0으로 저장
	Map = new int* [row];
	for (int i = 0; i < row; i++) {
		Map[i] = new int[col];
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			Map[i][j] = 0;
		}
	}

	//중복 방지
	for (int i = 0; i < mines; i++) {
		int r = rand() % row;
		int c = rand() % col;
		if (Map[r][c] == 9) {
			i--;
		}
		Map[r][c] = 9;
	}

	//오픈, 깃발, 미오픈 여부 저장
	Status = new int* [row];
	for (int i = 0; i < row; i++) {
		Status[i] = new int[col];
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			Status[i][j] = 0;
		}
	}

	//주변의 지뢰 갯수 계산해서 1씩 증가
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

//Map배열, Status배열 삭제
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

//맵 화면 출력
void MineSweeper::printMap()
{
	system("cls");

	cout << "\n";
	jyhan::printName();
	cout << "\n";

	//Status에 따라 다르게 출력
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			switch(Status[i][j]) {
			//오픈되지 않음
			case 0:
				cout << "■";
				break;
			//깃발
			case 1:
				cout << "▶";
				break;
			//오픈됨
			case 2:
				cout << " " << Map[i][j];
				break;
			}
		}
		cout << endl;
	}
	cout << "\n ←↑→↓:이동 / Enter: 열기 / Tab: 깃발";
}

//Enter키 입력 시 (오픈)
void MineSweeper::openMine(int mx, int my)
{
	//오픈되지 않았다면
	if (Status[mx][my] == 0) {
		Status[mx][my] = 2; //오픈함
		if (Map[mx][my] == 0) { //주변에 지뢰가 존재하지 않는 곳이라면
			for (int i = 0; i < row; i++) {
				for (int j = 0; j < col; j++) {
					//8방향 오픈함수 재귀 호출
					if ((i != mx || j != my) && (abs(i - mx) <= 1 && abs(j - my) <= 1)) {
						openMine(i, j);
					}
				}
			}
		}
		//지뢰를 오픈했을 때(게임 종료)
		if (Map[mx][my] == 9) {
			isEnd = true;
		}
	}

	//지뢰를 모두 체크하고 그 외의 곳은 모두 오픈했을 때(게임 클리어)
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

//Tab키 입력 시 (깃발)
void MineSweeper::checkMine(int mx, int my)
{
	//미오픈상태일 때 깃발로 변환
	if (Status[mx][my] == 0) {
		Status[mx][my] = 1;
	}
	//깃발일 때 미오픈상태로 변환
	else if (Status[mx][my] == 1) {
		Status[mx][my] = 0;
	}

	//지뢰를 모두 체크하고 그 외의 곳은 모두 오픈했을 때(게임 클리어)
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

//저장된 맵 불러오기
void MineSweeper::loadSavedMap(int i)
{
	ifstream fin;
	fin.open("save" + to_string(i + 1) + ".txt");
	int a; //쓰레기값

	//ratio 저장 (나중에 덮어쓸 때 사용)
	fin >> a >> ratio;
	//행, 열 값 저장
	fin >> row >> col;

	//저장된 맵 읽은 후 생성
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

//saveCount 초기화
void MineSweeper::loadSaveCount()
{
	ifstream fin;
	for (int i = 0; i < 3; i++) {
		fin.open("save" + to_string(i + 1) + ".txt");
		int isSaved;
		fin >> isSaved;

		//맵이 존재한다면
		if (isSaved == 1) {
			saveCount++; //값 증가
		}
		fin.close();
	}
}
