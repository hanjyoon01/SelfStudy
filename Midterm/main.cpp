#include <iostream>
#include "JyhanStudent.h"
#include "JyhanScholarship.h"
using namespace std;

namespace jyhan {
	void printName() {
		std::cout << "�й�:202011390 �̸�:������" << std::endl;
	}
}

int main() {

	jyhan::printName();
	cout << endl;

	JyhanStudent jyHan("������", 4.5);
	cout << jyHan << endl;
	
	//�޸� ���� ����
	JyhanScholarship jyHanSch("�Ǳ����б�", 5);
	jyHanSch.apply("������", 2.5);
	jyHanSch.apply("������", 4.5);
	jyHanSch.apply("������", 3.0);
	jyHanSch.apply("������", 4.0);
	cout << jyHanSch << endl;

	//�޸� ���� ����
	JyhanScholarship jyHanSch2(jyHanSch);
	cout << jyHanSch2 << endl;

	//�޸� ���� �߻�
	JyhanScholarship jyHanSch3(move(jyHanSch2));
	cout << jyHanSch3 << endl;
}