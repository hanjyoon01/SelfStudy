//202011390 ������ (0450-02), ����1, �ۼ���:2020.04.16

#include <stdio.h>
int main()
{
	int r_width, r_length, t_width, t_length, t_space, t_people;
	int w_number, l_number, total_people;

	printf("���� ���ο� ������ ���̸� ���ʷ� �Է��Ͻÿ�(m): "); //���� ���ο� ������ ���̸� �Է¹���
	scanf("%d %d", &r_width, &r_length);
	printf("���̺��� ���ο� ������ ���̸� ���ʷ� �Է��Ͻÿ�(m): "); //���̺��� ���ο� ������ ���̸� �Է¹���
	scanf("%d %d", &t_width, &t_length);
	printf("���̺� ���� ������ �Է��Ͻÿ�(m): "); //���̺� �� ������ ���̸� �Է¹���
	scanf("%d", &t_space);
	printf("���̺� �� �ϰ� ���� �Է��Ͻÿ�: "); //���̺� �� �ϰ��� ���� �Է¹���
	scanf("%d", &t_people);

	// ��� ���̺��� ���� ���̸� ������� �� ���η� ���� �� �ִ� ���̺��� ���� ����
	w_number = (r_width - t_space) / (t_width + t_space);

	// ��� ���̺��� ���� ���̸� ������� �� ���η� ���� �� �ִ� ���̺��� ���� ����
	l_number = (r_length - t_space) / (t_length + t_space);

	//�� �ϰ��� = ���� ���̺� �� * ���� ���̺� �� * ���̺� �� �ϰ���
	total_people = w_number * l_number * t_people;

	printf("���� ���� �ο��� �� %d���Դϴ�.\n", total_people);

	return 0;
}