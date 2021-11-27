#pragma once
#include "Salesman.h"
#include <memory>
using std::unique_ptr;
using std::shared_ptr;

class SalesReport
{
private:
	double highestSales;
	double averageSales;
	size_t m_number;
	size_t count = 0;
	//Salesman* team;
	//unique_ptr<Salesman[]> team;
	//shared_ptr<Salesman[]> team;
	//Salesman** team;
	shared_ptr<shared_ptr<Salesman>[]> team;
public:
	SalesReport();
	SalesReport(const size_t& number);
	~SalesReport();
	void computeStats();
	shared_ptr<Salesman> getBestClerk();
	string getTeamInfo();
	size_t getNumber();
	void addMember();
};

