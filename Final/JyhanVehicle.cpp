#include "JyhanVehicle.h"

JyhanVehicle::JyhanVehicle(const string& num, const string& type, const int& itemnum, const int& price, const string& company, const string& model, const int& capacity)
	:JyhanItems(num,type,itemnum,price), company(company), model(model), capacity(capacity)
{
}

void JyhanVehicle::buy(const string& b)
{
	buyer.push_back(b);
}

ostream& operator<<(ostream& out, const JyhanVehicle& v)
{
	out << "============================" << endl;
	out << "��Ϲ�ȣ: " << v.num << endl;
	out << "��ǰ����: " << v.type << endl;
	out << "��ǰ����: " << v.itemnum << endl;
	out << "����: " << v.price << endl;
	out << "============================" << endl;
	out << "����ȸ��: " << v.company << endl;
	out << "������: " << v.model << endl;
	out << "���뷮(cc): " << v.capacity << endl;
	out << "============================" << endl;
	out << "���� ������" << endl;
	out << "----------------------------" << endl;
	for_each(v.buyer.begin(), v.buyer.end(), [](const auto& b) {cout << b << endl; });
	out << "----------------------------" << endl;
	out << endl;
	return out;
}
