//Lap Assignment 1
/*#include <stdio.h>
#define GRAVITY 9.8
int main()
{
	float m, v, h, EK, EP, EM;

	printf("물체의 질량<g>, 속도<m/s> 및 높이<m>를 입력하세요:");
	scanf("%f %f %f", &m, &v, &h);

	EK = 0.5 * m * v * v;
	EP = m * GRAVITY * h;
	EM = EK + EP;

	printf("운동에너지:%.2f[J]\n위치에너지:%.2f[J]\n역학적에너지:%.2f[J]\n", EK, EP, EM);

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

	printf("평균 속도를 입력하세요(km/h): ");
	scanf("%f", &s);
	printf("주행 거리를 입력하세요(km): ");
	scanf("%f", &d);

	time = d / s;
	ho = time;
	printf("시간 = %f\n", time);
	time *= hour;
	printf("시간(초단위) = %f\n", time);
	mi = ((int)time % hour) / 60;
	se = (int)time % 60;

	printf("총 주행 시간은 %d시간 %d분 %d초입니다.\n", ho, mi, se);

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
	printf("이차방정식 ax^2 + bx + c에서의 a,b,c를 차례로 입력하세요:");
	scanf("%d %d %d", &a, &b, &c);

	a1 = (-b + sqrt((double)(b * b - 4 * a * c))) / (2.0 * a);
	a2 = (-b - sqrt((double)(b * b - 4 * a * c))) / (2.0 * a);

	printf("방정식의 두 근: %.2f, %.2f\n", a1, a2);

	return 0;
}*/
