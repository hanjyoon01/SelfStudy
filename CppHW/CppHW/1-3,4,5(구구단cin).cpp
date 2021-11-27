#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::setw;

namespace jyhan {
	void printName() {
		std::cout << "�й�:202011390 �̸�:������" << std::endl;
	}
}

int main() {

	jyhan::printName();
	int start, end;
	cout << endl;
	cout << "�������� ����� ���ϴ� ������ �Է��ϼ���(����, ��) : ";
	cin >> start >> end;
	cout << endl;

	if (start > end) {
		cout << "�� ��° �Է� ���ڰ� �� ũ�Ƿ�, ���۰� ���� ���� �ٲ㼭 ����ұ��?(y/n) ";
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