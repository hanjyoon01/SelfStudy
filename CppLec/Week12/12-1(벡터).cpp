#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "CMyPoint.h"

using namespace std; 

template<typename T>
void printArr(vector<T>& v) {
	for (auto it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";;
	}
	cout << endl;
}

int main() {
	//vector<int> intarr1;
	//for (int i = 0; i < 10; i++) {
	//	intarr1.push_back(i);
	//	cout << intarr1.size() << endl;
	//	cout << intarr1.capacity() << endl;
	//	cout << intarr1.data() << endl;
	//	cout << endl;
	//}

	//vector<int> arr1({ 1,2,3,4,5 });
	//vector<double> arr2;
	//arr2.push_back(10.5);
	//arr2.push_back(10.5);
	//arr2.push_back(10.5);
	//arr2.insert(arr2.begin(), 2.5);
	//printArr(arr1);
	//cout << "====================" << endl;
	//printArr(arr2);

	//CMyPoint arr[] = {
	//	CMyPoint(10,20),
	//	CMyPoint(10,20),
	//	CMyPoint(10,20)
	//};
	//vector<CMyPoint> arr3(&arr[0], &arr[2]);
	//printArr(arr3);

	//vector <CMyPoint> arr;
	//for (int i = 0; i < 5; i++) {
	//	//arr.push_back(CMyPoint(i * 10, i * 10));
	//	arr.emplace_back(i * 10, i * 10);
	//	cout << endl << endl;
	//}

	//vector<CMyPoint*> arr;
	//arr.push_back(new CMyPoint(10, 10));
	//arr.push_back(new CMyPoint(10, 10));
	//arr.push_back(new CMyPoint(10, 10));
	//for (auto it = arr.begin(); it != arr.end(); it++) {
	//	cout << **it << " ";
	//	delete* it;
	//} 

	vector<unique_ptr<CMyPoint>> arr;
	arr.push_back(make_unique<CMyPoint>(10, 10));
	arr.push_back(make_unique<CMyPoint>(10, 10));
	arr.push_back(make_unique<CMyPoint>(10, 10));
	arr.push_back(make_unique<CMyPoint>(10, 10));
	for (auto it = arr.begin(); it != arr.end(); it++) {
		cout << **it << " ";
		//delete* it;
	} 
}