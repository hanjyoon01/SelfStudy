#include <iostream>
#include "TV.h"
#include "Vegetable.h"
#include "Customer.h"
#include "Customer2.h"

using namespace std;

int main() {

	/*Customer hanjyoon("한재윤", 5);
	hanjyoon.buy(new TV("건국TV", 100, 20));
	hanjyoon.buy(new TV("대학TV", 200, 40));
	hanjyoon.buy(new Vegetable("시금치", 50, "남해", 5));
	hanjyoon.buy(new TV("세종TV", 100, 15));
	hanjyoon.showlist();*/

	Customer2 hanjyoon("한재윤", 5);
	hanjyoon.buy(make_unique<TV>("건국TV", 100, 20));
	hanjyoon.buy(make_unique<TV>("대학TV", 200, 40));
	hanjyoon.buy(make_unique<Vegetable>("시금치", 50, "남해", 5));
	hanjyoon.buy(make_unique<TV>("세종TV", 100, 15));
	hanjyoon.showlist();
	cout << "---------------------" << endl;
	hanjyoon.showVegetablelist();
	//Product item1("건국TV", 100);
	//item1.show();

	//TV item2("건국TV", 100, 20);
	//item2.show();
	//
	//Vegetable item3("시금치", 10, "남해", 5);
	//item3.show();
}