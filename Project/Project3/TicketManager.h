#pragma once
#include <iostream>
#include "Ticket.h";
using namespace std;

class TicketManager
{
private:
	string m_name;
	int totalNumber;
	Ticket** ticket = nullptr;
	int count = 0;
public:
	TicketManager() = delete;
	TicketManager(const string& name, const int number);
	~TicketManager();
	void buy(Ticket* t);
	void show() const;
	int getCount() const {
		return this->count;
	}
	void showGeneralTIcket(const bool& card);
	void showAdvancedTicket();
};
ostream& operator<<(ostream& out, const TicketManager& manager);
