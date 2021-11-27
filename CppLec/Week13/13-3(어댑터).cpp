#include <iostream>
#include <map>
#include <list>
#include <functional>
#include "Student.h"

using namespace std;
using namespace std::placeholders;

int add(int a, int b) {
	return a + b;
}

int sub(int a, int b) {
	return a - b;
}

int calculate(int a, int b, int (*func)(int, int)) {
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

bool removescore(int a) {
	return a < 40;
}

int main() {


	list<Student> stdlist;
	stdlist.push_back(Student("greenjoa1", "홍길동", 80));
	stdlist.push_back(Student("greenjoa2", "김길동", 90));
	stdlist.push_back(Student("greenjoa3", "엄길동", 60));
	stdlist.push_back(Student("greenjoa4", "최길동", 50));
	//stdlist.sort(greater<>());

	//stdlist.remove_if(bind(equal_to<>(), _1, Student("greenjoa3", "엄길동", 60)));
	stdlist.remove_if([](auto i) { return i == Student("greenjoa3", "엄길동", 60); });
	for (auto it = stdlist.begin(); it != stdlist.end(); it++) {
		cout << *it << endl;
	}

	//list<int> mylist = { 50,60,10,30,40,90 };
	////mylist.sort(greater<>());
	////mylist.remove_if(removescore);
	////mylist.remove_if(bind(less<>(), _1, 40));
	//mylist.remove_if([](auto i) {return i < 40; });
	//for (auto it = mylist.begin(); it != mylist.end(); it++) {
	//	cout << *it << endl;
	//}
}