//Programming Practice 1
/*#include <stdio.h>
void up_and_down(int n);
int main()
{
	up_and_down(1);
	return 0;
}

void up_and_down(int n)
{
	printf("Level %d before a recursion\n", n);
	if (n < 4)
		up_and_down(n + 1);
	printf("Level %d before a recursion\n", n);
}*/

//Programming Practice 2
/*#include "my.h"
int main()
{
	int n;
	time_t t1, t2;
	printf("정수를 입력하세요: ");
	scanf("%d", &n);
	t1 = time(NULL);
	printf("피보나치 수:%d\n", fib_iter(n));
	t2 = time(NULL);
	printf("반복문 시간:%d\n", t2 - t1);
	t1 = time(NULL);
	printf("피보나치 수:%d\n", fib(n));
	t2 = time(NULL);
	printf("재귀 호출 시간:%d\n", t2 - t1);

	return 0;
}*/

//Lap Assignment 1
/*#include <stdio.h>
void get_dice_face();
int main()
{
	int i;
	printf("주사위 던지기를 시작합니다.\n\n");
	for (i = 0; i < 50; i++)
		get_dice_face();
	return 0;
}

void get_dice_face()
{
	static int d1 = 0, d2 = 0, d3 = 0, d4 = 0, d5 = 0, d6 = 0;
	int n;
	n = (rand() % 6) + 1;
	printf("현재 주사위면: %d\n", n);
	switch (n)
	{
	case 1:
		d1++;
		break;
	case 2:
		d2++;
		break;
	case 3:
		d3++;
		break;
	case 4:
		d4++;
		break;
	case 5:
		d5++;
		break;
	case 6:
		d6++;
		break;
	}
	printf("면별 나온 횟수:\n");
	printf("1:%d, 2:%d, 3:%d, 4:%d, 5:%d, 6:%d\n\n", d1, d2, d3, d4, d5, d6);
}*/

//Lap Assignment 2
/*#include <stdio.h>
void reverse();
int main()
{
	printf("String: ");
	reverse();
	printf("\n");
	return 0;
}
void reverse()
{
	char ch;
	ch = getchar();
	if (ch != '\n')
		reverse();
	printf("%c", ch);
}*/