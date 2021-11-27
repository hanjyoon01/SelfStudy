#include "header.h"
int main()
{
	// 시나리오 선택하기
	int a; // 조건문 사용 용도
	int count = 1; //시도횟수
	srand((unsigned)time(NULL));
	//스테이지 선택
	printf("\n★보물 찾기★\n\n스테이지를 선택하세요(1:초반(초급) 2:중반(중급) 3:후반(상급) 4:프로그램 종료): ");
	scanf("%d", &a);
	if (a == 4)
	{
		printf("\n게임을 종료합니다...\n\n");
		return 0;
	}
	printf("\n보물 찾기 게임을 시작합니다...");
	Sleep(1500);
	system("cls");
	// 2.게임 진행하기
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
	int motion = 45, move = 0; //최대 이동 횟수 설정
	int fx[EASY], fy[EASY]; //깃발 위치
	int count[EASY] = { 0 }; //지나간 깃발 확인용
	int ch, a, x = 4, y = 2;
	char b;
	
	//게임 틀
	printf("▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣\n");
	for (a = 0; a < 20; a++)
		printf("▣                                    ▣\n");
	printf("▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣\n");

	//보물 위치 (오른쪽 아래)
	fx[0] = 2*(12+(rand() % 6)); //24 ~ 34
	fy[0] = (rand() % 12) + 6; //6 ~ 17
	gotoxy(fx[0], fy[0]);
	printf(FLAG_MARK);

	//그 외의 깃발 (5개)
	for (a = 1; a < EASY; a++)
	{
		fx[a] = 2 * (2 + (rand() % 16)); // 4 ~ 34
		fy[a] = (rand() % 17) + 3; // 3 ~ 19
		gotoxy(fx[a], fy[a]);
		printf(FLAG_MARK);
	}

	//게임 진행
	while (1)
	{
		gotoxy(0, 22);
		printf("나침반을 찾아야해!!! (이동횟수: %d/%d)", move, motion);
		//스테이지를 이탈할 경우
		if ((x < 1) || (x > 37) || (y < 1) || (y > 20))
		{
			gotoxy(0, 24);
			printf("섬을 벗어나면 안 돼!!!");
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

		//위치 초기화
		gotoxy(x, y);
		printf(PLAYER_MARK);

		//방향키 이동 
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
		move++; //이동횟수 증가

		//보물을 찾은 경우
		if (x == fx[0] && y == fy[0])
		{
			gotoxy(0, 24);
			printf("상자를 찾았다! 상자안에 나침반이 있어!\n\n");
			printf("나침반을 획득했다!\n\n");
			printf("다음 단계로 넘어가겠습니까? (y or n): ");
			while ((b = getchar()) != 224)
			if (b == 'y') //다음 단계 
			{
				printf("\n다음 단계로 넘어갑니다...");
				Sleep(3000);
				system("cls");
				scenario_1(try); //중급 단계
			}
			else if (b == 'n') //게임 종료
			{
				printf("\n메뉴로 돌아갑니다...(시도횟수: %d회)\n\n", *try);
				Sleep(2000);
				system("cls");
				*try = 1;
				main();
			}
		}
		//그 외의 깃발을 찾은 경우
		for (a = 1; a <= 2; a++)
		{
			if (x == fx[a] && y == fy[a])
			{
				if (count[a] == 1)
					continue;
				gotoxy(0, 24);
				printf("폭탄이다!!!\n\n캐릭터의 위치가 초기화 됩니다...");
				gotoxy(x, y);
				printf("   ");
				Sleep(2000);
				gotoxy(0, 24);
				printf("\r               \n\n");
				printf("\r                                    \n");
				// 캐릭터 위치 초기화
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
				printf("아무것도 없네...");
				Sleep(2000);
				printf("\r                               ");
				count[a]++;
			}
		}
		//이동횟수 초과 시 선택
		if (move >= motion)
		{
			gotoxy(0, 24);
			printf("최대 이동 횟수를 초과했습니다! 다시 하시겠습니까? (y or n): ");
			while ((b = getchar()) != 224)
			if (b == 'y')
			{
				(*try)++; //시도횟수 증가
				printf("\n다시 시작합니다...");
				Sleep(2000);
				system("cls");
				easy(try);
			}
			else if (b == 'n')
			{
				printf("\n메뉴로 돌아갑니다...(시도횟수: %d회)\n\n", *try);
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
	int motion = 50, move = 0; //최대 이동 횟수 설정
	int fx[MEDIUM], fy[MEDIUM]; //깃발 위치
	int fx2[MEDIUM], fy2[MEDIUM]; //장애물 위치
	int count[MEDIUM] = { 0 }; //지나간 깃발 확인용
	int ch, a, x = 4, y = 2;
	char b;

	//게임 틀
	printf("▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣\n");
	for (a = 0; a < 20; a++)
		printf("▣                                    ▣\n");
	printf("▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣\n");

	//보물 위치 (아래쪽)
	fx[0] = 2 * (3 + (rand() % 15)); //6 ~ 34
	fy[0] = (rand() % 5) + 15; //15 ~ 19
	gotoxy(fx[0], fy[0]);
	printf(FLAG_MARK);

	//그 외 깃발, 장애물 (6개씩)
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

	//게임 진행
	while (1)
	{
		gotoxy(0, 22);
		printf("이동횟수: %d/%d", move, motion);
		//스테이지를 이탈할 경우
		if ((x < 1) || (x > 37) || (y < 1) || (y > 20))
		{
			gotoxy(0, 24);
			printf("섬을 벗어나면 안 돼!!!");
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

		//위치 초기화
		gotoxy(x, y);
		printf(PLAYER_MARK);

		//방향키 이동 
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
		move++; //이동횟수 증가

		//보물을 찾은 경우
		if (x == fx[0] && y == fy[0])
		{
			gotoxy(0, 24);
			printf("상자를 찾았다! 안에 지도가 있어!\n\n");
			printf("지도를 획득했다!\n\n");
			printf("다음 단계로 넘어가겠습니까? (y or n): ");
			while ((b = getchar()) != 224)
			if (b == 'y')
			{
				printf("\n다음 단계로 넘어갑니다...");
				Sleep(3000);
				system("cls");
				scenario_2(try);
			}
			else if (b == 'n')
			{
				printf("\n메뉴로 돌아갑니다...(시도횟수: %d회)\n\n", *try);
				Sleep(2000);
				system("cls");
				*try = 1;
				main();
			}
		}
		//힌트를 찾은 경우
		if (x == fx[1] && y == fy[1])
		{
			if (count[1] == 1)
				continue;
			gotoxy(0, 24);
			printf("힌트를 얻었어!\n\n");
			printf("힌트: 상자는 아래쪽에 있다...");
			Sleep(3000);
			gotoxy(0, 24);
			printf("\r                    \n\n");
			printf("\r                                 \n");
			count[1]++;
		}
		//폭탄을 찾은 경우
		for (a = 2; a <= 5; a++)
		{
			if (x == fx[a] && y == fy[a])
			{
				if (count[a] == 1)
					continue;
				gotoxy(0, 24);
				printf("폭탄이다!!!\n\n캐릭터의 위치가 초기화 됩니다...");
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
		//그 외의 깃발을 찾은 경우
		if (x == fx[6] && y == fy[6])
		{
			if (count[6] == 1)
				continue;
			gotoxy(0, 24);
			printf("아무것도 없네...");
			Sleep(2000);
			printf("\r                               ");
			count[6]++;
		}
		//장애물에 부딪힌 경우
		for (a = 1; a < MEDIUM; a++)
		{
			if ((x == fx2[a] || x == fx2[a] + 1 || x + 1 == fx2[a]) && y == fy2[a])
			{
				gotoxy(0, 24);
				printf("으...장애물에 부딪혔어...");
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
		//이동횟수 초과 시 선택
		if (move >= motion)
		{
			gotoxy(0, 24);
			printf("최대 이동 횟수를 초과했습니다! 다시 하시겠습니까? (y or n): ");
			while ((b = getchar()) != 224)
			if (b == 'y')
			{
				(*try)++; //시도횟수 증가
				printf("\n다시 시작합니다...");
				Sleep(2000);
				system("cls");
				medium(try);
			}
			else if (b == 'n')
			{
				printf("\n메뉴로 돌아갑니다...(시도횟수: %d회)\n\n", *try);
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
	int motion = 90, move = 0; //최대 이동 횟수 설정
	int fx[HARD], fy[HARD]; //깃발 위치
	int fx2[HARD], fy2[HARD]; //장애물 위치
	int count[HARD] = { 0 };//지나간 깃발 확인용
	int ch, a, x = 4, y = 2;
	char b;

	//게임 틀
	printf("▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣\n");
	for (a = 0; a < 20; a++)
		printf("▣                                    ▣\n");
	printf("▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣\n");
	
	//보물의 위치
	fx[0] = 2 * (8 + (rand() % 8)); // x: 16 ~ 30
	fy[0] = (rand() % 11) + 8; // y: 8 ~ 18
	gotoxy(fx[0], fy[0]);
	printf(FLAG_MARK);

	//목재의 위치 (오른쪽)
	fx[1] = 2 * (10 + (rand() % 8)); // x: 20 ~ 34
	fy[1] = (rand() % 16) + 3; // y: 3 ~ 18
	gotoxy(fx[1], fy[1]);
	printf(FLAG_MARK);

	//못과 망치의 위치 (왼쪽 아래)
	fx[2] = 2 * (2 + (rand() % 6)); // x: 4 ~ 14
	fy[2] = (rand() % 6) + 13; // y: 13 ~ 18
	gotoxy(fx[2], fy[2]);
	printf(FLAG_MARK);

	//그 외의 깃발, 장애물 (9개씩)
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

	//게임 진행
	while (1)
	{
		gotoxy(0, 22);
		printf("이번에는 목재와 못, 망치를 찾은 후 보물상자를 찾으러 가야해!!! (이동횟수: %d/%d)", move, motion);
		//스테이지를 이탈할 경우
		if ((x < 1) || (x > 37) || (y < 1) || (y > 20))
		{
			gotoxy(0, 24);
			printf("섬을 벗어나면 안 돼!!!");
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

		//위치 초기화
		gotoxy(x, y);
		printf(PLAYER_MARK);

		//방향키 이동 
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
		move++; //이동횟수 증가

		//보물을 찾은 경우
		if ((x == fx[0] || x == fx[0] + 1 || x + 1 == fx[0]) && y == fy[0])
		{
			if (count[1] == 1 && count[2] == 1) //조건 충족 o
			{
				gotoxy(0, 22);
				printf("\r                                                                                    \r");
				printf("보물상자를 열 수 있게 됐어! 깃발이 있어!\n\n");
				printf("깃발을 획득했다!\n\n");
				printf("모든 스테이지를 클리어했습니다!\n\n");
				Sleep(3000);
				printf("엔딩으로 넘어갑니다...");
				Sleep(2000);
				system("cls");
				ending(try);
			}
			else //조건 충족 x
			{	
				gotoxy(0, 24);
				if (count[1] == 0 && count[2] == 0)
				{
					printf("목재와 못, 망치를 찾아와야 해!");
					Sleep(2000);
					printf("\r                                  ");
				}
				if (count[1] > 0 && count[2] == 0)
				{
					printf("못과 망치도 찾아와야 해!");
					Sleep(2000);
					printf("\r                              ");
				}
				if (count[1] == 0 && count[2] > 0)
				{
					printf("목재도 찾아와야 해!");
					Sleep(2000);
					printf("\r                             ");
				}
				switch (ch) //다시 돌려보내기
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
		//목재를 얻을 경우
		if (x == fx[1] && y == fy[1])
		{
			if (count[1] == 1)
				continue;
			gotoxy(0, 24);
			printf("목재를 얻었어!");
			Sleep(2000);
			printf("\r                         ");
			count[1]++;
		}
		//못과 망치를 얻을 경우
		if (x == fx[2] && y == fy[2])
		{
			if (count[2] == 1)
				continue;
			gotoxy(0, 24);
			printf("못과 망치를 얻었어!");
			Sleep(2000);
			printf("\r                          ");
			count[2]++;
		}
		//힌트를 찾은 경우
		if (x == fx[3] && y == fy[3])
		{
			if (count[3] == 1)
				continue;
			gotoxy(0, 24);
			printf("힌트를 얻었어!\n\n");
			printf("힌트: 목재는 오른쪽에 있다...");
			Sleep(3000);
			gotoxy(0, 24);
			printf("\r                    \n\n");
			printf("\r                                     ");
			count[3]++;
		}
		//힌트를 찾은 경우2
		if (x == fx[4] && y == fy[4])
		{
			if (count[4] == 1)
				continue;
			gotoxy(0, 24);
			printf("힌트를 얻었어!\n\n");
			printf("힌트: 못과 망치는 왼쪽 아래에 있다...");
			Sleep(3000);
			gotoxy(0, 24);
			printf("\r                    \n\n");
			printf("\r                                     ");
			count[4]++;
		}
		//폭탄을 찾은 경우
		for (a = 5; a <= 9; a++)
		{
			if (x == fx[a] && y == fy[a])
			{
				if (count[a] == 1)
					continue;
				gotoxy(0, 24);
				printf("폭탄이다!!!\n\n캐릭터의 위치가 초기화 됩니다...");
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
		//그 외의 깃발을 찾은 경우
		for (a = 10; a <= 11; a++)
		{
			if (x == fx[a] && y == fy[a])
			{
				if (count[a] == 1)
					continue;
				gotoxy(0, 24);
				printf("아무것도 없네...");
				Sleep(2000);
				printf("\r                               ");
				count[a]++;
			}
		}

		//장애물에 부딪힌 경우
		for (a = 3; a < HARD; a++)
		{
			if ((x == fx2[a] || x == fx2[a] + 1 || x + 1 == fx2[a]) && y == fy2[a])
			{
				gotoxy(0, 24);
				printf("으...장애물에 부딪혔어...");
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
		//이동횟수 초과 시 선택
		if (move >= motion)
		{
			gotoxy(0, 24);
			printf("최대 이동 횟수를 초과했습니다! 다시 하시겠습니까? (y or n): ");
			while ((b = getchar()) != 224)
			if (b == 'y')
			{
				(*try)++; //시도횟수 증가
				printf("\n다시 시작합니다...");
				Sleep(2000);
				system("cls");
				hard(try);
			}
			else if (b == 'n')
			{
				printf("\n메뉴로 돌아갑니다...(시도횟수: %d회)\n\n", *try);
				Sleep(2000);
				system("cls");
				main();
			}
		}
	}
}