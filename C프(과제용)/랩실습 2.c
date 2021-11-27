/*#include <stdio.h>
int main()
{
	int f;
	float c;

	printf("화씨 온도를 입력하세요: ");
	scanf("%d", &f);

	c = 5.0 / 9.0 * (f - 32);

	printf("섭씨 온도는 %.2lf도 입니다.", c);

	return 0;
}*/

/*#include <stdio.h>
int main()
{
	int pages = 931;

	printf("*%d*\n", pages); // 정수 그대로 표시
	printf("*%2d*\n", pages); // 전체 2칸, 오른쪽 맞춤, 무시됨
	printf("*%10d*\n", pages); // 전체 10칸, 오른쪽 맞춤
	printf("*%-10d*\n", pages); // 전체 10칸, 왼쪽 맞춤
	printf("*%+d*\n", pages); // 숫자의 부호 표시

	return 0;
}*/

/*#include <stdio.h>
int main()
{
	float rent = 3852.99;

	printf("*%f*\n", rent); // 소수점아래 6자리까지 표시 (기본)
	printf("*%e*\n", rent); // 지수표기법으로 출력 (소수점 이동), 소수점 아래 6자리까지 표시
	printf("*%4.2f*\n", rent); // 전체 4칸, 소수점 아래 2자리까지 표시, 무시됨
	printf("*%13.1f*\n", rent); // 전체 13칸, 소수점 아래 둘째자리에서 반올림해 표시
	printf("*%10.3e*\n", rent); // 지수표기법으로 출력 (소수점 이동), 소수점 아래 3자리까지 표시
	printf("*%+4.2f*\n", rent); // 숫자의 부호 표시
	printf("*%019.2f*\n", rent); // 전체 19칸 (빈 칸은 0으로 표시), 소수점 아래 2자리까지 표시

	return 0;
}*/
