#include "JyhanItems.h"


JyhanItems::JyhanItems(const string& num, const string& type, const int& itemnum, const int& price)
	:num(num), type(type), itemnum(itemnum), price(price)
{
}

JyhanItems::~JyhanItems()
{
}

void JyhanItems::buy(const string& b)
{
	buyer.push_back(b);
}

ostream& operator<<(ostream& out, const JyhanItems& i)
{
	out << "============================" << endl;
	out << "��Ϲ�ȣ: " << i.num << endl;
	out << "��ǰ����: " << i.type << endl;
	out << "��ǰ����: " << i.itemnum << endl;
	out << "����: " << i.price << endl;
	out << "============================" << endl;
	out << "���� ������" << endl;
	out << "----------------------------" << endl;
	for_each(i.buyer.begin(), i.buyer.end(), [](const auto& b) {cout << b << endl; });
	out << "----------------------------" << endl;
	out << endl;
	return out;
}
