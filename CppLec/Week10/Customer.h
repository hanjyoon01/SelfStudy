#pragma once
#include <iostream>
#include "Product.h"
using std::string;

class Customer
{
private:
	string m_name;
	int m_number;
	int m_count = 0;
	Product** items;
public:
	Customer(const string& name, const int& number);
	~Customer();
	void buy(Product* item);
	string getName() const;
	int getCount() const;
	void showlist() const;
};

