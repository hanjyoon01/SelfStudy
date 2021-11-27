#pragma once
#include <string>
#include "Dice.h"
using std::string;

class Player
{
private:
	string name;
	int total = 0;
public:
	Player(const string& _name);
	void setName(const string& _name);
	string getName();
	void roll(Dice& dice1, Dice& dice2);
	int getTotal();
};

