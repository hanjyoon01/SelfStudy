#include "JyhanMarket.h"

JyhanMarket::JyhanMarket(const string& name)
	:name(name)
{
}

JyhanMarket::~JyhanMarket()
{
}

void JyhanMarket::addProduct(JyhanItems* p)
{
	JyhanVehicle* v = dynamic_cast<JyhanVehicle*>(p);
	if (v != nullptr)
		product.push_back(v);

	JyhanShoes* s = dynamic_cast<JyhanShoes*>(p);
	if (s != nullptr)
		product.push_back(s);
}

vector<JyhanItems*> JyhanMarket::getProducts()
{
	return product;
}

void JyhanMarket::showShoelist() const
{
	cout << "운동화 목록" << endl;
	for_each(product.begin(), product.end(), [](const auto& p)
		{JyhanShoes* s = dynamic_cast<JyhanShoes*>(p);
	if (s != nullptr)
		cout << *s << endl; });
}

