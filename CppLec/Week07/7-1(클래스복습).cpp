#include "Concert.h"
#include <iostream>
using namespace std;
#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK, __FILE__, __LINE__)
#define new DBG_NEW
#endif // !DBG_NEW
#endif

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//생성자
	//cout << "==========" << endl;
	//Concert concert1("아이유 콘서트", 5);
	//concert1.reservation();
	//concert1.reservation();
	//concert1.show();
	//cout << "=====복사 생성자=====" << endl;
	//Concert concert2(concert1);
	//concert2.show();

	//cout << "=====이동 생성자=====" << endl;
	//Concert concert3(move(concert1));
	//concert3.show();

	//concert1.show();


	//더블 포인터
	//Concert** manager1 = new Concert * [5];
	//manager1[0] = new Concert("A", 3);
	//manager1[1] = new Concert("B", 2);
	//manager1[0]->reservation();
	//manager1[0]->show();
	//delete manager1[0];
	//delete manager1[1];
	//delete[] manager1;
	//manager1 = nullptr;

	//unique_ptr
	//unique_ptr<unique_ptr<Concert>[]> manager1 = make_unique < unique_ptr<Concert>[]>(5);

	//manager1[0] = make_unique<Concert>("A", 3);
	//manager1[1] = make_unique<Concert>("B", 3);
	//manager1[0]->reservation();
	//manager1[0]->show();

	//shared_ptr
	shared_ptr<shared_ptr<Concert>[]> manager1(new shared_ptr<Concert>[5]);

	manager1[0] = make_shared<Concert>("A", 3);
	manager1[1] = make_shared<Concert>("B", 3);
	manager1[0]->reservation();
	manager1[0]->show();
}