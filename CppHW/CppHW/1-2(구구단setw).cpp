#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;
using std::setw;

namespace jyhan {
	void printName() {
		std::cout << "학번:202011390 이름:한재윤" << std::endl;
	}
}

int main() {

	jyhan::printName();
	cout << endl;

	for (size_t i = 1; i <= 9; i += 1) {
		for (size_t j = 2; j <= 9; j += 1) {
			cout << j << " * " << i << " = " << setw(2) << j * i << "\t";
		}
		cout << endl;
	}
}