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
		std::cout << "ÇÐ¹ø:202011390 ÀÌ¸§:ÇÑÀçÀ±" << std::endl;
	}
}

int main() {

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	jyhan::printName();
	cout << endl;

	JyhanStudent jyHan("ÇÑÀçÀ±", 4.5);
	cout << jyHan << endl;
	
	//¸Þ¸ð¸® ´©¼ö ¾øÀ½
	JyhanScholarship jyHanSch("°Ç±¹ÀåÇÐ±Ý", 5);
	jyHanSch.apply(new JyhanStudent("ÇÑÀçÀ±", 2.5));
	jyHanSch.apply(new JyhanStudent("±èÀçÀ±", 2.5));
	jyHanSch.apply(new JyhanStudent("Á¶ÀçÀ±", 2.5));
	jyHanSch.apply(new JyhanStudent("¹ÚÀçÀ±", 2.5));
	cout << jyHanSch << endl;
}