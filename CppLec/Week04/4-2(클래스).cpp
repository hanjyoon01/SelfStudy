//클래스 예제1

#include <iostream>
#include <string>
#include "TV.h"
#include "User.h"
using namespace std;

int main() {

	TV tv1,tv2;
	User user,user2;

	user.setName("hanjyoon");
	cout << "========TV1========" << endl;
	user.turnOnOff(tv1);
	user.changeChannel(tv1, 12);
	user.changeVolume(tv1, 10);

	cout << "========TV2========" << endl;
	user.turnOnOff(tv2);
	user.changeChannel(tv2, 22);
	user.changeVolume(tv2, 15);

	cout << "========TV1========" << endl;
	user.turnOnOff(tv1);
	user.changeChannel(tv1, 32);

	//tv1.powerOnOff();
	//tv1.setChannel(10);
	//tv1.setVolume(12);
	//tv1.powerOnOff();
	//tv1.setChannel(50);
	//tv1.setVolume(22);

	return 0;
}