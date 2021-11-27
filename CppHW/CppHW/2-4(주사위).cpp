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

	constexpr int SIZE = 6;
	int num[SIZE]{};
	srand((unsigned)time(NULL));

	for (int i = 0; i < 10000; i++) {
		num[rand() % 6]++;
	}

	for (int i = 0; i < SIZE; i++) {
		cout << i + 1 << " : " << num[i] << "��" << endl;
	}
	cout << endl;

	return 0;
}