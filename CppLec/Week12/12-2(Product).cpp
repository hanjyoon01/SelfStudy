#include <iostream>
#include "TV.h"
#include "Vegetable.h"
#include "Customer2.h"

using namespace std;

int main() {
		
	Customer2 hanjyoon("������", 5);
	hanjyoon.buy(make_unique<TV>("�Ǳ�TV", 100, 20));
	hanjyoon.buy(make_unique<TV>("����TV", 200, 40));
	hanjyoon.buy(make_unique<Vegetable>("�ñ�ġ", 50, "����", 5));
	hanjyoon.buy(make_unique<TV>("����TV", 100, 15));
	hanjyoon.showTVlist();
	cout << endl;
	hanjyoon.showVegetablelist();
	

}