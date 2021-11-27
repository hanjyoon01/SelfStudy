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
			cout << "���� : " << illuminance << endl;
		}
		else {
			illuminance = 1;
			cout << "���� : " << illuminance << endl;
		}
	}
	else {
		cout << "������ ��������" << endl;
	}
}
