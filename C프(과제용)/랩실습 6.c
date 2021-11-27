//Lap Assignment 1-1
/*#include <stdio.h>
int main()
{	
	int num, sum = 0, i;

	printf("정수를 입력하세요: ");
	scanf("%d", &num);

	for (i = 1; i <= num; i++)
	{
		if (i < num)
			printf("%d + ", i * i + 1);
		else
			printf("%d = ", i * i + 1);

		sum += (i * i + 1);
	}
	printf("%d\n", sum);

	return 0;
}*/

//Lap Assignment 1-2
/*#include <stdio.h>
int main()
{
	int num;
	int i;
	printf("양의 정수를 입력하세요: ");
	scanf("%d", &num);
	
	while (num >= 1)
	{
		printf("%d", num % 10);
		num /= 10;
	}
	printf("\n");

	return 0;
}*/

//Programming Practice 1-1
/*#include <stdio.h>
int main()
{
	char ch;
	scanf("%c", &ch);

	while(ch != 'g')
	{
		printf("%c", ch);
		scanf("%c", &ch);
	}

	return 0;
}*/

//Programming Practice 1-2
/*#include <stdio.h>
int main()
{
	char ch;
	scanf("%c", &ch);

	while (ch != 'g')
	{
		printf("%c",++ch);
		scanf("%c", &ch);
	}

	return 0;
}*/

//Programming Practice 2
/*#include <stdio.h>
int main()
{
	int evil1, evil2;
	char ch;

	do
	{
		printf("Enter a pair of integers:\n");
		scanf("%d %d", &evil1, &evil2);
		printf("The lesser of %d and %d is %d.\n", evil1, evil2, (evil1 < evil2) ? evil1 : evil1);
		printf("Press \'y\' to continue, or \'q\'to quit.");
		ch = getchar();
	} while (ch == 'y');
	
	printf("Bye.\n");
	
	return 0;
}*/

//Programming Practice 3
/*#include <stdio.h>
int main()
{
	const int ROWS = 6;
	const int CHARS = 6;
	int row;
	char ch;

	for (row = 0; row < ROWS; row++)
	{
		for (ch = ('A' + row); ch < ('A' + CHARS); ch++)
			printf("%c", ch);
		printf("\n");
	}

	return 0;
}*/

//Lap Assignment 2
/*#include <stdio.h>
int main()
{
	char ch;
	float a, b;
	do {
		printf("****************************\n");
		printf("A---Add\nS---Subtract\nM---Multiply\nD---Divide\nQ---Quit\n");
		printf("****************************\n");
		printf("연산을 선택하세요: ");

		while((ch = getchar()) == '\n');
		
		if (ch == 'A' || ch == 'S' || ch == 'M' || ch == 'D')
		{
			printf("두 수를 입력하세요: ");
			scanf(" %f %f", &a, &b);
			switch (ch)
			{
			case 'A':
				printf("%.2f + %.2f = %.2f\n", a, b, a + b);
				break;
			case 'S':
				printf("%.2f - %.2f = %.2f\n", a, b, a - b);
				break;
			case 'M':
				printf("%.2f * %.2f = %.2f\n", a, b, a * b);
				break;
			case 'D':
				printf("%.2f / %.2f = %.2f\n", a, b, a / b);
				break;
			}
		}
		else if (ch == 'Q')
		{
			break;
		}
		else
		{
			printf("잘못 입력하였습니다.\n");
		}
	} while (1);

	return 0;
}*/

//Lap Assignment 3
/*#include <stdio.h>
int main()
{
	const int ROWS = 6;
	const int CHARS = 6;
	int row;
	char ch;

	for (row = 0; row < ROWS; row++)
	{
		for (ch = 'F'; ch > 'F' - (row + 1); ch--)
			printf("%c", ch);
		printf("\n");
	}

	return 0;
}*/