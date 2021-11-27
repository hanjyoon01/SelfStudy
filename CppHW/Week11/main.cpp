#include <iostream>
#include <string>
#include "CMyPoint.h"
#include "ArrayData.h"

using namespace std;

template<typename T>
void printArr(T* arr, size_t N) {
	for (int i = 0; i < N; i++) {
		cout << arr[i] << endl;
	}
	cout << endl;
}

template<>
void printArr(char* arr, size_t N) {
	cout << arr << endl;
}

template<typename T, size_t N>
void showArr(T(&arr)[N]) {
	for (auto i : arr) {
		cout << i << endl;
	}
	cout << endl;
}

template<typename T, size_t N>
void sortDesc(T(&arr)[N]) {
	for (size_t i = 0; i < N - 1; i++) {
		for (size_t j = i + 1; j < N; j++) {
			if (arr[i] < arr[j]) {
				T tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}

template<typename T, size_t N>
void sortAsc(T(&arr)[N]) {
	for (size_t i = 0; i < N - 1; i++) {
		for (size_t j = i + 1; j < N; j++) {
			if (arr[i] > arr[j]) {
				T tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}

namespace jyhan {
	void printName() {
		std::cout << "학번:202011390 이름:한재윤" << std::endl;
	}
}

int main() {

	jyhan::printName();
	cout << endl;

	ArrayData<CMyPoint> arr1;
	arr1.addElement(CMyPoint(10, 20));
	arr1.addElement(CMyPoint(20, 30));
	arr1.addElement(CMyPoint(30, 40));
	cout << arr1 << endl;

	ArrayData<CMyPoint> arr2 = arr1;
	cout << arr2 << endl;

	ArrayData<CMyPoint> arr3 = move(arr2);
	cout << arr3 << endl;
}