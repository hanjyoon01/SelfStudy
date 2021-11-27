#pragma once
#include "Ticket.h"
class GeneralTicket :
	public Ticket
{
private:
	bool payByCredit;
public:
	GeneralTicket();
	~GeneralTicket();
	using Ticket::Ticket;
	GeneralTicket(const double& price, const bool& payByCredit);

	double getPrice() const;
	bool getPayByCredit() const;
	void show() const;
};

