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
	out << "등록번호: " << s.num << endl;
	out << "제품유형: " << s.type << endl;
	out << "제품개수: " << s.itemnum << endl;
	out << "가격: " << s.price << endl;
	out << "============================" << endl;
	out << "성별유형: " << s.gender << endl;
	out << "신발종류: " << s.shoetype << endl;
	out << "사이즈: " << s.size << endl;
	out << "============================" << endl;
	out << "구매 참여자" << endl;
	out << "----------------------------" << endl;
	for_each(s.buyer.begin(), s.buyer.end(), [](const auto& b) {cout << b << endl; });
	out << "----------------------------" << endl;
	out << endl;
	return out;
}
