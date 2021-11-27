#include <iostream>
#include "ArrayData.h"
#include <vector>
using namespace std;

void showArr(ArrayData& arr1) {
	cout << __FUNCTION__ << "(&)" << endl;
	arr1.showData();
}

void showArr(ArrayData&& arr1) {
	cout << __FUNCTION__ << "(&&)" << endl;
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

	//vector <ArrayData> vec;
	//for (size_t i = 0; i < 4; i++) {
	//	cout << "iteration " << i << endl;
	//	vec.push_back(ArrayData(5));
	//	cout << endl;
	//}


	ArrayData arr1 = getArr(10);
	arr1.addElement(5.5);
	arr1.addElement(2.5);
	
	arr1.showData();

}