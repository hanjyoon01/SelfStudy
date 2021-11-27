#pragma once
#include "JyhanItems.h"
class JyhanVehicle :
	public JyhanItems
{
private:
	string company;
	string model;
	int capacity;
public:
	using JyhanItems::JyhanItems;
	JyhanVehicle(const string& num, const string& type, const int& itemnum, const int& price, 
		const string& company, const string& model, const int& capacity);
	void buy(const string& b);
	friend ostream& operator<<(ostream& out, const JyhanVehicle& v);
};

