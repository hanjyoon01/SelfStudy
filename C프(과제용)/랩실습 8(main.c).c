#include "my.h"
int main()
{
	int n;
	time_t t1 , t2;
	printf("������ �Է��ϼ���: ");
	scanf("%d", &n);
	t1 = time(NULL);
	printf("�Ǻ���ġ ��:%d\n", fib_iter(n));
	t2 = time(NULL);
	printf("�ݺ��� �ð�:%d\n", t2 - t1);
	t1 = time(NULL);
	printf("�Ǻ���ġ ��:%d\n", fib(n));
	t2 = time(NULL);
	printf("��� ȣ�� �ð�:%d\n", t2 - t1);
	
	return 0;
}