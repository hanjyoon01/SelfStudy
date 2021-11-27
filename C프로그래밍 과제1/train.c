//202011390 한재윤 (0450-02), 과제1, 작성일:2020.04.26

#include <stdio.h>
int main ()
{
	int space, speed1, speed2, hour, minute, second;
	float time_minute, distance1, distance2;

	printf("두 기차 사이의 거리를 입력하세요: "); //두 기차 사이의 거리를 입력받음
	scanf("%d", &space);
	printf("첫 번째 기차의 속도(km/h)를 입력하세요: "); //첫 번째 기차의 속도를 입력받음
	scanf("%d", &speed1);
	printf("두 번째 기차의 속도(km/h)를 입력하세요: "); //두 번째 기차의 속도를 입력받음
	scanf("%d", &speed2);

	time_minute = (float)space / (speed1 + speed2) * 60; //충돌까지 걸리는 시간(분단위)를 구함(거리값 형변환)
	
	//이 시간을 (x시간 x분 x초)의 형태로 나타내기 위해 시,분,초 단위로 나눔
	hour = time_minute / 60;
	minute = time_minute - 60 * hour;
	second = (time_minute - (int)time_minute) * 60;

	//충돌까지 두 기차가 이동한 거리를 구함
	distance1 = (time_minute / 60) * speed1;
	distance2 = (time_minute / 60) * speed2;

	
	printf("충돌까지 총 %.3f분(%d시간 %d분 %d초)이 소요됩니다.\n", time_minute, hour, minute, second);
	printf("첫 번째 기차의 운행 거리는 총 %.2f(km)입니다.\n", distance1);
	printf("두 번째 기차의 운행 거리는 총 %.2f(km)입니다.\n", distance2);

	return 0;
}