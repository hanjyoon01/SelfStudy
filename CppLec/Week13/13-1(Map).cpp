#include <iostream>
#include <map>
#include "Student.h"

using namespace std;

int main() {

	map<string, Student> cppclassA;
	cppclassA["hanjyoon1"] = Student("hanjyoon1", "������", 60);
	cppclassA.insert({ "hanjyoon2",Student("hanjyoon2","������",70) });
	cppclassA.emplace("hanjyoon4", Student("hanjyoon4", "������", 90));
	cppclassA.insert({ "hanjyoon3",Student("hanjyoon3","������",80) });

	cout << "------------cppclassA------------" << endl;
	for (const auto& p : cppclassA) {
		cout << p.first << " : " << p.second << endl;
	}

	auto pos = cppclassA.find("hanjyoon3");
	if (pos != cppclassA.end()) {
		//cout << *pos << endl;
		cout << pos->first << " : " << pos->second << endl;
	}

	map<string, Student> cppclassB;
	cppclassB.insert({ "hanjyoon5",Student("hanjyoon5","������",75) });
	cppclassB.insert({ "hanjyoon6",Student("hanjyoon6","������",65) });
	cppclassB.emplace("hanjyoon3", Student("hanjyoon3", "������", 80));

	cout << "------------cppclassB------------" << endl;
	for (const auto& p : cppclassB) {
		cout << p.first << " : " << p.second << endl;
	}

	cppclassA.merge(cppclassB);
	cout << "------------cppclassA------------" << endl;
	for (const auto& p : cppclassA) {
		cout << p.first << " : " << p.second << endl;
	}

	cout << "------------cppclassB------------" << endl;
	for (const auto& p : cppclassB) {
		cout << p.first << " : " << p.second << endl;
	}

	auto node = cppclassA.extract("hanjyoon1");
	cout << node.key() << ", " << node.mapped() << endl;
	cppclassB.insert(move(node));

	cout << "------------cppclassA------------" << endl;
	for (const auto& p : cppclassA) {
		cout << p.first << " : " << p.second << endl;
	}

	cout << "------------cppclassB------------" << endl;
	for (const auto& [key, value] : cppclassB) {
		cout << key << " : " << value << endl;
	}
}