//Lap Assignment 1
/*#include <stdio.h>
#define GRAVITY 9.8
int main()
{
	float m, v, h, EK, EP, EM;

	printf("��ü�� ����<g>, �ӵ�<m/s> �� ����<m>�� �Է��ϼ���:");
	scanf("%f %f %f", &m, &v, &h);

	EK = 0.5 * m * v * v;
	EP = m * GRAVITY * h;
	EM = EK + EP;

	printf("�������:%.2f[J]\n��ġ������:%.2f[J]\n������������:%.2f[J]\n", EK, EP, EM);

	return 0;
}*/

//Programming Practice 1
/*#include <stdio.h>
int main()
{
	int x;
	double y;

	x = -(2 + 5) * 6 + (4 + 3 * (2 + 3));
	printf("x = %5d\n", x);
	y = 3 + 2 * (x = 7 / 2);
	printf("x = %5d, y = %5.2f\n", x, y);
	x = (int)3.8 + 3.3;
	printf("x = %5d\n", x);
	x = 3 / 5 * 22.0;
	printf("x = %5d\n", x);
	y = (double)(x = 4) * 3 / 5;
	printf("y = %5.2f\n", y);
	y = x * 3 / 5;
	printf("y = %5.2f\n", y);

	return 0;
}*/

//Lap Assignment 2
/*#include <stdio.h>
#define hour 3600
int main()
{
	float s, d;
	float time;
	int ho, mi, se;

	printf("��� �ӵ��� �Է��ϼ���(km/h): ");
	scanf("%f", &s);
	printf("���� �Ÿ��� �Է��ϼ���(km): ");
	scanf("%f", &d);

	time = d / s;
	ho = time;
	printf("�ð� = %f\n", time);
	time *= hour;
	printf("�ð�(�ʴ���) = %f\n", time);
	mi = ((int)time % hour) / 60;
	se = (int)time % 60;

	printf("�� ���� �ð��� %d�ð� %d�� %d���Դϴ�.\n", ho, mi, se);

	return 0;
}*/

//Programming Practice 2
/*#include <stdio.h>
#include <math.h>
int main()
{
	double a = 2;
	double b = 16;
	int c = -3;

	printf("square root of a is %.2lf.\n", sqrt(a));
	printf("b^a is %.0lf.\n", pow(b, a));
	printf("absolute value of c is %d.\n", abs(c));
	printf("log(b)is %.2lf.\n", log(b));

	return 0;
}*/

//Lap Assignment 3
/*#include <stdio.h>
#include <math.h>
int main()
{
	int a, b, c;
	float a1, a2;
	printf("���������� ax^2 + bx + c������ a,b,c�� ���ʷ� �Է��ϼ���:");
	scanf("%d %d %d", &a, &b, &c);

	a1 = (-b + sqrt((double)(b * b - 4 * a * c))) / (2.0 * a);
	a2 = (-b - sqrt((double)(b * b - 4 * a * c))) / (2.0 * a);

	printf("�������� �� ��: %.2f, %.2f\n", a1, a2);

	return 0;
}*/
