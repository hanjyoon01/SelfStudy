#include <iostream>
#include "GeneralTicket.h"
#include "AdvancedTicket.h"

using namespace std;

namespace jyhan {
	void printName() {
		std::cout << "학번:202011390 이름:한재윤" << std::endl;
	}
}

int main() {

	jyhan::printName();
	cout << endl;

	Ticket ticket(1500.0);
	ticket.show();
	cout << "---------------------" << endl;

	GeneralTicket gTicket(2500.0, true);
	gTicket.show();
	cout << "---------------------" << endl;

	AdvancedTicket aTicket(4000.0, 15);
	aTicket.show();
	cout << "---------------------" << endl;
}