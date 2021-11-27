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
	out << "등록번호: " << v.num << endl;
	out << "제품유형: " << v.type << endl;
	out << "제품개수: " << v.itemnum << endl;
	out << "가격: " << v.price << endl;
	out << "============================" << endl;
	out << "제조회사: " << v.company << endl;
	out << "차량모델: " << v.model << endl;
	out << "배기용량(cc): " << v.capacity << endl;
	out << "============================" << endl;
	out << "구매 참여자" << endl;
	out << "----------------------------" << endl;
	for_each(v.buyer.begin(), v.buyer.end(), [](const auto& b) {cout << b << endl; });
	out << "----------------------------" << endl;
	out << endl;
	return out;
}
