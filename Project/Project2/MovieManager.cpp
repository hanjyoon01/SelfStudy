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
		std::cout << "  학번:202011390 이름:한재윤" << std::endl;
	}
}

MovieManager::MovieManager(const string& txt)
	:txt(txt)
{
	//cout << "MovieManager 생성자" << endl; //생성자 테스트용

	srand((unsigned)time(NULL));

	ifstream fin(this->txt);
	string end;

	if (!fin.is_open()) {
		cerr << "파일 오픈 실패" << endl;
		exit(0);
	}

	//영화 개수 저장
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
	cout << "MovieManager 복사 생성자" << endl;
	count = MM.count;
	txt = MM.txt;
	movie = new Movie *[MM.count];
	for (int i = 0; i < count; i++) {
		movie[i] = new Movie(*MM.movie[i]);
	}
}

MovieManager::MovieManager(MovieManager&& MM) noexcept: count(MM.count), txt(MM.txt), movie(MM.movie)
{
	cout << "MovieManager 이동 생성자" << endl;
	MM.count = 0;
	MM.txt = "";
	MM.movie = nullptr;
}

MovieManager::~MovieManager()
{
	//cout << "MovieManager 소멸자" << endl; //소멸자 테스트용
	//movie 메모리 해제
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

	int s; //영화 선택 매개변수a
	cout << "========================영화 예매========================\n\n";

	//영화 목록 출력
	for (int i = 0; i < count; i++) {
		cout << "\t" << i + 1 << ")" << left << setw(20) << (*movie[i]).getName() << "\t\t"
			<< (*movie[i]).getLS() << "/" << (*movie[i]).getFS() << ((*movie[i]).getLS() == 0 ? "(매진)" : "") << endl;
	}

	//영화 선택
	cout << "\n     예매할 영화를 선택하세요(번호): ";
	cin >> s;

	system("cls");

	cout << "\n";
	jyhan2::printName();
	cout << "\n";
	cout << "========================영화 예매========================\n\n";

	//좌석 출력
	(*movie[s-1]).printSeat();

	//예매 좌석 입력
	cout << "  좌석 입력 (ex ==> A1) : ";
	char x;
	int y;
	cin >> x >> y;

	//좌석 조건
	if (x < 'A' or x >= 'A' + (*movie[s - 1]).getRow() or y < 1 or y > (*movie[s - 1]).getCol()) {
		cout << "\n 없는 자리입니다. 다시 입력하세요.\n\n ";
	}
	else {
		int c = 0;
		if ((*movie[s - 1]).getSeat(x - 'A', y - 1) != 0) {
			cout << "\n 이미 예매된 자리입니다. (예매번호: " << (*movie[s - 1]).getSeat(x - 'A', y - 1) << ")\n\n ";
		}

		//예매 번호 중복 방지
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
				//예매 완료시 잔여 좌석 감소
				if (c == 0) {
					cout << "\n 예매가 완료되었습니다. (예매번호: " << (*movie[s - 1]).getSeat(x - 'A', y - 1) << ")\n\n ";
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

	int cancelnum; //취소할 번호

	cout << "\n";
	jyhan2::printName();
	cout << "\n";
	cout << "====================예매 취소====================\n\n";
	cout << " 예매 번호를 입력해주세요: ";
	cin >> cancelnum;

	int c = 0; //예매 번호 존재 여부 확인

	//예매 번호 비교 후 취소
	for (int i = 0; i < count; i++) {
		for (int j = 0; j < (*movie[i]).getRow(); j++) {
			for (int k = 0; k < (*movie[i]).getCol(); k++) {
				if (cancelnum == (*movie[i]).getSeat(j,k)) {
					cout << "\n 예매 취소가 완료되었습니다.";
					cout << "(" << (*movie[i]).getName() << ", " << char('A' + j) << k + 1 << ")\n\n ";
					(*movie[i]).incrLS(); //잔여좌석 추가
					(*movie[i]).setSeat(j, k, 0); //예매 번호 초기화
					c++;
					system("pause");
					system("cls");
				}
			}
		}
	}

	//예매 번호 미존재시
	if (c == 0) {
		cout << "\n 예매 번호가 존재하지 않습니다.\n\n ";
		system("pause");
		system("cls");
	}
}

void MovieManager::ticketCheck()
{
	system("cls");
	int checknum; //확인할 번호
	int c = 0; //예매 번호 존재 여부 확인
	cout << "\n";
	jyhan2::printName();
	cout << "\n";
	cout << "====================예매 확인====================\n\n";
	cout << " 예매 번호를 입력해주세요: ";
	cin >> checknum;

	//예매 번호 비교 후 정보 출력
	for (int i = 0; i < count; i++) {
		for (int j = 0; j < (*movie[i]).getRow(); j++) {
			for (int k = 0; k < (*movie[i]).getCol(); k++) {
				if (checknum == (*movie[i]).getSeat(j, k)) {

					//예매 정보 출력
					cout << "\n 예매하신 영화: " << (*movie[i]).getName() << endl;
					cout << "\n 예매하신 좌석: " << char('A' + j) << k + 1 << "\n\n";
					cout << "====================예매 좌석====================\n\n";

					//예매 좌석 출력
					for (int l = 0; l < (*movie[i]).getCol(); l++)
						cout << "  " << '\t' << l + 1;
					cout << "\n\n ";

					for (int y = 0; y < (*movie[i]).getRow(); y++) {
						cout << "  " << static_cast<char>('A' + y) << '\t';
						for (int z = 0; z < (*movie[i]).getCol(); z++) {
							cout << (checknum == (*movie[i]).getSeat(y, z) ? "☆" : "○") << '\t';
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

	//예매 번호 미존재시
	if (c == 0) {
		cout << "\n 예매 번호가 존재하지 않습니다.\n\n ";
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
		cout << "  1) 영화 예매  2) 예매 취소  3) 예매 확인  4) 종료\n" << endl;
		cout << "  메뉴를 선택하세요: ";
		cin >> menu;

		//1번 메뉴
		if (menu == 1) {
			this->ticketing();
		}
		//2번 메뉴
		else if (menu == 2) {
			this->ticketCancel();
		}
		//3번 메뉴
		else if (menu == 3) {
			this->ticketCheck();
		}
		//종료
		else if (menu == 4) {
			cout << "\n  영화 예매를 종료합니다.\n\n";
			break;
		}
	}
}
