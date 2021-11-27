#include <iostream>
#include "TV.h"
#include "Vegetable.h"
#include "Customer2.h"

using namespace std;

int main() {
		
	Customer2 hanjyoon("한재윤", 5);
	hanjyoon.buy(make_unique<TV>("건국TV", 100, 20));
	hanjyoon.buy(make_unique<TV>("대학TV", 200, 40));
	hanjyoon.buy(make_unique<Vegetable>("시금치", 50, "남해", 5));
	hanjyoon.buy(make_unique<TV>("세종TV", 100, 15));
	hanjyoon.showTVlist();
	cout << endl;
	hanjyoon.showVegetablelist();
	

}