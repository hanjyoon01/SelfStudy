#include "header.h"
int main()
{
	// �ó����� �����ϱ�
	int a; // ���ǹ� ��� �뵵
	int count = 1; //�õ�Ƚ��
	srand((unsigned)time(NULL));
	//�������� ����
	printf("\n�ں��� ã���\n\n���������� �����ϼ���(1:�ʹ�(�ʱ�) 2:�߹�(�߱�) 3:�Ĺ�(���) 4:���α׷� ����): ");
	scanf("%d", &a);
	if (a == 4)
	{
		printf("\n������ �����մϴ�...\n\n");
		return 0;
	}
	printf("\n���� ã�� ������ �����մϴ�...");
	Sleep(1500);
	system("cls");
	// 2.���� �����ϱ�
	switch (a)
	{
	case 1:
		prologue(&count);
		break;
	case 2:
		scenario_1(&count);
		break;
	case 3:	
		scenario_2(&count);
		break;
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void easy(int *try)
{
	int motion = 45, move = 0; //�ִ� �̵� Ƚ�� ����
	int fx[EASY], fy[EASY]; //��� ��ġ
	int count[EASY] = { 0 }; //������ ��� Ȯ�ο�
	int ch, a, x = 4, y = 2;
	char b;
	
	//���� Ʋ
	printf("�âââââââââââââââââââ�\n");
	for (a = 0; a < 20; a++)
		printf("��                                    ��\n");
	printf("�âââââââââââââââââââ�\n");

	//���� ��ġ (������ �Ʒ�)
	fx[0] = 2*(12+(rand() % 6)); //24 ~ 34
	fy[0] = (rand() % 12) + 6; //6 ~ 17
	gotoxy(fx[0], fy[0]);
	printf(FLAG_MARK);

	//�� ���� ��� (5��)
	for (a = 1; a < EASY; a++)
	{
		fx[a] = 2 * (2 + (rand() % 16)); // 4 ~ 34
		fy[a] = (rand() % 17) + 3; // 3 ~ 19
		gotoxy(fx[a], fy[a]);
		printf(FLAG_MARK);
	}

	//���� ����
	while (1)
	{
		gotoxy(0, 22);
		printf("��ħ���� ã�ƾ���!!! (�̵�Ƚ��: %d/%d)", move, motion);
		//���������� ��Ż�� ���
		if ((x < 1) || (x > 37) || (y < 1) || (y > 20))
		{
			gotoxy(0, 24);
			printf("���� ����� �� ��!!!");
			Sleep(1500);
			printf("\r                        ");
			switch (ch)
			{
			case 72:
				y++;
				break;
			case 80:
				y--;
				break;
			case 75:
				x += 2;
				break;
			case 77:
				x -= 2;
				break;
			}
		}

		//��ġ �ʱ�ȭ
		gotoxy(x, y);
		printf(PLAYER_MARK);

		//����Ű �̵� 
		ch = _getch();
		if (ch == 224)
			ch = _getch();
		switch (ch)
		{
		case 72:
			printf("\b\b  ");
			y--;
			break;
		case 80:
			printf("\b\b  ");
			y++;
			break;
		case 75:
			printf("\b\b  ");
			x-=2;
			break;
		case 77:
			printf("\b\b  ");
			x+=2;
			break;
		}
		move++; //�̵�Ƚ�� ����

		//������ ã�� ���
		if (x == fx[0] && y == fy[0])
		{
			gotoxy(0, 24);
			printf("���ڸ� ã�Ҵ�! ���ھȿ� ��ħ���� �־�!\n\n");
			printf("��ħ���� ȹ���ߴ�!\n\n");
			printf("���� �ܰ�� �Ѿ�ڽ��ϱ�? (y or n): ");
			while ((b = getchar()) != 224)
			if (b == 'y') //���� �ܰ� 
			{
				printf("\n���� �ܰ�� �Ѿ�ϴ�...");
				Sleep(3000);
				system("cls");
				scenario_1(try); //�߱� �ܰ�
			}
			else if (b == 'n') //���� ����
			{
				printf("\n�޴��� ���ư��ϴ�...(�õ�Ƚ��: %dȸ)\n\n", *try);
				Sleep(2000);
				system("cls");
				*try = 1;
				main();
			}
		}
		//�� ���� ����� ã�� ���
		for (a = 1; a <= 2; a++)
		{
			if (x == fx[a] && y == fy[a])
			{
				if (count[a] == 1)
					continue;
				gotoxy(0, 24);
				printf("��ź�̴�!!!\n\nĳ������ ��ġ�� �ʱ�ȭ �˴ϴ�...");
				gotoxy(x, y);
				printf("   ");
				Sleep(2000);
				gotoxy(0, 24);
				printf("\r               \n\n");
				printf("\r                                    \n");
				// ĳ���� ��ġ �ʱ�ȭ
				x = 4; 
				y = 2;
				count[a]++;
			}
		}
		for (a = 3; a <= 5; a++)
		{
			if (x == fx[a] && y == fy[a])
			{
				if (count[a] == 1)
					continue;
				gotoxy(0, 24);
				printf("�ƹ��͵� ����...");
				Sleep(2000);
				printf("\r                               ");
				count[a]++;
			}
		}
		//�̵�Ƚ�� �ʰ� �� ����
		if (move >= motion)
		{
			gotoxy(0, 24);
			printf("�ִ� �̵� Ƚ���� �ʰ��߽��ϴ�! �ٽ� �Ͻðڽ��ϱ�? (y or n): ");
			while ((b = getchar()) != 224)
			if (b == 'y')
			{
				(*try)++; //�õ�Ƚ�� ����
				printf("\n�ٽ� �����մϴ�...");
				Sleep(2000);
				system("cls");
				easy(try);
			}
			else if (b == 'n')
			{
				printf("\n�޴��� ���ư��ϴ�...(�õ�Ƚ��: %dȸ)\n\n", *try);
				Sleep(2000);
				system("cls");
				*try = 1;
				main();
			}
		}
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void medium(int *try)
{ 
	int motion = 50, move = 0; //�ִ� �̵� Ƚ�� ����
	int fx[MEDIUM], fy[MEDIUM]; //��� ��ġ
	int fx2[MEDIUM], fy2[MEDIUM]; //��ֹ� ��ġ
	int count[MEDIUM] = { 0 }; //������ ��� Ȯ�ο�
	int ch, a, x = 4, y = 2;
	char b;

	//���� Ʋ
	printf("�âââââââââââââââââââ�\n");
	for (a = 0; a < 20; a++)
		printf("��                                    ��\n");
	printf("�âââââââââââââââââââ�\n");

	//���� ��ġ (�Ʒ���)
	fx[0] = 2 * (3 + (rand() % 15)); //6 ~ 34
	fy[0] = (rand() % 5) + 15; //15 ~ 19
	gotoxy(fx[0], fy[0]);
	printf(FLAG_MARK);

	//�� �� ���, ��ֹ� (6����)
	for (a = 1; a < MEDIUM; a++)
	{
		fx[a] = 2 * (2 + (rand() % 16)); // 4 ~ 34
		fy[a] = (rand() % 17) + 3; // 3 ~ 19
		fx2[a] = 2 * (2 + (rand() % 16)); // 4 ~ 34
		fy2[a] = (rand() % 17) + 3; // 3 ~ 19
		gotoxy(fx[a], fy[a]);
		printf(FLAG_MARK);
		gotoxy(fx2[a], fy2[a]);
		printf(WALL_MARK);
	}

	//���� ����
	while (1)
	{
		gotoxy(0, 22);
		printf("�̵�Ƚ��: %d/%d", move, motion);
		//���������� ��Ż�� ���
		if ((x < 1) || (x > 37) || (y < 1) || (y > 20))
		{
			gotoxy(0, 24);
			printf("���� ����� �� ��!!!");
			Sleep(1500);
			printf("\r                        ");
			switch (ch)
			{
			case 72:
				y++;
				break;
			case 80:
				y--;
				break;
			case 75:
				x+=2;
				break;
			case 77:
				x-=2;
				break;
			}
		}

		//��ġ �ʱ�ȭ
		gotoxy(x, y);
		printf(PLAYER_MARK);

		//����Ű �̵� 
		ch = _getch();
		if (ch == 224)
			ch = _getch();
		switch (ch)
		{
		case 72:
			printf("\b\b  ");
			y--;
			break;
		case 80:
			printf("\b\b  ");
			y++;
			break;
		case 75:
			printf("\b\b  ");
			x-=2;
			break;
		case 77:
			printf("\b\b  ");
			x+=2;
			break;
		}
		move++; //�̵�Ƚ�� ����

		//������ ã�� ���
		if (x == fx[0] && y == fy[0])
		{
			gotoxy(0, 24);
			printf("���ڸ� ã�Ҵ�! �ȿ� ������ �־�!\n\n");
			printf("������ ȹ���ߴ�!\n\n");
			printf("���� �ܰ�� �Ѿ�ڽ��ϱ�? (y or n): ");
			while ((b = getchar()) != 224)
			if (b == 'y')
			{
				printf("\n���� �ܰ�� �Ѿ�ϴ�...");
				Sleep(3000);
				system("cls");
				scenario_2(try);
			}
			else if (b == 'n')
			{
				printf("\n�޴��� ���ư��ϴ�...(�õ�Ƚ��: %dȸ)\n\n", *try);
				Sleep(2000);
				system("cls");
				*try = 1;
				main();
			}
		}
		//��Ʈ�� ã�� ���
		if (x == fx[1] && y == fy[1])
		{
			if (count[1] == 1)
				continue;
			gotoxy(0, 24);
			printf("��Ʈ�� �����!\n\n");
			printf("��Ʈ: ���ڴ� �Ʒ��ʿ� �ִ�...");
			Sleep(3000);
			gotoxy(0, 24);
			printf("\r                    \n\n");
			printf("\r                                 \n");
			count[1]++;
		}
		//��ź�� ã�� ���
		for (a = 2; a <= 5; a++)
		{
			if (x == fx[a] && y == fy[a])
			{
				if (count[a] == 1)
					continue;
				gotoxy(0, 24);
				printf("��ź�̴�!!!\n\nĳ������ ��ġ�� �ʱ�ȭ �˴ϴ�...");
				gotoxy(x, y);
				printf("   ");
				Sleep(2000);
				gotoxy(0, 24);
				printf("\r               \n\n");
				printf("\r                                    \n");
				x = 4;
				y = 2;
				count[a]++;
			}
		}
		//�� ���� ����� ã�� ���
		if (x == fx[6] && y == fy[6])
		{
			if (count[6] == 1)
				continue;
			gotoxy(0, 24);
			printf("�ƹ��͵� ����...");
			Sleep(2000);
			printf("\r                               ");
			count[6]++;
		}
		//��ֹ��� �ε��� ���
		for (a = 1; a < MEDIUM; a++)
		{
			if ((x == fx2[a] || x == fx2[a] + 1 || x + 1 == fx2[a]) && y == fy2[a])
			{
				gotoxy(0, 24);
				printf("��...��ֹ��� �ε�����...");
				Sleep(2000);
				printf("\r                               ");
				switch (ch)
				{
				case 72:
					y++;
					break;
				case 80:
					y--;
					break;
				case 75:
					x+=2;
					break;
				case 77:
					x-=2;
					break;
				}
			}
		}
		//�̵�Ƚ�� �ʰ� �� ����
		if (move >= motion)
		{
			gotoxy(0, 24);
			printf("�ִ� �̵� Ƚ���� �ʰ��߽��ϴ�! �ٽ� �Ͻðڽ��ϱ�? (y or n): ");
			while ((b = getchar()) != 224)
			if (b == 'y')
			{
				(*try)++; //�õ�Ƚ�� ����
				printf("\n�ٽ� �����մϴ�...");
				Sleep(2000);
				system("cls");
				medium(try);
			}
			else if (b == 'n')
			{
				printf("\n�޴��� ���ư��ϴ�...(�õ�Ƚ��: %dȸ)\n\n", *try);
				Sleep(2000);
				system("cls");
				*try = 1;
				main();
			}
		}
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void hard(int *try)
{
	int motion = 90, move = 0; //�ִ� �̵� Ƚ�� ����
	int fx[HARD], fy[HARD]; //��� ��ġ
	int fx2[HARD], fy2[HARD]; //��ֹ� ��ġ
	int count[HARD] = { 0 };//������ ��� Ȯ�ο�
	int ch, a, x = 4, y = 2;
	char b;

	//���� Ʋ
	printf("�âââââââââââââââââââ�\n");
	for (a = 0; a < 20; a++)
		printf("��                                    ��\n");
	printf("�âââââââââââââââââââ�\n");
	
	//������ ��ġ
	fx[0] = 2 * (8 + (rand() % 8)); // x: 16 ~ 30
	fy[0] = (rand() % 11) + 8; // y: 8 ~ 18
	gotoxy(fx[0], fy[0]);
	printf(FLAG_MARK);

	//������ ��ġ (������)
	fx[1] = 2 * (10 + (rand() % 8)); // x: 20 ~ 34
	fy[1] = (rand() % 16) + 3; // y: 3 ~ 18
	gotoxy(fx[1], fy[1]);
	printf(FLAG_MARK);

	//���� ��ġ�� ��ġ (���� �Ʒ�)
	fx[2] = 2 * (2 + (rand() % 6)); // x: 4 ~ 14
	fy[2] = (rand() % 6) + 13; // y: 13 ~ 18
	gotoxy(fx[2], fy[2]);
	printf(FLAG_MARK);

	//�� ���� ���, ��ֹ� (9����)
	for (a = 3; a < HARD ; a++) 
	{
		fx[a] = 2 * (2 + (rand() % 17)); // x: 4 ~ 36
		fy[a] = (rand() % 17) + 3;
		fx2[a] = 2 * (2 + (rand() % 17)); // x: 4 ~ 36
		fy2[a] = (rand() % 17) + 3;
		gotoxy(fx[a], fy[a]);
		printf(FLAG_MARK);
		gotoxy(fx2[a], fy2[a]);
		printf(WALL_MARK);
	}

	//���� ����
	while (1)
	{
		gotoxy(0, 22);
		printf("�̹����� ����� ��, ��ġ�� ã�� �� �������ڸ� ã���� ������!!! (�̵�Ƚ��: %d/%d)", move, motion);
		//���������� ��Ż�� ���
		if ((x < 1) || (x > 37) || (y < 1) || (y > 20))
		{
			gotoxy(0, 24);
			printf("���� ����� �� ��!!!");
			Sleep(1500);
			printf("\r                        ");
			switch (ch)
			{
			case 72:
				y++;
				break;
			case 80:
				y--;
				break;
			case 75:
				x+=2;
				break;
			case 77:
				x-=2;
				break;
			}
		}

		//��ġ �ʱ�ȭ
		gotoxy(x, y);
		printf(PLAYER_MARK);

		//����Ű �̵� 
		ch = _getch();
		if (ch == 224)
			ch = _getch();
		switch (ch)
		{
		case 72:
			printf("\b\b  ");
			y--;
			break;
		case 80:
			printf("\b\b  ");
			y++;
			break;
		case 75:
			printf("\b\b  ");
			x-=2;
			break;
		case 77:
			printf("\b\b  ");
			x+=2;
			break;
		}
		move++; //�̵�Ƚ�� ����

		//������ ã�� ���
		if ((x == fx[0] || x == fx[0] + 1 || x + 1 == fx[0]) && y == fy[0])
		{
			if (count[1] == 1 && count[2] == 1) //���� ���� o
			{
				gotoxy(0, 22);
				printf("\r                                                                                    \r");
				printf("�������ڸ� �� �� �ְ� �ƾ�! ����� �־�!\n\n");
				printf("����� ȹ���ߴ�!\n\n");
				printf("��� ���������� Ŭ�����߽��ϴ�!\n\n");
				Sleep(3000);
				printf("�������� �Ѿ�ϴ�...");
				Sleep(2000);
				system("cls");
				ending(try);
			}
			else //���� ���� x
			{	
				gotoxy(0, 24);
				if (count[1] == 0 && count[2] == 0)
				{
					printf("����� ��, ��ġ�� ã�ƿ;� ��!");
					Sleep(2000);
					printf("\r                                  ");
				}
				if (count[1] > 0 && count[2] == 0)
				{
					printf("���� ��ġ�� ã�ƿ;� ��!");
					Sleep(2000);
					printf("\r                              ");
				}
				if (count[1] == 0 && count[2] > 0)
				{
					printf("���絵 ã�ƿ;� ��!");
					Sleep(2000);
					printf("\r                             ");
				}
				switch (ch) //�ٽ� ����������
				{
				case 72:
					y++;
					break;
				case 80:
					y--;
					break;
				case 75:
					x+=2;
					break;
				case 77:
					x-=2;
					break;
				}
			}	
		}
		//���縦 ���� ���
		if (x == fx[1] && y == fy[1])
		{
			if (count[1] == 1)
				continue;
			gotoxy(0, 24);
			printf("���縦 �����!");
			Sleep(2000);
			printf("\r                         ");
			count[1]++;
		}
		//���� ��ġ�� ���� ���
		if (x == fx[2] && y == fy[2])
		{
			if (count[2] == 1)
				continue;
			gotoxy(0, 24);
			printf("���� ��ġ�� �����!");
			Sleep(2000);
			printf("\r                          ");
			count[2]++;
		}
		//��Ʈ�� ã�� ���
		if (x == fx[3] && y == fy[3])
		{
			if (count[3] == 1)
				continue;
			gotoxy(0, 24);
			printf("��Ʈ�� �����!\n\n");
			printf("��Ʈ: ����� �����ʿ� �ִ�...");
			Sleep(3000);
			gotoxy(0, 24);
			printf("\r                    \n\n");
			printf("\r                                     ");
			count[3]++;
		}
		//��Ʈ�� ã�� ���2
		if (x == fx[4] && y == fy[4])
		{
			if (count[4] == 1)
				continue;
			gotoxy(0, 24);
			printf("��Ʈ�� �����!\n\n");
			printf("��Ʈ: ���� ��ġ�� ���� �Ʒ��� �ִ�...");
			Sleep(3000);
			gotoxy(0, 24);
			printf("\r                    \n\n");
			printf("\r                                     ");
			count[4]++;
		}
		//��ź�� ã�� ���
		for (a = 5; a <= 9; a++)
		{
			if (x == fx[a] && y == fy[a])
			{
				if (count[a] == 1)
					continue;
				gotoxy(0, 24);
				printf("��ź�̴�!!!\n\nĳ������ ��ġ�� �ʱ�ȭ �˴ϴ�...");
				gotoxy(x, y);
				printf("   ");
				Sleep(2000);
				gotoxy(0, 24);
				printf("\r                  \n\n");
				printf("\r                               \n");
				x = 4;
				y = 2;
				count[a]++;
			}
		}
		//�� ���� ����� ã�� ���
		for (a = 10; a <= 11; a++)
		{
			if (x == fx[a] && y == fy[a])
			{
				if (count[a] == 1)
					continue;
				gotoxy(0, 24);
				printf("�ƹ��͵� ����...");
				Sleep(2000);
				printf("\r                               ");
				count[a]++;
			}
		}

		//��ֹ��� �ε��� ���
		for (a = 3; a < HARD; a++)
		{
			if ((x == fx2[a] || x == fx2[a] + 1 || x + 1 == fx2[a]) && y == fy2[a])
			{
				gotoxy(0, 24);
				printf("��...��ֹ��� �ε�����...");
				Sleep(2000);
				printf("\r                                 ");
				switch (ch)
				{
				case 72:
					y++;
					break;
				case 80:
					y--;
					break;
				case 75:
					x+=2;
					break;
				case 77:
					x-=2;
					break;
				}
			}
		}
		//�̵�Ƚ�� �ʰ� �� ����
		if (move >= motion)
		{
			gotoxy(0, 24);
			printf("�ִ� �̵� Ƚ���� �ʰ��߽��ϴ�! �ٽ� �Ͻðڽ��ϱ�? (y or n): ");
			while ((b = getchar()) != 224)
			if (b == 'y')
			{
				(*try)++; //�õ�Ƚ�� ����
				printf("\n�ٽ� �����մϴ�...");
				Sleep(2000);
				system("cls");
				hard(try);
			}
			else if (b == 'n')
			{
				printf("\n�޴��� ���ư��ϴ�...(�õ�Ƚ��: %dȸ)\n\n", *try);
				Sleep(2000);
				system("cls");
				main();
			}
		}
	}
}