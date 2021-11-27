#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10

int rpow(int a, int b);
void cal_pow();
void add_array();
void print_array(int* a, int s);
void add(int* a, int* b, int* c, int s);
void set_array(int* a, int s);

int main()
{
	int a;

	srand((unsigned)time(NULL));

	do {
		printf("1. a�� b�� ���ϱ�\n2. �迭�� ��\n3. ������\n�޴��� �����Ͻÿ�: ");
		scanf("%d", &a);
		printf("\n");	
		switch (a)
		{
		case 1:
			cal_pow();
			break;
		case 2:
			add_array();
			break;
		case 3:
			break;
		default:
			break;
		}
	} while (a != 3);
	
	return 0;
}
void cal_pow()
{
	int x, y;
	printf("���� ���� �� ���� �Է��Ͻÿ�: ");
	scanf("%d %d", &x, &y);
	printf("%d�� %d���� %d�Դϴ�. \n\n", x, y, rpow(x, y));
}
int rpow(int a, int b)
{
	if (b == 0)
		return 1;
	else if (b == 1)
		return a;
	else
		return a * rpow(a, b - 1);
}
void add_array()
{
	int a1[SIZE];
	int a2[SIZE];
	int sum[SIZE] = { 0 };

	set_array(a1, SIZE);
	set_array(a2, SIZE);
	add(sum, a1, a2, SIZE);

	printf("ù ��° �迭:");
	print_array(a1, SIZE);
	printf("�� ��° �迭:");
	print_array(a2, SIZE);
	printf("�� �迭�� ��:");
	print_array(sum, SIZE);
	printf("\n");
}

void print_array(int *a, int s)
{
	int i;
	for (i = 0; i < s; i++)
		printf("%5d", a[i]);
	printf("\n");
}
void add(int* a, int* b, int* c, int s)
{
	int i;
	for (i = 0; i < s; i++)
		a[i] = b[i] + c[i];
}
void set_array(int *a, int s)
{
	int i;
	for (i = 0;i < s; i++)
		a[i] = rand() % 101;
}