#include <iostream>

using namespace std;

namespace jyhan {
	void printName() {
		std::cout << "�й�:202011390 �̸�:������" << std::endl;
	}
}

int main() {

	jyhan::printName();
	cout << endl;

	const int SIZE = 5;
	int grade[SIZE]{ 10,5,8,20,12 };

	
	for (int i = 0; i <	SIZE; i++) {
		cout << "��ȣ " << i << " :";
		for (int j = 0; j < grade[i]; j++) {
			cout << "*";
		}
		cout << endl;
	}
	cout << endl;

	return 0;
}