#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <ctime>

using namespace std;

namespace jyhan {
	void printName() {
		std::cout << "  학번:202011390 이름:한재윤" << std::endl;
	}
}

//영화 구조체
struct movie {
	string name; // 제목
	int ROW; // 행
	int COL; // 열
	int FS; // 전체 좌석 수
	int LS; // 잔여좌석 수
	int* (*NUM); // 예약번호
};


// 1)영화 예매
void ticketing(movie* (&m), int c) {


	system("cls");

	cout << "\n";
	jyhan::printName();
	cout << "\n";

	int s; //영화 선택 매개변수
	cout << "========================영화 예매========================\n\n";

	//영화 목록 출력
	for (int i = 0; i < c; i++) {
		cout << "\t" << i + 1 << ")" << left << setw(20) << m[i].name << "\t\t" << m[i].LS << "/" << m[i].FS << (m[i].LS == 0 ? "(매진)" : "") << endl;
	}

	//영화 선택
	cout << "\n     예매할 영화를 선택하세요(번호): ";
	cin >> s;

	int ROW = m[s - 1].ROW; // 행
	int COL = m[s - 1].COL; // 열

	system("cls");

	cout << "\n";
	jyhan::printName();
	cout << "\n";
	cout << "========================영화 예매========================\n\n";

	//좌석 출력
	for (int i = 0; i < COL; i++)
		cout << "  " << '\t' << i + 1;
	cout << "\n\n";

	for (int i = 0; i < ROW; i++) {
		cout << "  " << static_cast<char>('A' + i) << '\t';
		for (int j = 0; j < COL; j++) {
			cout << (m[s - 1].NUM[i][j] == 0 ? "○" : "●") << '\t';
		}
		cout << "\n\n";
	}

	//예매 좌석 입력
	cout << "  좌석 입력 (ex ==> A1) : ";
	char x;
	int y;
	cin >> x >> y;

	//좌석 조건
	if (x < 'A' or x >= 'A' + ROW or y < 1 or y > COL) {
		cout << "\n 없는 자리입니다. 다시 입력하세요.\n\n ";
	}
	else {
		int c = 0;
		if (m[s - 1].NUM[x - 'A'][y - 1] != 0) {
			cout << "\n 이미 예매된 자리입니다. (예매번호: " << m[s - 1].NUM[x - 'A'][y - 1] << ")\n\n ";
		}

		//예매 번호 중복 방지
		else {
			while (true) {
				m[s - 1].NUM[x - 'A'][y - 1] = rand() % 999 + 1;
				for (int i = 1; i < c; i++) {
					for (int j = 0; j < ROW; j++) {
						for (int k = 0; k < COL; k++) {
							if (m[s - 1].NUM[x - 'A'][y - 1] == m[i].NUM[j][k])
								c++;
						}
					}
				}
				//예매 완료시 잔여 좌석 감소
				if (c == 0) {
					cout << "\n 예매가 완료되었습니다. (예매번호: " << m[s - 1].NUM[x - 'A'][y - 1] << ")\n\n ";
					m[s - 1].LS--;
					break;
				}
			}
		}
	}
	system("pause");
	system("cls");
}

// 2)예매 취소
void ticketcancel(movie* (&m), int c) {

	system("cls");

	int cancelnum; //취소할 번호

	cout << "\n";
	jyhan::printName();
	cout << "\n";
	cout << "====================예매 취소====================\n\n";
	cout << " 예매 번호를 입력해주세요: ";
	cin >> cancelnum;

	int count = 0; //예매 번호 존재 여부 확인

	//예매 번호 비교 후 취소
	for (int i = 0; i < c; i++) {
		for (int j = 0; j < m[i].ROW; j++) {
			for (int k = 0; k < m[i].COL; k++) {
				if (cancelnum == m[i].NUM[j][k]) {
					cout << "\n 예매 취소가 완료되었습니다.";
					cout << "(" << m[i].name << ", " << char('A' + j) << k + 1 << ")\n\n ";
					m[i].LS++; //잔여좌석 추가
					m[i].NUM[j][k] = 0; //예매 번호 초기화
					count++;
					system("pause");
					system("cls");
				}
			}
		}
	}

	//예매 번호 미존재시
	if (count == 0) {
		cout << "\n 예매 번호가 존재하지 않습니다.\n\n ";
		system("pause");
		system("cls");
	}
}

