#include <iostream>
#include "MovieManager.h"
using namespace std;

#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK, __FILE__, __LINE__)
#define new DBG_NEW
#endif // !DBG_NEW
#endif

namespace jyhan {
	void printName() {
		std::cout << "  �й�:202011390 �̸�:������" << std::endl;
	}
}

int main() {

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	cout << "\n";
	jyhan::printName();
	cout << "\n";

	//����2
	MovieManager hanjyoon("movieinfo.txt");
	hanjyoon.startMenu();

	//Movie ������ �Ҹ���
	//Movie m1("1917", 10, 10);
	//cout << "======================" << endl;
	//Movie m2(m1);
	//cout << m2.getName() << "(" << m2.getRow() << ", " << m2.getCol() << ")" << endl;
	//cout << "======================" << endl;
	//Movie m3(move(m1));
	//cout << m3.getName() << "(" << m3.getRow() << ", " << m3.getCol() << ")" << endl;
	//cout << "======================" << endl;

	//MovieManager ������ �Ҹ���
	//MovieManager hanjyoon("movieinfo.txt");
	//cout << "======================" << endl;
	//MovieManager hanjyoon1(hanjyoon);
	//cout << "======================" << endl;
	//MovieManager hanjyoon2(move(hanjyoon));
	//cout << "======================" << endl;
}