#include <iostream>
#include <map>
#include <list>
#include "Student.h"

using namespace std;
int add(int a, int b) {
	return a + b;
}

int sub(int a, int b) {
	return a - b;
}

int calculate(int a, int b, int (*func)(int,int)) {
	return func(a, b);
}

template<typename T>
auto calculate(int a, int b, T func) {
	return func(a, b);
}

//auto calculate(int a, int b, minus<int> func) {
//	return func(a, b);
//}

bool sortdesc(int a, int b) {
	return a > b;
}

int main() {

	list<Student> stdlist;
	stdlist.push_back(Student("greenjoa1", "홍길동", 80));
	stdlist.push_back(Student("greenjoa2", "김길동", 90));
	stdlist.push_back(Student("greenjoa3", "엄길동", 60));
	stdlist.push_back(Student("greenjoa4", "최길동", 50));
	stdlist.sort(greater<>());

	for (auto it = stdlist.begin(); it != stdlist.end(); it++) {
		cout << *it << endl;
	}

	//list<int> mylist = { 50,60,10,30,40,90 };
	////mylist.sort(sortdesc);
	//mylist.sort(greater<>());
	//for (auto it = mylist.begin(); it != mylist.end(); it++) {
	//	cout << *it << endl;
	//}

	//plus<int> p1;
	//minus<int> m1;
	//cout << calculate(10, 20, p1) << endl;
	//cout << calculate(10, 20, m1) << endl;

}