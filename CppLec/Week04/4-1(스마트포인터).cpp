//unique_ptr 예제
/*
#include <iostream>
#include <string>
using namespace std;

#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK, __FILE__, __LINE__)
#define new DBG_NEW
#endif // !DBG_NEW
#endif

void delete_int(int* ptr) {
	cout << "포인터 삭제" << endl;
	delete ptr;
}

void delete_arr(int* ptr) {
	cout << "배열 삭제" << endl;
	delete[] ptr;
}

void func() {
	string* str = new string("HELLO");
	str->append(" WORLD");
	cout << *str << endl;
}

void func2() {
	auto str = make_unique<string>("HELLO");
	str->append(" WORLD");
	cout << *str << endl;
}

void func3(string* str) {
	cout << *str << endl;
}


int main() {

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//int*pnum1 = new int;
	unique_ptr<int, decltype(&delete_int)> pnum1(new int, &delete_int);
	//auto pnum1 = make_unique<int>();
	//unique_ptr<int> pnum1 = make_unique<int>();
	*pnum1 = 100;
	cout << *pnum1 << endl;

	//unique_ptr<int> pnum1_copy = pnum1;
	//unique_ptr<int> pnum1_copy = move(pnum1);
	//if (pnum1 == nullptr) {
	//	cout << "null ptr" << endl;
	//}
	//else {
	//	cout << *pnum1 << endl;
	//}

	//int* pnum2 = new int[5];
	unique_ptr<int[], decltype(&delete_arr)> pnum2(new int[5], &delete_arr);
	//auto pnum2 = make_unique<int[]>(5);
	//unique_ptr<int[]> pnum2 = make_unique<int[]>(5);
	pnum2[0] = 100;
	cout << pnum2[0] << endl;

	//int** pnum3 = new int*[5];
	//unique_ptr<unique_ptr<int[]>[]> pnum3 = make_unique<unique_ptr<int[]>[]>(5);
	auto pnum3 = make_unique<unique_ptr<int[]>[]>(5);

	for (int i = 0; i < 5; i++) {
		pnum3[i] = make_unique<int[]>(3);
	}
	pnum3[0][0] = 100;
	cout << pnum3[0][0] << endl;

	//string* pstr = new string("Hello");
	auto pstr = make_unique<string>("HELLO");
	cout << *pstr << endl;
	func3(pstr.get());

	pstr.reset(); //nullptr
	pstr.reset(new string("world"));
	cout << *pstr << endl;

	string* str = pstr.release(); // pstr = nullptr;
	delete str;
	str = nullptr;
	
	func();
	func2();
}*/

//shared_ptr 예제
/*
#include <iostream>
#include <string>
using namespace std;

#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK, __FILE__, __LINE__)
#define new DBG_NEW
#endif // !DBG_NEW
#endif

void addNum(shared_ptr<int> pnum) {
	(*pnum)++;
	cout << pnum.use_count() << endl;
}
int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	auto pnum1 = make_shared<int>();
	*pnum1 = 100;
	cout << *pnum1 << endl;

	auto pnum1_copy = pnum1; //copy 가능
	*pnum1_copy = 200;
	cout << *pnum1_copy << endl;
	cout << pnum1.use_count() << endl; //2
	addNum(pnum1);					   //3
	cout << pnum1.use_count() << endl; //2
	pnum1_copy.reset();
	cout << pnum1.use_count() << endl; //1

	//int* pnum2 = new int[5];
	shared_ptr<int[]>pnum2(new int[5]);
	pnum2[0] = 100;
	cout << pnum2[0] << endl;

	//int* pnum3 = ne int*[5];
	shared_ptr<shared_ptr<int[]>[]> pnum3(new shared_ptr<int[]>[5]);
	
	//for (int i = 0; i < 5; i++) {
	//	pnum3[i] = new int[3];
	//}
	for (int i = 0; i < 5; i++) {
		pnum3[i] = shared_ptr<int[]>(new int[3]);
	}
	pnum3[0][0] = 100;
	cout << pnum3[0][0] << endl;
}*/

//weak_ptr 예제
/*
#include <iostream>
#include <string>

using namespace std;

#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK, __FILE__, __LINE__)
#define new DBG_NEW
#endif // !DBG_NEW
#endif

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	auto pnum1 = make_shared<int>();
	*pnum1 = 100;

	shared_ptr<int> pnum1_c = pnum1;
	cout << pnum1.use_count() << endl; //2

	pnum1.reset();
	cout << *pnum1_c << endl; //2

	auto pnum2 = make_shared<int>();
	*pnum2 = 100;

	//weak_ptr<int> pnum2_w = pnum2;
	weak_ptr<int> pnum2_w(pnum2);
	cout << pnum2.use_count() << endl; //1
	{
		//cout << *pnum2_w << endl; (x)
		auto pnum2_s = pnum2_w.lock();
		if (pnum2_s) {
			cout << *pnum2_s << endl;
		}
		else {
			cout << "리소스 없음" << endl;
		}

		cout << pnum2.use_count() << endl; //2
	}
	cout << "============" << endl;;
	pnum2.reset();

	auto pnum3_s = pnum2_w.lock();
	if (pnum3_s){
		cout << *pnum3_s << endl;
	}
	else {
		cout << "리소스 없음" << endl;;
	}
}*/

