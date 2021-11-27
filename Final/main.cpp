#include <iostream>
#include <string>
#include "JyhanItems.h"
#include "JyhanMarket.h"
#include "JyhanShoes.h"
#include "JyhanVehicle.h"

using namespace std;

#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK, __FILE__, __LINE__)
#define new DBG_NEW
#endif // !DBG_NEW
#endif

namespace jyhan {
	void printName() {
		std::cout << "학번:202011390 이름:한재윤" << std::endl;
	}
}

int main() {

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	jyhan::printName();
	cout << endl;

	//2번 문항
	//JyhanItems p("a10001", "자동차", 2, 1000);

	//3번 문항
	cout << "3)" << endl;
	JyhanItems* car = new JyhanVehicle("A0001", "자동차", 2, 10000, "건국차", "Konkuk9", 2500);

	//4번 문항
	cout << "4)" << endl;
	JyhanItems* shoes = new JyhanVehicle("S0001", "신발류", 3, 100, "여성용", "건국샌들", 240);

	//5번 문항
	cout << "5)" << endl;
	car->buy("홍길동");
	shoes->buy("김길동");
	shoes->buy("이길동");

	//6번 문항
	cout << "6)" << endl;
	cout << *car << endl;
	cout << *shoes << endl;

	//7번 문항
	cout << "7)" << endl;
	JyhanMarket market("건국Market");

	//8번 문항
	cout << "8)" << endl;
	market.addProduct(new JyhanVehicle("A0001", "자동차", 2, 10000, "건국차", "Konkuk9", 2500));
	market.addProduct(new JyhanShoes("S0001", "신발류", 3, 100, "여성용", "건국샌들", 240));
	market.addProduct(new JyhanVehicle("A0002", "자동차", 1, 20000, "대학차", "Konkuk", 3000));
	market.addProduct(new JyhanShoes("S0002", "신발류", 2, 200, "남성용", "건국운동화", 270));
	market.addProduct(new JyhanShoes("S0003", "신발류", 4, 300, "여성용", "건국구두", 235));

	//9번 문항
	auto items = market.getProducts();

	//10번 문항
	//uto pos = find_if(items.begin(), items.end(), [](auto p) { {JyhanShoes* s = dynamic_cast<JyhanShoes*>(p);

	//11번 문항
	cout << "11)" << endl;
	market.showShoelist();

	//12번 문항
	cout << "12)" << endl;
	sort(items.begin(), items.end(), greater<>());
	for_each(items.begin(), items.end(), [](const auto& b) {cout << *b << endl; });
}