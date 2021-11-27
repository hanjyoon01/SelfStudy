//Programming Practice 1
/*#include <stdio.h>
int main()
{
	int urn[5] = { 100,200,300,400,500 };
	int* ptr1, * ptr2, * ptr3;
	ptr1 = urn;
	ptr2 = &urn[2];
	printf("ptr1 = %p, *ptr1 = %d, &ptr1 = %p\n", ptr1, *ptr1, &ptr1);
	printf("ptr2 = %p, *ptr2 = %d, &ptr2 = %p\n", ptr2, *ptr2, &ptr2);
	ptr3 = ptr1 + 4;
	printf("ptr1 + 4 = %p, *(ptr3) = %d\n", ptr1 + 4, *(ptr3));
	ptr1++;
	printf("ptr1++ = %p, *ptr1 = %d\n", ptr1, *ptr1);
	ptr2--;
	printf("ptr2-- = %p, *ptr2 = %d\n", ptr2, *ptr2);
	printf("ptr2 = %p, ptr1 = %p, ptr2 - ptr1 = %d\n", ptr2, ptr1, ptr2 - ptr1);
	printf("ptr3 = %d, *(ptr3 - 2) = %d\n", *ptr3, *(ptr3 - 2));
	return 0;
}*/

//Lap Assignment 1
/*#include <stdio.h>
void get_int_real(float* a, int* i, float* f);
int main()
{
	int i;
	float a, f;
	printf("실수를 입력하시오: ");
	scanf("%f", &a);
	get_int_real(&a, &i, &f);
	printf("정수부는 %d, 소수점 이하 부분은 %.2f입니다.\n", i, f);
}
void get_int_real(float* a, int *i, float *f)
{
	*i = (int)*a;
	*f = *a - (int)*a;
}*/

//Lap Assignment 2
/*#include <stdio.h>
#define SIZE 32
void dec_to_bin(int i, char binary[], int* p);
int main()
{
	char bin[SIZE];
	int num, count = 0, i;
	printf("양의 정수를 입력하세요: ");
	scanf("%d", &num);
	dec_to_bin(num, bin, &count);
	for (i = count-1; i >= 0; i--)
		printf("%d", bin[i]);
	printf("\n");
	return 0;
}
void dec_to_bin(int i, char binary[], int* p)
{
	while (i >= 2)
	{
		binary[*p] = i % 2;
		i /= 2;
		(*p)++;
	}
	binary[(*p)++] = i;
}*/


