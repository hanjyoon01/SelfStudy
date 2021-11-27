#include <iostream>
#include "Salesman.h"
#include "SalesReport.h"
using namespace std;

namespace jyhan {
	void printName() {
		std::cout << "�й�:202011390 �̸�:������" << std::endl;
	}
}

int main() {

	jyhan::printName();
	cout << endl;

	SalesReport team1(3);
	team1.addMember();
	team1.addMember();
	team1.addMember();
	team1.addMember();
	team1.computeStats();

	if (team1.getNumber() > 0)
		cout << team1.getBestClerk()->getSalesmanInfo() << endl;

	return 0;
}