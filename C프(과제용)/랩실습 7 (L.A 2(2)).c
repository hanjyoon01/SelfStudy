#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
int set_random();
int decision(int, int);
void print_result(int);
int get_input();

int main()
{
	int computer, user, result;
	char sel;
	while (1)
	{
		computer = set_random();
		user = get_input();
		printf("\ncomputer:%d, user:%d\n", computer, user);
		result = decision(computer, user);
		print_result(result);
		printf("\n\n게임 계속 진행하려면 아무 키나 누르시오. 단, q를 누르면 끝납니다.");
		while ((sel = getchar()) == '\n');

		if (sel == 'q')
			break;
	}

	return 0;
}
int set_random()
{
	srand((unsigned)time(NULL));
	return (rand() % 3);
}
int decision(int x, int y)
{
	if (x == y)
		return (0);
	else if ((x == 2 && y == 0) || (x == 0 && y == 1) || (x == 1 && y == 2))
		return (1);
	else
		return (2);
}
void print_result(int r)
{
	switch (r)
	{
	case 0:
		printf("비겼음");
		break;
	case 1:
		printf("사용자 승리");
		break;
	case 2:
		printf("컴퓨터 승리");
		break;
	}
}
int get_input()
{
	int i;
	do {
		printf("선택하세요(가위:0, 바위:1, 보:2): ");
		scanf("%d", &i);
		if (i != 0 && i != 1 && i != 2)
			printf("다시 입력하세요.\n");
	} while (i != 0 && i != 1 && i != 2);

	return i;
}