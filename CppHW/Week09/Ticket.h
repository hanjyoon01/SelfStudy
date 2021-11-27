#pragma once
class Ticket
{
protected:
	int number;
	double price;
public:
	Ticket();
	Ticket(const int& price);
	~Ticket();

	int getNumber() const;
	double getPrice() const;
	void setPrice(const double& price);
	void show() const;
};

