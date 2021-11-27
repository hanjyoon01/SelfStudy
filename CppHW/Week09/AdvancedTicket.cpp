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
	return this->price;
}

int AdvancedTicket::getAdvanceDays() const
{
	return this->advanceDays;
}

void AdvancedTicket::show() const
{
	cout << "Ƽ�Ϲ�ȣ: " << this->number << endl;
	cout << "��������: " << this->price << endl;
	cout << "����������: " << this->advanceDays << endl;

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
	cout << "���ұݾ�: " << p << endl;
}
