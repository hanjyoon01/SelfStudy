//cout ����1
/*
#include <iostream>
const double PI = 3.14;
double area(int r);
int main(){

	int r = 3;
	std::cout << "������ " << area(r) << "�Դϴ�.\n";
	std::cout << "������ " << area(r) << "�Դϴ�." << std::endl;

	return 0;
}

double area(int r) {
	return PI * r * r;
} */

//Namespace, Using ����1
/*
#include <iostream>
using std::cout;
using std::endl;
namespace gdhongns {
	void showName() {
		cout << "ȫ�浿" << endl;
	}
}
namespace gdgons {
	void showName() {
		cout << "��浿" << endl;
	}
}
using gdhongns::showName; //ȫ�浿 NS���� �ʿ�X
int main() {

	showName(); 
	gdgons::showName();

	return 0;
}*/

//Namespace, Using ����2 (������� �̿�)
/*
#include "gdgo.h"
#include "gdhong.h"
using gdhongns::showName;
int main() {

	showName();
	gdgons::showName();

	return 0;
}*/

//cin ����1 (����, ����)
/*
#include <iostream>
using std::cout;
using std::cin;

int main() {
	int val1, val2;

	//cin >> val1;
	//cin >> val2;

	cin >> val1 >> val2;

	char ch;
	cin >> ch;

	cout << val1 << "," << val2 << "," << ch << "\n";

	return 0;	
} */

//cin ����2 (���ڿ�)
/*
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;

int main() {

	string name;
	cout << "�̸��� �Է��ϼ��� : ";
	cin >> name;
	cout << "����� �̸��� " << name << "�Դϴ�.\n";

	return 0;
}*/

//cin ����3 (���ڿ�, ���� ���� ó��)
/*
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;

int main() {

	string name;
	cout << "�̸��� �Է��ϼ��� : ";
	getline(cin, name);
	cout << "����� �̸��� " << name << "�Դϴ�.\n";

	return 0;
} */