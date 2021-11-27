#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <list>
#include "CMyPoint.h"

using namespace std;

template<typename T>
void printArr(list<T>& v) {
	for (auto it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";;
	}
	cout << endl;
}

template<typename T>
void printArr(vector<T>& v) {
	for (auto it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";;
	}
	cout << endl;
}

int main() {
	list<int> list1({ 1,2,3,3,3,4,5 });
	list1.unique();
	printArr(list1);

	list<CMyPoint> list2;
	list2.push_back(CMyPoint(10, 10));
	list2.emplace_back(20, 20);
	list2.emplace_back(20, 20);
	list2.emplace_back(20, 20);
	list2.push_front(CMyPoint(30, 30));
	list2.unique();
	printArr(list2);

	list<CMyPoint> list3;
	list2.push_back(CMyPoint(40, 50));
	list2.push_back(CMyPoint(50, 50));
	list2.splice(list2.end(), list3);
	cout << list3.size() << endl;
	printArr(list2);



	list<string> std1({ "hanjyoon1","hanjyoon2", "hanjyoon3" });
	list<string> std2({ "kimjyoon1","kimjyoon2" });
	list<string> std3({ "parkjyoon1" });

	vector<list<string>> std;
	std.push_back(std1);
	std.push_back(std2);
	std.push_back(std3);

	vector<string> stdname;
	for (auto s : std) {
		for (auto t : s) {
			stdname.push_back(t);
		}
	}
	printArr(stdname);
}