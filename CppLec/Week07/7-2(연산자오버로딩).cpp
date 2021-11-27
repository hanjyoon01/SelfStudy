#include <iostream>
#include "ArrayData.h"
using namespace std;

void showArr(const ArrayData& arr) {
	for (size_t i = 0; i < arr.getUsed(); i++) {
		cout << arr[i] << endl;
	}
}

int main() {

	ArrayData arr1(5);
	arr1.addElement(10.5);
	arr1.addElement(10.5);
	showArr(arr1);

	cout << "==============" << endl;
	ArrayData arr2;
	arr2 = arr1;
	for (int i = 0; i < arr2.getUsed(); i++) {
		cout << arr2[i] << endl;
	}
	cout << "==============" << endl;
	ArrayData arr3;
	arr3 = move(arr2);
	for (int i = arr3.getUsed(); i < arr3.getCapacity(); i++) {
		arr3[i] = 10.0;
		arr3.setUsed();
	}
	cout << arr3 << endl;
}