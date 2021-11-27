#include "TicketManager.h"
#include "AdvancedTicket.h"
#include "GeneralTicket.h"

TicketManager::TicketManager(const string& name, const int number)
	:m_name(name), totalNumber(number)
{
	if (totalNumber > 0)
		ticket = new Ticket * [totalNumber];
	else
		ticket = nullptr;
}

TicketManager::~TicketManager()
{
	if (ticket != nullptr) {
		for (size_t i = 0; i < count; i++) {
			delete ticket[i];
		}
		delete[] ticket;
	}
}

void TicketManager::buy(Ticket* t)
{
	if (count < totalNumber) {
		ticket[count++] = t;
	}
}

void TicketManager::show() const
{
	cout << "-----------  �ܼ�Ʈ  ����  -----------" << endl;
	cout << "�ܼ�Ʈ �̸�: " << m_name <<endl;
	cout << "���Ű���: " << count << endl;
	cout << "----------  Ƽ�� ���� ��Ȳ  ----------\n" << endl;

	int price = 0;
	for (size_t i = 0; i < count; i++) {
		ticket[i]->show();
		cout << endl;
		price += ticket[i]->getPrice();
	}
	cout << "�� ���� �ݾ�: " << price << endl;
	cout << "--------------------------------------\n" << endl;
}

void TicketManager::showGeneralTIcket(const bool& card)
{
	cout << "----------  �Ϲ� ���� ��Ȳ  ----------\n" << endl;
	cout << "ī�� ���� ����:" << boolalpha << card << endl;
	cout << "--------------------------------------\n" << endl;

	int price = 0;

	for (size_t i = 0; i < count; i++) {
		GeneralTicket* GT = dynamic_cast<GeneralTicket*>(ticket[i]);
		if (GT != nullptr) {
			if (GT->getPayByCredit() == card) {
				ticket[i]->show();
				cout << endl;
				price += ticket[i]->getPrice();
			}
		}
	}
	cout << "--------------------------------------" << endl;
	cout << "�� ���� �ݾ�: " << price << endl;
	cout << "--------------------------------------\n" << endl;
}

void TicketManager::showAdvancedTicket()
{
	cout << "----------  ���� ���� ��Ȳ  ----------\n" << endl;

	int price = 0;

	for (size_t i = 0; i < count; i++) {
		AdvancedTicket* AT = dynamic_cast<AdvancedTicket*>(ticket[i]);
		if (AT != nullptr) {
			ticket[i]->show();
			cout << endl;
			price += ticket[i]->getPrice();
		}
	}

	cout << "--------------------------------------" << endl;
	cout << "�� ���� �ݾ�: " << price <<endl;
	cout << "--------------------------------------\n" << endl;
}

ostream& operator<<(ostream& out, const TicketManager& manager)
{
	manager.show();
	return out;
}
