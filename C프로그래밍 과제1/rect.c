//202011390 한재윤 (0450-02), 과제1, 작성일:2020.04.16

#include <stdio.h>
int main()
{
	int r_width, r_length, t_width, t_length, t_space, t_people;
	int w_number, l_number, total_people;

	printf("방의 가로와 세로의 길이를 차례로 입력하시오(m): "); //방의 가로와 세로의 길이를 입력받음
	scanf("%d %d", &r_width, &r_length);
	printf("테이블의 가로와 세로의 길이를 차례로 입력하시오(m): "); //테이블의 가로와 세로의 길이를 입력받음
	scanf("%d %d", &t_width, &t_length);
	printf("테이블 간의 간격을 입력하시오(m): "); //테이블 간 간격의 길이를 입력받음
	scanf("%d", &t_space);
	printf("테이블 당 하객 수를 입력하시오: "); //테이블 당 하객의 수를 입력받음
	scanf("%d", &t_people);

	// 방과 테이블의 가로 길이를 고려했을 때 가로로 놓을 수 있는 테이블의 수를 구함
	w_number = (r_width - t_space) / (t_width + t_space);

	// 방과 테이블의 세로 길이를 고려했을 때 세로로 놓을 수 있는 테이블의 수를 구함
	l_number = (r_length - t_space) / (t_length + t_space);

	//총 하객수 = 가로 테이블 수 * 세로 테이블 수 * 테이블 당 하객수
	total_people = w_number * l_number * t_people;

	printf("수용 가능 인원은 총 %d명입니다.\n", total_people);

	return 0;
}