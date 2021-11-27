#pragma once
#include "JyhanItems.h"
class JyhanShoes :
	public JyhanItems
{
private:
	string gender;
	string shoetype;
	int size;
public:
	using JyhanItems::JyhanItems;
	JyhanShoes(const string& num, const string& type, const int& itemnum, const int& price,
		const string& gender, const string& shoetype, const int& size);
	void buy(const string& b);
	friend ostream& operator<<(ostream& out, const JyhanShoes& s);
};

