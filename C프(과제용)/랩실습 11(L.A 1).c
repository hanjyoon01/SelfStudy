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
	printf("첫 번째 벡터 A의 x, y값을 입력하세요: ");
	scanf("%lf %lf", &v1.x, &v1.y);
	printf("두 번째 벡터 B의 x, y값을 입력하세요: ");
	scanf("%lf %lf", &v2.x, &v2.y);
	printf("스칼라값 k을 입력하세요: ");
	scanf("%d", &s);
	printf("---------------------\n");
	printf("덧셈 A+B: (%.2lf,%.2lf)\n", v1.x + v2.x, v1.y + v2.y);
	printf("뺄셈 A-B: (%.2lf,%.2lf)\n", v1.x - v2.x, v1.y - v2.y);
	printf("내적 A*B: %.2lf\n", v1.x * v2.x + v1.y * v2.y);
	printf("스칼라곱 k|A|: (%.2lf,%.2lf)\n", s * v1.x, s * v1.y);
	printf("스칼라곱 k|B|: (%.2lf,%.2lf)\n", s * v2.x, s * v2.y);
	printf("A의 크기: %.2lf\n", sqrt(v1.x * v1.x + v1.y * v1.y));
	printf("B의 크기: %.2lf\n", sqrt(v2.x * v2.x + v2.y * v2.y));
}