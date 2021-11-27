#include <iostream>
#include "JyhanStudent.h"
#include "JyhanScholarship.h"
using namespace std;

#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK, __FILE__, __LINE__)
#define new DBG_NEW
#endif // !DBG_NEW
#endif

namespace jyhan {
	void printName() {
		std::cout << "�й�:202011390 �̸�:������" << std::endl;
	}
}

int main() {

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	jyhan::printName();
	cout << endl;

	JyhanStudent jyHan("������", 4.5);
	cout << jyHan << endl;
	
	//�޸� ���� ����
	JyhanScholarship jyHanSch("�Ǳ����б�", 5);
	jyHanSch.apply(new JyhanStudent("������", 2.5));
	jyHanSch.apply(new JyhanStudent("������", 2.5));
	jyHanSch.apply(new JyhanStudent("������", 2.5));
	jyHanSch.apply(new JyhanStudent("������", 2.5));
	cout << jyHanSch << endl;
}