#include <iostream>
#include "Lamp.h"
#include "User.h"
using namespace std;

namespace jyhan {
	void printName() {
		std::cout << "�й�:202011390 �̸�:������" << std::endl;
	}
}

int main() {
		
	jyhan::printName();
	cout << endl;

	Lamp l1;
	User user;

	l1.powerOnOff();
	l1.changeLight();
	l1.changeLight();
	l1.changeLight();
	l1.changeLight();
	l1.powerOnOff();
	l1.changeLight();

	cout << "=========user=========" << endl;
	user.changeLight(l1);
	user.turnOnOff(l1);
	user.changeLight(l1);
}