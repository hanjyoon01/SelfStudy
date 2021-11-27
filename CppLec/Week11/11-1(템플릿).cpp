#include <iostream>
#include <string>
#include "CMyPoint.h"
#include "Stack.h"

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
	for (auto i:arr) {
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

	//Stack<int> istack;
	//istack.push(10);
	//istack.push(20);
	//istack.push(30);
	//istack.push(40);
	//istack.push(50);

	//int item;
	//while (istack.pop(item)) {
	//	cout << item << endl;
	//}

	//Stack<double> dstack;
	//dstack.push(10.0);
	//dstack.push(20.0);
	//dstack.push(30.0);
	//dstack.push(40.0);
	//dstack.push(50.0);
	//double ditem;
	//while (dstack.pop(ditem)) {
	//	cout << ditem << endl;
	//}

	//Stack<string> sstack;
	//sstack.push("hanjyoon01");
	//sstack.push("hanjyoon02");
	//sstack.push("hanjyoon03");
	//string sitem;
	//while (sstack.pop(sitem)) {
	//	cout << sitem << endl;
	//}

	//Stack<CMyPoint> ptstack;
	//ptstack.push(CMyPoint(10, 20));
	//ptstack.push(CMyPoint(20, 40));
	//ptstack.push(CMyPoint(30, 60));
	//CMyPoint ptitem;
	//while (ptstack.pop(ptitem)) {
	//	cout << ptitem << endl;
	//}

	CMyPoint arr[]{ CMyPoint(20,30) ,CMyPoint(10,20) ,CMyPoint(40,50) };
	sortAsc(arr);
	showArr(arr); 

	//CMyPoint arr[]{ CMyPoint(10,20) ,CMyPoint(25,30) ,CMyPoint(15,10) };
	//sortDesc(arr);
	//showArr(arr); 

	//int arr1[]{ 1, 2, 3, 4, 5 };
	//double arr2[]{ 1.1,2.2,3.3,4.4,5.5,6.6 };
	//string arr3[]{ "hanjyoon01","hanjyoon02","hanjyoon03" };
	//sortDesc(arr1);
	//showArr(arr1);
	//sortDesc(arr2);
	//showArr(arr2);
	//sortDesc(arr3);
	//showArr(arr3);
	
	//char arr4[]{ 'a','b', 0 };
	//showArr(arr1);
	//showArr(arr2);
	/*printArr<int>(arr1, size(arr1));
	printArr(arr2, size(arr2));
	printArr(arr3, size(arr3));
	printArr(arr4, size(arr4));*/
}