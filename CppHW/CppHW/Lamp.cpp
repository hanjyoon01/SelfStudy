#include <iostream>
#include "Lamp.h"
using std::cout;
using std::endl;

void Lamp::powerOnOff()
{
	isOn = !isOn;
}

void Lamp::changeLight()
{
	if (isOn) {
		if (illuminance < 3) {
			illuminance++;
			cout << "조도 : " << illuminance << endl;
		}
		else {
			illuminance = 1;
			cout << "조도 : " << illuminance << endl;
		}
	}
	else {
		cout << "전원이 꺼져있음" << endl;
	}
}
