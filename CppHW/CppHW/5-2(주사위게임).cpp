#include <iostream>
#include "Dice.h"
#include "Player.h"
#include <ctime>
using namespace std;

namespace jyhan {
	void printName() {
		std::cout << "ÇÐ¹ø:202011390 ÀÌ¸§:ÇÑÀçÀ±" << std::endl;
	}
}

int main() {

	jyhan::printName();
	cout << endl;

	Dice dice1;
	Player p1("ÇÑÀçÀ±");

	cout << dice1.getFaceValue() << endl;
	cout << p1.getName() << endl;
}