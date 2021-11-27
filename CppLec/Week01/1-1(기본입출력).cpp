//cout 예제1
/*
#include <iostream>
const double PI = 3.14;
double area(int r);
int main(){

	int r = 3;
	std::cout << "면적은 " << area(r) << "입니다.\n";
	std::cout << "면적은 " << area(r) << "입니다." << std::endl;

	return 0;
}

double area(int r) {
	return PI * r * r;
} */

//Namespace, Using 예제1
/*
#include <iostream>
using std::cout;
using std::endl;
namespace gdhongns {
	void showName() {
		cout << "홍길동" << endl;
	}
}
namespace gdgons {
	void showName() {
		cout << "고길동" << endl;
	}
}
using gdhongns::showName; //홍길동 NS지정 필요X
int main() {

	showName(); 
	gdgons::showName();

	return 0;
}*/

//Namespace, Using 예제2 (헤더파일 이용)
/*
#include "gdgo.h"
#include "gdhong.h"
using gdhongns::showName;
int main() {

	showName();
	gdgons::showName();

	return 0;
}*/

//cin 예제1 (정수, 문자)
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

//cin 예제2 (문자열)
/*
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;

int main() {

	string name;
	cout << "이름을 입력하세요 : ";
	cin >> name;
	cout << "당신의 이름은 " << name << "입니다.\n";

	return 0;
}*/

//cin 예제3 (문자열, 공백 포함 처리)
/*
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;

int main() {

	string name;
	cout << "이름을 입력하세요 : ";
	getline(cin, name);
	cout << "당신의 이름은 " << name << "입니다.\n";

	return 0;
} */