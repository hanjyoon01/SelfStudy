//Programming Practice 1
/*#include <stdio.h>
int main()
{
	int x, y;
	printf("�� ���� ������ �Է��ϼ���: ");
	scanf("%d %d", &x, &y);
	if (x == 0)
	if (y == 0)
		printf("�� ���� ��� 0�Դϴ�.");
	else
		printf("�� �� �ϳ��� 1�Դϴ�.");

	return 0;
}*/

//Lap Assignment 1 (��ø if��)
/*#include <stdio.h>
int main()
{
	int x, y;
	printf("�� ���� ������ �Է��ϼ���(x,y): ");
	scanf("%d %d", &x, &y);

	if (x == 0)
	{
		if (y == 0)
			printf("�� ���� ��� 0�Դϴ�.\n");
		else
			printf("x�� 0�̰�, y�� 0�� �ƴմϴ�.\n");
	}
	else
	{
		if (y == 0)
			printf("x�� 0�� �ƴϰ�, y�� 0�Դϴ�.\n");
		else
			printf("�� ���� ��� 0�� �ƴմϴ�.\n");
	}

	return 0;
}*/

//Lap Assignment 1 (if-else if��)
/*#include <stdio.h>
int main()
{
	int x, y;
	
	printf("�� ���� ������ �Է��ϼ���(x,y): ");
	scanf("%d %d", &x, &y);

	if (x == 0 && y == 0)
		printf("�� ���� ��� 0�Դϴ�.\n");
	else if (x == 0 && y != 0)
		printf("x�� 0�̰�, y�� 0�� �ƴմϴ�.\n");
	else if (x != 0 && y == 0)
		printf("x�� 0�� �ƴϰ�, y�� 0�Դϴ�.\n");
	else
		printf("�� ���� ��� 0�� �ƴմϴ�.\n");
	
	return 0;
}*/

//Lap Assignment 2
/*#include <stdio.h>
int main()
{
	char ch;

	printf("���ڸ� �Է��ϼ���: ");
	scanf("%c", &ch);

	if (ch >= 'a' && ch <= 'z')
	{
		if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
			printf("%c�� �����Դϴ�.\n", ch);
		else
			printf("%c�� �����Դϴ�.\n", ch);
	}
	else
		printf("%c�� ���ĺ� �ҹ��ڰ� �ƴմϴ�.\n", ch);

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
	printf("�ٹ� �ð��� �Է��ϼ���(�ð� ����): ");
	scanf("%d", &hour);
	if (hour <= 30)
	{
		total = hour * pay;
		printf("�ִ� �� �ӱ�: %d��\n", total);
		if (total > 100000)
		{
			printf("�ֱ��� 10���� �ʰ��� 5%% ���� ����, ����:%d��\n\n", (int)(total * tax_rate_over));
			printf("�Ǽ��ɾ�: %d��\n", (int)(total * (1 - tax_rate_over)));
		}
		else
		{
			printf("�ֱ��� 10���� ���Ϸ� 3%% ���� ����, ����:%d��\n\n", (int)(total * tax_rate_under));
			printf("�Ǽ��ɾ�: %d��\n", (int)(total * (1 - tax_rate_under)));
		}
	}
	else
	{
		total = pay * 30 + pay_over * (hour - 30);
		printf("�⺻ �ֱ�: %d��\n", pay * 30);
		printf("�ʰ� ����: %d�ð�, %d��\n", hour - 30, pay_over * (hour - 30));
		printf("�ִ� �� �ӱ�: %d��\n\n", total);
		printf("�ֱ��� 10���� �ʰ��� 5%% ���� ����, ����:%d��\n\n", (int)(total * tax_rate_over));
		printf("�Ǽ��ɾ�: %d��\n", (int)(total * (1 - tax_rate_over)));
	}	
	return 0;
}*/

//Lap Assignment 4
/*#include <stdio.h>
int main()
{
	char c;
	
	printf("���ڸ� �Է��ϼ���: ");
	scanf("%c", &c);

	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		if (c >= 'a' && c <= 'z')
		{
			printf("%c -> �빮��: %c\n", c, 'A' + (c - 'a'));
		}
		else
		{
			printf("%c -> �ƽ�Ű �ڵ�: %d\n", c, c);
		}
	}
	else
		printf("%c -> ���ĺ��� �ƴմϴ�.\n", c);

	return 0;
}*/