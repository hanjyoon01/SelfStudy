#pragma once
#include <iostream>
#include <memory>
#include <vector>
#include "Product.h"

using std::string;
using std::unique_ptr;
using std::vector;

class Customer2
{
private:
	string m_name;
	int m_number;
	int m_count = 0;
	//Product** items;
	//unique_ptr<unique_ptr<Product>[]> items;
	vector<unique_ptr<Product>> items;
public:
	Customer2(const string& name, const int& number);
	~Customer2();
	void buy(unique_ptr<Product> item);
	string getName() const;
	int getCount() const;
	void showlist() const;
	void showTVlist() const;
	void showVegetablelist() const;
};
