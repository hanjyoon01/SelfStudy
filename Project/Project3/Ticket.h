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
	virtual double getPrice() const=0;
	void setPrice(const double& price);
	virtual void show() const=0;
};

