#include <iostream>
#include "TV.h"
#include "Vegetable.h"
#include "Customer.h"
#include "Customer2.h"

using namespace std;

int main() {

	/*Customer hanjyoon("������", 5);
	hanjyoon.buy(new TV("�Ǳ�TV", 100, 20));
	hanjyoon.buy(new TV("����TV", 200, 40));
	hanjyoon.buy(new Vegetable("�ñ�ġ", 50, "����", 5));
	hanjyoon.buy(new TV("����TV", 100, 15));
	hanjyoon.showlist();*/

	Customer2 hanjyoon("������", 5);
	hanjyoon.buy(make_unique<TV>("�Ǳ�TV", 100, 20));
	hanjyoon.buy(make_unique<TV>("����TV", 200, 40));
	hanjyoon.buy(make_unique<Vegetable>("�ñ�ġ", 50, "����", 5));
	hanjyoon.buy(make_unique<TV>("����TV", 100, 15));
	hanjyoon.showlist();
	cout << "---------------------" << endl;
	hanjyoon.showVegetablelist();
	//Product item1("�Ǳ�TV", 100);
	//item1.show();

	//TV item2("�Ǳ�TV", 100, 20);
	//item2.show();
	//
	//Vegetable item3("�ñ�ġ", 10, "����", 5);
	//item3.show();
}