// 3)예매 확인
void ticketcheck(movie* (&m), int c) {

	system("cls");
	int checknum; //확인할 번호
	int count = 0; //예매 번호 존재 여부 확인
	cout << "\n";
	jyhan::printName();
	cout << "\n";
	cout << "====================예매 확인====================\n\n";
	cout << " 예매 번호를 입력해주세요: ";
	cin >> checknum;

	//예매 번호 비교 후 정보 출력
	for (int i = 0; i < c; i++) {
		for (int j = 0; j < m[i].ROW; j++) {
			for (int k = 0; k < m[i].COL; k++) {
				if (checknum == m[i].NUM[j][k]) {

					//예매 정보 출력
					cout << "\n 예매하신 영화: " << m[i].name << endl;
					cout << "\n 예매하신 좌석: " << char('A' + j) << k + 1 << "\n\n";
					cout << "====================예매 좌석====================\n\n";

					//예매 좌석 출력
					for (int l = 0; l < m[i].COL; l++)
						cout << "  " << '\t' << l + 1;
					cout << "\n\n ";

					for (int y = 0; y < m[i].ROW; y++) {
						cout << "  " << static_cast<char>('A' + y) << '\t';
						for (int z = 0; z < m[i].COL; z++) {
							cout << (checknum == m[i].NUM[y][z] ? "☆" : "○") << '\t';
						}
						cout << "\n\n ";
						count++;
					}
					system("pause");
					system("cls");
				}
			}
		}
	}

	//예매 번호 미존재시
	if (count == 0) {
		cout << "\n 예매 번호가 존재하지 않습니다.\n\n ";
		system("pause");
		system("cls");
	}
}

int main() {

	int count; //영화 개수
	int menu; //메뉴 선택

	string name;
	string end;
	ifstream fin("movieinfo.txt");
	srand((unsigned)time(NULL));

	if (!fin.is_open()) {
		cerr << "파일 오픈 실패" << endl;
		exit(0);
	}

	//영화 개수 저장
	fin >> count;
	getline(fin, end);

	//구조체 배열 동적할당
	movie* moviethr = new movie[count];

	//파일로부터 영화 제목, 좌석수 저장
	for (int i = 0; i < count; i++) {
		getline(fin, moviethr[i].name); //영화 제목 저장
		fin >> moviethr[i].ROW >> moviethr[i].COL; //행, 열 저장
		getline(fin, end);
	}

	//좌석 수 초기화
	for (int i = 0; i < count; i++) {
		moviethr[i].FS = moviethr[i].LS = moviethr[i].ROW * moviethr[i].COL;
	}

	//예매번호 동적할당
	for (int i = 0; i < count; i++) {
		moviethr[i].NUM = new int* [moviethr[i].ROW];
	}
	for (int i = 0; i < count; i++) {
		for (int j = 0; j < moviethr[i].ROW; j++) {
			moviethr[i].NUM[j] = new int[moviethr[i].COL];
		}
	}

	//예매번호 0으로 초기화
	for (int i = 0; i < count; i++) {
		for (int j = 0; j < moviethr[i].ROW; j++) {
			for (int k = 0; k < moviethr[i].COL; k++) {
				moviethr[i].NUM[j][k] = 0;
			}
		}
	}

	while (true) {

		cout << "\n";
		jyhan::printName();
		cout << "\n";
		int menu;
		cout << "===========================GGV===========================\n" << endl;
		cout << "  1) 영화 예매  2) 예매 취소  3) 예매 확인  4) 종료\n" << endl;
		cout << "  메뉴를 선택하세요: ";
		cin >> menu;

		//1번 메뉴
		if (menu == 1) {
			ticketing(moviethr, count);
		}
		//2번 메뉴
		else if (menu == 2) {
			ticketcancel(moviethr, count);
		}
		//3번 메뉴
		else if (menu == 3) {
			ticketcheck(moviethr, count);
		}
		//종료 시 메모리 누수 체크, 메모리 삭제 후 종료
		else if (menu == 4) {

			_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

			cout << "\n  영화 예매를 종료합니다.\n\n  ";

			//동적할당한 NUM배열 삭제
			for (int i = 0; i < count; i++) {
				for (int j = 0; j < moviethr[i].ROW; j++) {
					delete[] moviethr[i].NUM[j];
				}
				delete[] moviethr[i].NUM;
				moviethr[i].NUM = nullptr;
			}

			//구조체 moviethr배열 삭제
			delete[] moviethr;
			moviethr = nullptr;
			return 0;
		}
	}
}