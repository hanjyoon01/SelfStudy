#include <iostream>
#include "ArrayData.h"
using namespace std;

void showArr(ArrayData arr1) {
	arr1.showData();
}

ArrayData getArr(const int& num) {
	ArrayData arr(num);
	return arr;
	//return ArrayData(num);
}

namespace jyhan {
	void printName() {
		std::cout << "학번:202011390 이름:한재윤" << std::endl;
	}
}

int main() {

	jyhan::printName();
	cout << endl;

	//ArrayData data1;
	//data1.addElement(5.5);
	//data1.addElement(5.5);
	//data1.addElement(5.5);
	//data1.showData();
	//cout << "==============" << endl;
	//ArrayData copy1(data1);
	////copy1.showData();
	//showArr(copy1);
	//cout << "==============" << endl;
	//ArrayData copy2 = getArr(10);

	ArrayData arr1(10);
	arr1.addElement(5.5);
	arr1.addElement(2.5);

	ArrayData arr2(arr1);
	arr2.addElement(3.5);

	arr1.showData();
	arr2.showData();
}