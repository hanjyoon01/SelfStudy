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
		std::cout << "�й�:202011390 �̸�:������" << std::endl;
	}
}

int main() {

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	jyhan::printName();
	cout << endl;

	//2�� ����
	//JyhanItems p("a10001", "�ڵ���", 2, 1000);

	//3�� ����
	cout << "3)" << endl;
	JyhanItems* car = new JyhanVehicle("A0001", "�ڵ���", 2, 10000, "�Ǳ���", "Konkuk9", 2500);

	//4�� ����
	cout << "4)" << endl;
	JyhanItems* shoes = new JyhanVehicle("S0001", "�Ź߷�", 3, 100, "������", "�Ǳ�����", 240);

	//5�� ����
	cout << "5)" << endl;
	car->buy("ȫ�浿");
	shoes->buy("��浿");
	shoes->buy("�̱浿");

	//6�� ����
	cout << "6)" << endl;
	cout << *car << endl;
	cout << *shoes << endl;

	//7�� ����
	cout << "7)" << endl;
	JyhanMarket market("�Ǳ�Market");

	//8�� ����
	cout << "8)" << endl;
	market.addProduct(new JyhanVehicle("A0001", "�ڵ���", 2, 10000, "�Ǳ���", "Konkuk9", 2500));
	market.addProduct(new JyhanShoes("S0001", "�Ź߷�", 3, 100, "������", "�Ǳ�����", 240));
	market.addProduct(new JyhanVehicle("A0002", "�ڵ���", 1, 20000, "������", "Konkuk", 3000));
	market.addProduct(new JyhanShoes("S0002", "�Ź߷�", 2, 200, "������", "�Ǳ��ȭ", 270));
	market.addProduct(new JyhanShoes("S0003", "�Ź߷�", 4, 300, "������", "�Ǳ�����", 235));

	//9�� ����
	auto items = market.getProducts();

	//10�� ����
	//uto pos = find_if(items.begin(), items.end(), [](auto p) { {JyhanShoes* s = dynamic_cast<JyhanShoes*>(p);

	//11�� ����
	cout << "11)" << endl;
	market.showShoelist();

	//12�� ����
	cout << "12)" << endl;
	sort(items.begin(), items.end(), greater<>());
	for_each(items.begin(), items.end(), [](const auto& b) {cout << *b << endl; });
}