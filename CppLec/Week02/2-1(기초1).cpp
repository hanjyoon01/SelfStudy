//���ڿ� ��ȯ
/*
#include <iostream>
#include <string>
using namespace std;
int main() {
	string name[5]{ "ȫ�浿","�̱浿","��浿","�ֱ浿","���浿" };

	for (size_t i = 0; i < 4; i++) {
		for (size_t j = i+1; j < 5; j++) {
			if (name[i].compare(name[j]) == 1) {
				string tmp = name[i];
				name[i] = name[j];
				name[j] = tmp;
			}
		}
	}

	for (string str : name) {
		cout << str << endl;
	}

	return 0;
}*/

//�迭 ����
/*
#include <iostream>
#include <string>
using namespace std;
int main() {
	const int SIZE = 5;
	const char tab = '\t';
	const char el = '\n';
	int grade[SIZE] { 10,20,30,40,50 };
	int Grade[SIZE]{};

	for (auto& i : Grade) {
		int j = 0;
		i = grade[j++];
	}

	int(&rgrade)[SIZE] = grade;

	for (auto i : rgrade) {
		cout << i << el;
	}
	
	cout << grade << tab << &grade[0] << el;
	cout << grade[0] << tab << grade[1] << el;
	cout << sizeof(grade) << tab << sizeof(grade[0]) << el;
	cout << size(grade) << el;

	return 0;
} */

//���� ����
/*
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

int main() {
	constexpr int SIZE = 10;
	int num[SIZE];
	srand((unsigned)time(NULL));

	cout << "=============" << endl;
	cout << "   �ε��� ��  " << endl;
	cout << "=============" << endl;


	for (int i = 0; i < SIZE; i++) {
		num[i] = rand() % 100;
		cout << i << '\t' << num[i] << endl;
	}
	return 0;
}*/