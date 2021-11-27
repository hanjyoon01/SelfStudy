#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class JyhanItems
{
protected:
	string num;
	string type;
	int itemnum;
	int price;
	vector<string> buyer;

public:
	JyhanItems(const string& num, const string& type, const int &itemnum, const int& price);
	~JyhanItems();
	virtual void buy(const string& b) = 0;
	friend ostream& operator<<(ostream& out, const JyhanItems& i);
	bool operator>(const JyhanItems& i) const {
		return price > i.price;
	}
};

