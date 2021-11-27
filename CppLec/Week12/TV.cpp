#include "TV.h"
#include <iostream>
using namespace std;

TV::TV(const string& name, const int& price, const int& size)
	:Product(name, price), m_size(size)
{
}

TV::~TV()
{
}

int TV::getPrice() const
{
	return static_cast<int>(m_price - m_price * 0.1);
}

void TV::show() const
{
	Product::show();
	cout << "ȭ��ũ��: " << m_size << endl;
	cout << "�ǸŰ���: " << getPrice() << endl;
	cout << "------------------------------" << endl;
}
