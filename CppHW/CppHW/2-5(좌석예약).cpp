#include <iostream>
#include <string>
#include <ctime>

using namespace std;

namespace jyhan {
	void printName() {
		std::cout << "�й�:202011390 �̸�:������" << std::endl;
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
				cout << (seats[i][j] ? "��" : "��") << '\t';
			}

			cout << "\n\n";
		}

		cout << "�¼� �Է� (ex ==> A1, ����� EX�� ��������) : ";
		char x, y;
		cin >> x >> y;
	
		if (x == 'E' and y == 'X') {
			cout << "�¼������� �����մϴ�.\n";
			break;
		}

		else {
			if (x < 'A' or x>'F' or y < '1' or y>'4') {
				cout << "���� �ڸ��Դϴ�. �ٽ� �Է��ϼ���.\n";
			}
			else {
				if (seats[x - 'A'][y - '1']) {
					cout << "�̹� ����� �ڸ��Դϴ�.\n";
				}
				else {
					seats[x - 'A'][y - '1'] = true;
					cout << "������ �Ϸ�Ǿ����ϴ�.\n";
				}
			}
			system("pause");
		}
	}
	return 0;
}