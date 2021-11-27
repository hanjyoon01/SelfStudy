#include <iostream>
#include <string>
#include <list>

using namespace std;

template<typename T>
void printArr(list<T>& v) {
	for (auto it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";;
	}
	cout << endl;
}

list<string> getStudent(list<list<string>>& arr1, list<string>& arr2) {

	list<string> stdname;

	for (auto s : arr1) {
		for (auto t : s) {
			stdname.push_back(t);
		}
	}

	stdname.sort();
	stdname.unique();

	for (auto t : arr2) {
		stdname.remove(t);
	}

	return stdname;
}

namespace jyhan {
	void printName() {
		std::cout << "학번:202011390 이름:한재윤" << std::endl;
	}
}

int main() {

	jyhan::printName();
	cout << endl;

	list<list<string>> std;
	std.push_back({ "greenjoa1", "bluejoa1", "greenjoa3" });
	std.push_back({ "greenjoa1", "greenjoa3" });
	std.push_back({ "redjoa1", "greenjoa2", "bluejoa2" });
	list<string> droplist({ "greenjoa2", "bluejoa1" });

	auto student = getStudent(std, droplist);
	printArr(student);
	cout << endl;
}