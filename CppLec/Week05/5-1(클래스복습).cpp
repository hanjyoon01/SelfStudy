//���� ����1
/*
#include <iostream>
#include "Dice.h"
#include "Player.h"
#include <ctime>
using namespace std;

int main() {
	srand((unsigned)time(NULL));
	Dice dice1, dice2;
	Player player1, player2;
	player1.setName("ȫ�浿");
	player2.setName("��浿");

	player1.roll(dice1, dice2);
	player2.roll(dice1, dice2);

	if (player1.getTotal() > player2.getTotal()) {
		cout << player1.getName() << "�� �¸� ==> ���� (" <<
			player1.getTotal() << "," << player2.getTotal() << ")" << endl;
	}
	else if (player1.getTotal() < player2.getTotal()) {
		cout << player2.getName() << "�� �¸� ==> ���� (" <<
			player1.getTotal() << "," << player2.getTotal() << ")" << endl;
	}
	else {
		cout << "���º� ==> ���� (" <<
			player1.getTotal() << "," << player2.getTotal() << ")" << endl;
	}

	return 0;
}*/