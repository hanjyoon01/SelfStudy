#include <iostream>
#include "Student.h"

using namespace std;

namespace jyhan {
	void printName() {
		std::cout << "학번:202011390 이름:한재윤" << std::endl;
	}
}

template<typename T1, typename T2>
int search(T1* arr, int idx, T2 t) {

	for (int i = 0; i < idx; i++) {
		if (arr[i] == t)
			return i;
	}
	return -1;
}

int main() {

	cout << "\n";
	jyhan::printName();
	cout << "\n";	
	int arr[5] = { 5,4,3,2,1 };
	int idx1 = search(arr, 5, 3);
	if (idx1 != -1) {
		cout << arr[idx1] << endl;
	}

	string id[3] = { "hanjyoon1","hanjyoon2", "hanjyoon3" };
	int idx2 = search(id, 3, "hanjyoon2");
	if (idx2 != -1) {
		cout << id[idx2] << endl;
	}

	Student std[3]{
		Student("hanjyoon1",50),
		Student("hanjyoon2",60),
		Student("hanjyoon3",70),
	};
	int idx3 = search(std, 3, "hanjyoon2");
	if (idx3 != -1) {
		cout << std[idx3] << endl;
	}

	int idx4 = search(std, 3, Student("hanjyoon3",70));
	if (idx4 != -1) {
		cout << std[idx4] << endl;
	}
}