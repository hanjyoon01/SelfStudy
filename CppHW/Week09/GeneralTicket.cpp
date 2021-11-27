#include "GeneralTicket.h"
#include <iostream>
using namespace std;

GeneralTicket::GeneralTicket()
	:GeneralTicket(0.0, false)
{
}

GeneralTicket::~GeneralTicket()
{
}

GeneralTicket::GeneralTicket(const double& price, const bool& payByCredit)
:Ticket(price), payByCredit(payByCredit)
{
}

double GeneralTicket::getPrice() const
{
	return this->price;
}

bool GeneralTicket::getPayByCredit() const
{
	return payByCredit;
}

void GeneralTicket::show() const
{
	cout << "티켓번호: " << this->number << endl;
	cout << "가격정보: " << this->price << endl;
	cout << "카드결제여부: " << boolalpha << this->payByCredit << endl;
	
	double p = this->price;

	if (this->getPayByCredit()) {
		p = this->price * 1.1;
	}

	cout << "지불금액: " << p << endl;
}
