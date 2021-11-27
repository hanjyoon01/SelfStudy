//Lap Assignment 1
#include <stdio.h>
#define HEIGHT 10
#define WIDTH 10
void array_copy(int a[][WIDTH], int b[][WIDTH]);
void array_print(int a[][WIDTH]);
int main()
{
	int score[HEIGHT][WIDTH] = { {100,90,80},{70,60,50},{40,30,20} };
	int tmp[HEIGHT][WIDTH];
	array_copy(tmp, score);
	array_print(tmp);

	return 0;
}

void array_copy(int a[][WIDTH], int b[][WIDTH])
{
	int* p;
	int* endp;
	int* tp;

	p = &b[0][0];
	endp = &b[HEIGHT - 1][WIDTH - 1];
	tp = &a[0][0];

	while (p <= endp)
		*tp++ = *p++;
}
void array_print(int a[][WIDTH])
{
	int count = 0;
	int* p;
	int* endp;
	p = &a[0][0];
	endp = &a[HEIGHT - 1][WIDTH - 1];
	while (p <= endp)
	{
		printf("%5d", *p++); 
		count++;
		if (count == 10)
		{
			printf("\n");
			count = 0;
		}
	}
}*/