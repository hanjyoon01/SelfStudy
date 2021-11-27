#include "my.h"
int main()
{
	int n;
	time_t t1 , t2;
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
}