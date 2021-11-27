#include "JyhanShoes.h"


JyhanShoes::JyhanShoes(const string& num, const string& type, const int& itemnum, const int& price, const string& gender, const string& shoetype, const int& size)
	:JyhanItems(num, type, itemnum, price), gender(gender), shoetype(shoetype), size(size)
{
}

void JyhanShoes::buy(const string& b)
{
	buyer.push_back(b);
}

ostream& operator<<(ostream& out, const JyhanShoes& s)
{
	out << "============================" << endl;
	out << "��Ϲ�ȣ: " << s.num << endl;
	out << "��ǰ����: " << s.type << endl;
	out << "��ǰ����: " << s.itemnum << endl;
	out << "����: " << s.price << endl;
	out << "============================" << endl;
	out << "��������: " << s.gender << endl;
	out << "�Ź�����: " << s.shoetype << endl;
	out << "������: " << s.size << endl;
	out << "============================" << endl;
	out << "���� ������" << endl;
	out << "----------------------------" << endl;
	for_each(s.buyer.begin(), s.buyer.end(), [](const auto& b) {cout << b << endl; });
	out << "----------------------------" << endl;
	out << endl;
	return out;
}
