#include <stdio.h>
int main()
{
	char ch;
	float a, b;
	do {
		printf("****************************\n");
		printf("A---Add\nS---Subtract\nM---Multiply\nD---Divide\nQ---Quit\n");
		printf("****************************\n");
		printf("연산을 선택하세요: ");

		while ((ch = getchar()) == '\n');

		switch (ch)
		{
		case 'A':
			printf("두 수를 입력하세요: ");
			scanf(" %f %f", &a, &b);
			printf("%.2f + %.2f = %.2f\n", a, b, a + b);				
			break;
		case 'S':
			printf("두 수를 입력하세요: ");
			scanf(" %f %f", &a, &b);
			printf("%.2f - %.2f = %.2f\n", a, b, a - b);				
			break;
		case 'M':
			printf("두 수를 입력하세요: ");
			scanf(" %f %f", &a, &b);
			printf("%.2f * %.2f = %.2f\n", a, b, a * b);
			break;
		case 'D':
			printf("두 수를 입력하세요: ");
			scanf(" %f %f", &a, &b);
			printf("%.2f / %.2f = %.2f\n", a, b, a / b);
			break;
		case 'Q':
			return 0;
		default:
			printf("잘못 입력하였습니다.\n");
			break;
		}
	} while (1);

	return 0;
}