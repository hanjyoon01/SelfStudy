//Lap Assignment 1
#include <stdio.h>
#include <math.h>
struct vector {
	double x;
	double y;
};
int main()
{
	struct vector v1;
	struct vector v2;
	int s;
	printf("ù ��° ���� A�� x, y���� �Է��ϼ���: ");
	scanf("%lf %lf", &v1.x, &v1.y);
	printf("�� ��° ���� B�� x, y���� �Է��ϼ���: ");
	scanf("%lf %lf", &v2.x, &v2.y);
	printf("��Į�� k�� �Է��ϼ���: ");
	scanf("%d", &s);
	printf("---------------------\n");
	printf("���� A+B: (%.2lf,%.2lf)\n", v1.x + v2.x, v1.y + v2.y);
	printf("���� A-B: (%.2lf,%.2lf)\n", v1.x - v2.x, v1.y - v2.y);
	printf("���� A*B: %.2lf\n", v1.x * v2.x + v1.y * v2.y);
	printf("��Į��� k|A|: (%.2lf,%.2lf)\n", s * v1.x, s * v1.y);
	printf("��Į��� k|B|: (%.2lf,%.2lf)\n", s * v2.x, s * v2.y);
	printf("A�� ũ��: %.2lf\n", sqrt(v1.x * v1.x + v1.y * v1.y));
	printf("B�� ũ��: %.2lf\n", sqrt(v2.x * v2.x + v2.y * v2.y));
}