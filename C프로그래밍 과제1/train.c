//202011390 ������ (0450-02), ����1, �ۼ���:2020.04.26

#include <stdio.h>
int main ()
{
	int space, speed1, speed2, hour, minute, second;
	float time_minute, distance1, distance2;

	printf("�� ���� ������ �Ÿ��� �Է��ϼ���: "); //�� ���� ������ �Ÿ��� �Է¹���
	scanf("%d", &space);
	printf("ù ��° ������ �ӵ�(km/h)�� �Է��ϼ���: "); //ù ��° ������ �ӵ��� �Է¹���
	scanf("%d", &speed1);
	printf("�� ��° ������ �ӵ�(km/h)�� �Է��ϼ���: "); //�� ��° ������ �ӵ��� �Է¹���
	scanf("%d", &speed2);

	time_minute = (float)space / (speed1 + speed2) * 60; //�浹���� �ɸ��� �ð�(�д���)�� ����(�Ÿ��� ����ȯ)
	
	//�� �ð��� (x�ð� x�� x��)�� ���·� ��Ÿ���� ���� ��,��,�� ������ ����
	hour = time_minute / 60;
	minute = time_minute - 60 * hour;
	second = (time_minute - (int)time_minute) * 60;

	//�浹���� �� ������ �̵��� �Ÿ��� ����
	distance1 = (time_minute / 60) * speed1;
	distance2 = (time_minute / 60) * speed2;

	
	printf("�浹���� �� %.3f��(%d�ð� %d�� %d��)�� �ҿ�˴ϴ�.\n", time_minute, hour, minute, second);
	printf("ù ��° ������ ���� �Ÿ��� �� %.2f(km)�Դϴ�.\n", distance1);
	printf("�� ��° ������ ���� �Ÿ��� �� %.2f(km)�Դϴ�.\n", distance2);

	return 0;
}