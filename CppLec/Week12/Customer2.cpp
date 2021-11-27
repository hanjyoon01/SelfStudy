#include "Customer2.h"
#include "TV.h"
#include "Vegetable.h"
#include <iostream>
using namespace std;

Customer2::Customer2(const string& name, const int& number)
	:m_name(name), m_number(number)
{
	/*if (m_number > 0)
		items = new Product * [m_number];
	else
		items = nullptr;*/
}

Customer2::~Customer2()
{
	//if (items != nullptr) {
	//	for (size_t i = 0; i < m_count; i++) {
	//		delete items[i];
	//	}
	//	delete[] items;
	//}
}

void Customer2::buy(unique_ptr<Product> item)
{
	//if (m_count < m_number) {
	//	items[m_count++] = move(item);
	//}
	items.push_back(move(item));
}

string Customer2::getName() const
{
	return m_name;
}

int Customer2::getCount() const
{
	return items.size();
}

void Customer2::showlist() const
{
	cout << "���̸�: " << m_name << endl;
	cout << "���Ű���: " << items.size() << endl;

	int price = 0;

	for (auto it = items.begin(); it != items.end(); it++) {
		(*it)->show();
		price += (*it)->getPrice();
	}
	//for (size_t i = 0; i < items.size(); i++) {
	//	items[i]->show();
	//	price += items[i]->getPrice();
	//}
	cout << "�� ���� �ݾ�: " << price << endl;
}

void Customer2::showTVlist() const
{
	for (size_t i = 0; i < items.size(); i++) {
		TV* tv = dynamic_cast<TV*>(items[i].get());
		if (tv != nullptr)
			items[i]->show();
	}
}

void Customer2::showVegetablelist() const
{
	for (size_t i = 0; i < items.size(); i++) {
		Vegetable* vegetable = dynamic_cast<Vegetable*>(items[i].get());
		if (vegetable != nullptr)
			items[i]->show();
	}
}
