#pragma once
#include <iostream>
#include "JyhanItems.h"
#include "JyhanVehicle.h"
#include "JyhanShoes.h"
using namespace std;
class JyhanMarket
{
private:
	string name;
	vector<JyhanItems*> product;
public:
	JyhanMarket(const string& name);
	~JyhanMarket();

	void addProduct(JyhanItems* p);
	vector<JyhanItems*> getProducts();
	void showShoelist() const;
};

