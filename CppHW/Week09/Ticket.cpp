#include "Ticket.h"
#include <iostream>
using namespace std;

Ticket::Ticket(): Ticket(0.0)
{
}

Ticket::Ticket(const int& price)
	:price(price)
{
	static int n = 1;
	this->number = n++;
}

Ticket::~Ticket()
{
}

int Ticket::getNumber() const
{
	return this->number;
}

double Ticket::getPrice() const
{
	return this->price;
}

void Ticket::setPrice(const double& price)
{
	this->price = price;
}

void Ticket::show() const
{
	cout << "Ƽ�Ϲ�ȣ: " << this->number << endl;
	cout << "��������: " << this->price << endl;
}
