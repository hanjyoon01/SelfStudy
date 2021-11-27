#include <iostream>
#include "JyhanStudent.h"
#include "JyhanScholarship.h"
using namespace std;

namespace jyhan {
	void printName() {
		std::cout << "학번:202011390 이름:한재윤" << std::endl;
	}
}

int main() {

	jyhan::printName();
	cout << endl;

	JyhanStudent jyHan("한재윤", 4.5);
	cout << jyHan << endl;
	
	//메모리 누수 없음
	JyhanScholarship jyHanSch("건국장학금", 5);
	jyHanSch.apply("한재윤", 2.5);
	jyHanSch.apply("김재윤", 4.5);
	jyHanSch.apply("최재윤", 3.0);
	jyHanSch.apply("박재윤", 4.0);
	cout << jyHanSch << endl;

	//메모리 누수 없음
	JyhanScholarship jyHanSch2(jyHanSch);
	cout << jyHanSch2 << endl;

	//메모리 누수 발생
	JyhanScholarship jyHanSch3(move(jyHanSch2));
	cout << jyHanSch3 << endl;
}