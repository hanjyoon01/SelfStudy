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
	out << "등록번호: " << i.num << endl;
	out << "제품유형: " << i.type << endl;
	out << "제품개수: " << i.itemnum << endl;
	out << "가격: " << i.price << endl;
	out << "============================" << endl;
	out << "구매 참여자" << endl;
	out << "----------------------------" << endl;
	for_each(i.buyer.begin(), i.buyer.end(), [](const auto& b) {cout << b << endl; });
	out << "----------------------------" << endl;
	out << endl;
	return out;
}
