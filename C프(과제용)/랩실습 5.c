//Programming Practice 1
/*#include <stdio.h>
int main()
{
	int x, y;
	printf("두 개의 정수를 입력하세요: ");
	scanf("%d %d", &x, &y);
	if (x == 0)
	if (y == 0)
		printf("두 수는 모두 0입니다.");
	else
		printf("둘 중 하나는 1입니다.");

	return 0;
}*/

//Lap Assignment 1 (중첩 if문)
/*#include <stdio.h>
int main()
{
	int x, y;
	printf("두 개의 정수를 입력하세요(x,y): ");
	scanf("%d %d", &x, &y);

	if (x == 0)
	{
		if (y == 0)
			printf("두 수는 모두 0입니다.\n");
		else
			printf("x는 0이고, y는 0이 아닙니다.\n");
	}
	else
	{
		if (y == 0)
			printf("x는 0이 아니고, y는 0입니다.\n");
		else
			printf("두 수는 모두 0이 아닙니다.\n");
	}

	return 0;
}*/

//Lap Assignment 1 (if-else if문)
/*#include <stdio.h>
int main()
{
	int x, y;
	
	printf("두 개의 정수를 입력하세요(x,y): ");
	scanf("%d %d", &x, &y);

	if (x == 0 && y == 0)
		printf("두 수는 모두 0입니다.\n");
	else if (x == 0 && y != 0)
		printf("x는 0이고, y는 0이 아닙니다.\n");
	else if (x != 0 && y == 0)
		printf("x는 0이 아니고, y는 0입니다.\n");
	else
		printf("두 수는 모두 0이 아닙니다.\n");
	
	return 0;
}*/

//Lap Assignment 2
/*#include <stdio.h>
int main()
{
	char ch;

	printf("문자를 입력하세요: ");
	scanf("%c", &ch);

	if (ch >= 'a' && ch <= 'z')
	{
		if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
			printf("%c는 모음입니다.\n", ch);
		else
			printf("%c는 자음입니다.\n", ch);
	}
	else
		printf("%c는 알파벳 소문자가 아닙니다.\n", ch);

	return 0;
}*/

//Lap Assignment 3
/*#include <stdio.h>
#define pay 8350
#define pay_over 10020
#define tax_rate_over 0.05
#define tax_rate_under 0.03
int main()
{
	int hour;
	int total;
	printf("근무 시간을 입력하세요(시간 단위): ");
	scanf("%d", &hour);
	if (hour <= 30)
	{
		total = hour * pay;
		printf("주당 총 임금: %d원\n", total);
		if (total > 100000)
		{
			printf("주급이 10만원 초과로 5%% 세율 적용, 세액:%d원\n\n", (int)(total * tax_rate_over));
			printf("실수령액: %d원\n", (int)(total * (1 - tax_rate_over)));
		}
		else
		{
			printf("주급이 10만원 이하로 3%% 세율 적용, 세액:%d원\n\n", (int)(total * tax_rate_under));
			printf("실수령액: %d원\n", (int)(total * (1 - tax_rate_under)));
		}
	}
	else
	{
		total = pay * 30 + pay_over * (hour - 30);
		printf("기본 주급: %d원\n", pay * 30);
		printf("초과 수당: %d시간, %d원\n", hour - 30, pay_over * (hour - 30));
		printf("주당 총 임금: %d원\n\n", total);
		printf("주급이 10만원 초과로 5%% 세율 적용, 세액:%d원\n\n", (int)(total * tax_rate_over));
		printf("실수령액: %d원\n", (int)(total * (1 - tax_rate_over)));
	}	
	return 0;
}*/

//Lap Assignment 4
/*#include <stdio.h>
int main()
{
	char c;
	
	printf("문자를 입력하세요: ");
	scanf("%c", &c);

	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		if (c >= 'a' && c <= 'z')
		{
			printf("%c -> 대문자: %c\n", c, 'A' + (c - 'a'));
		}
		else
		{
			printf("%c -> 아스키 코드: %d\n", c, c);
		}
	}
	else
		printf("%c -> 알파벳이 아닙니다.\n", c);

	return 0;
}*/