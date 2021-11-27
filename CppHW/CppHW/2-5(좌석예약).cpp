#include <iostream>
#include <string>
#include <ctime>

using namespace std;

namespace jyhan {
	void printName() {
		std::cout << "학번:202011390 이름:한재윤" << std::endl;
	}
}

int main() {

	jyhan::printName();
	cout << endl;

	constexpr int ROW = 6;
	constexpr int COL = 4;
	bool seats[ROW][COL]{};


	while (true) {
		
		system("cls");

		for (int i = 0; i < COL; i++)
			cout << '\t' << i + 1;
		cout << "\n\n";
		for (int i = 0; i < ROW; i++) {
			cout << static_cast<char>('A' + i) << '\t';

			for (int j = 0; j < COL; j++) {
				cout << (seats[i][j] ? "●" : "○") << '\t';
			}

			cout << "\n\n";
		}

		cout << "좌석 입력 (ex ==> A1, 종료는 EX를 누르세요) : ";
		char x, y;
		cin >> x >> y;
	
		if (x == 'E' and y == 'X') {
			cout << "좌석예약을 종료합니다.\n";
			break;
		}

		else {
			if (x < 'A' or x>'F' or y < '1' or y>'4') {
				cout << "없는 자리입니다. 다시 입력하세요.\n";
			}
			else {
				if (seats[x - 'A'][y - '1']) {
					cout << "이미 예약된 자리입니다.\n";
				}
				else {
					seats[x - 'A'][y - '1'] = true;
					cout << "예약이 완료되었습니다.\n";
				}
			}
			system("pause");
		}
	}
	return 0;
}