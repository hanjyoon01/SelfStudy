//예제1

#include <iostream>
#include "Salesman.h"
using namespace std;

Salesman getSalesman(const string& name) {
	Salesman s(name);
	return s;
}

Salesman getSalesman2(const string& name) {
	return Salesman(name);
}

int main() {

	Salesman s1;
	Salesman s2("hanjyoon2");
	Salesman s3("hanjyoon3",200.0);


	//예제2
	Salesman copy1(s2);
	Salesman copy2 = s3;
	cout << copy1.getSalesmanInfo() << endl;
	cout << copy2.getSalesmanInfo() << endl;
	Salesman copy3 = Salesman("hanjyoon3");

	cout << "=====================" << endl;
	copy3.showFriend(s3);
	cout << "=====================" << endl;
	Salesman s4 = getSalesman("hanjyoon4"); // s
	cout << "=====================" << endl;
	Salesman s5 = getSalesman2("hanjyoon5"); // Salesman(name)

	//예제1
	//Salesman s4 ="hanjyoon"s;
	//Salesman s4("hanjyoon");

	//auto str = "greenjoa";
	//cout << typeid(str).name() << endl;
	//auto str2 = "greenjoa"s;
	//cout << typeid(str2).name() << endl;

	//Salesman s4 = s3;
	//Salesman s5(s4);
	//cout << s5.getSalesmanInfo() << endl;


}