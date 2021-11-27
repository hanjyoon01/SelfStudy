#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::setw;

namespace jyhan {
	void printName() {
		std::cout << "학번:202011390 이름:한재윤" << std::endl;
	}
}

int main() {

	jyhan::printName();
	int start, end;
	cout << endl;
	cout << "구구단의 출력을 원하는 범위를 입력하세요(시작, 끝) : ";
	cin >> start >> end;
	cout << endl;

	if (start > end) {
		cout << "두 번째 입력 숫자가 더 크므로, 시작과 끝의 값을 바꿔서 출력할까요?(y/n) ";
		char ans;
		cin >> ans;
		if (ans == 'y') {
			int tmp;
			tmp = start;
			start = end;
			end = tmp;

			cout << endl;
			for (size_t i = 1; i <= 9; i += 1) {
				for (size_t j = start; j <= end; j += 1) {
					cout << j << " * " << i << " = " << setw(2) << j * i << "\t";
				}
				cout << endl;
			}
			
			return 0;
		}
		else if (ans == 'n') {
			return 0;
		}
	}

	else {
		for (size_t i = 1; i <= 9; i += 1) {
			for (size_t j = start; j <= end; j += 1) {
				cout << j << " * " << i << " = " << setw(2) << j * i << "\t";
			}
			cout << endl;
		}
	}
	return 0;
}