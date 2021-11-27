#include "AdvancedTicket.h"
#include <iostream>
using namespace std;

AdvancedTicket::AdvancedTicket()
	: AdvancedTicket(0.0, 0)
{
}

AdvancedTicket::~AdvancedTicket()
{
}

AdvancedTicket::AdvancedTicket(const double& price, const int& advanceDays)
	:Ticket(price), advanceDays(advanceDays)
{
}

double AdvancedTicket::getPrice() const
{
	double p = this->price;

	if (this->advanceDays >= 30) {
		p = this->price * 0.5;
	}
	else if (this->advanceDays >= 20) {
		p = this->price * 0.7;
	}
	else if (this->advanceDays >= 10) {
		p = this->price * 0.9;
	}
	return p;
}

int AdvancedTicket::getAdvanceDays() const
{
	return this->advanceDays;
}

void AdvancedTicket::show() const
{
	cout << "티켓번호: " << this->number << endl;
	cout << "가격정보: " << this->price << endl;
	cout << "사전예약일: " << this->advanceDays << endl;
	cout << "지불금액: " << this->getPrice() << endl;
}
