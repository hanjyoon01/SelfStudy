#pragma once
#include "Ticket.h"
class AdvancedTicket :
	public Ticket
{
private:
	int advanceDays;
public:
	AdvancedTicket();
	~AdvancedTicket();
	AdvancedTicket(const double& price, const int& advanceDays);

	double getPrice() const;
	int getAdvanceDays() const;
	void show() const;
};

