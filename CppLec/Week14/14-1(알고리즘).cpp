#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Student.h"

using namespace std;

int random() {
	return rand() % 100;
}

bool checkKim(const Student& std) {
	if (std.getName().find("김") != string::npos) {
		return true;
	}
	else {
		return false;
	}
}

int main() {

	vector<Student> std;
	std.push_back(Student("2001", "홍길동", 80));
	std.push_back(Student("2004", "김길동", 70));
	std.push_back(Student("2003", "최길동", 90));
	std.push_back(Student("2002", "이길동", 100));
	std.push_back(Student("2005", "김길동", 60));
	std.push_back(Student("2007", "최길자", 95));
	std.push_back(Student("2006", "김길동", 75));

	//vector<Student>::iterator it = find(std.begin(), std.end(), Student("2003", "최길동", 90));
	//vector<Student>::iterator it = find(std.begin(), std.end(), "최길동");
	vector<Student>::iterator it = remove_if(std.begin(), std.end(), [](const Student& s) {return s.getScore() >= 90; });
	std.erase(it, std.end());
	for_each(std.begin(), std.end(), [](const Student& i) {cout << i << endl; });
	
	//vector<Student>::iterator it = std.begin();
	//while (true) {
	//	it = find_if(it, std.end(), [](const Student& s) {return s.getScore() >= 90; });
	//	if (it != std.end()) {
	//		cout << distance(std.begin(), it) << "번째 존재함 : " << *it << endl;
	//		it++;
	//	}
	//	else {
	//		break;
	//	}
	//}

	//sort(std.begin(), std.end(), greater<Student>());
	//sort(std.begin(), std.end(), [](const Student& left, const Student& right) {
	//	return left.getId() < right.getId();
	//	});
	//for_each(std.begin(), std.end(), [](const Student& i) {cout << i << endl; });

	//vector<int> vec(10);
	////generate(vec.begin(), vec.end(), random);
	//generate(vec.begin(), vec.end(), [] {return rand() % 100; });
	////sort(vec.begin(), vec.end(), greater<int>());
	//
	//vector<int> vec2(5);
	//generate(vec2.begin(), vec2.end(), [] {return rand() % 50; });
	//
	//cout << vec.size() << "," << vec2.size() << endl;
	//cout << vec.data() << "," << vec2.data() << endl;
	//vec.swap(vec2);
	//cout << vec.size() << "," << vec2.size() << endl;
	//cout << vec.data() << "," << vec2.data() << endl;

	//for_each(vec.begin(), vec.end(), [](const int i) {cout << i << endl; });
}