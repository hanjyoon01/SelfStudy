//3����

/*#include <stdio.h>
int main()
{
	int pages = 931;

	printf("*%d*\n", pages);
	printf("*%2d*\n", pages);
	printf("*%10d*\n", pages);
	printf("*%-10d*\n", pages);
	printf("*%+d*\n", pages);

	return 0;
}*/

/*#include <stdio.h>
int main()
{
	float rent=3852.99;

	printf("*%f*\n", rent);
	printf("*%e*\n", rent);
	printf("*%4.2f*\n", rent);
	printf("*%13.1f*\n", rent);
	printf("*%10.3e*\n", rent);
	printf("*%+4.2f*\n", rent);
	printf("*%019.2f*\n", rent);
	

	return 0;
}*/

/*#include <stdio.h>
int main()
{
	int f = 78;
	float c;

	c = 5.0 / 9.0 * (f - 32);

	printf("%.2f\n", c);

	return 0;
}*/

/*#include <stdio.h>
int main()
{
	int a;
	scanf("%d", &a);

	int b;
	scanf("%d", &b);

	int sum = a + b;

	printf("%d", sum);

	return 0;
}*/

/*#include <stdio.h>
int main()
{
	int a, b;
	a = 1;
	b = 2;
	int sum;
	sum = a + b;
	printf("%d", sum);

	return 0;
}*/

/*#include <stdio.h>
int main()
{
	short year = 0;
	int sale = 0;
	long total_sale = 0;

	year = 10;
	sale = 200000000;
	total_sale = year * sale;

	printf("total_sale = %d \n", total_sale);
	printf("short���� ũ��: %d����Ʈ\n", sizeof(short));
	printf("int���� ũ��: %d����Ʈ\n", sizeof(int));
	printf("long���� ũ��: %d����Ʈ\n", sizeof(long));

	return 0;
}*/



//4����

//�����÷ο�
/*#include <stdio.h>
int main()
{
	int x = 2147483647;
	unsigned int y = 4294967295;

	printf("x = %d\n", x);
	printf("x+1 = %d\n", x+1);
	printf("x+2 = %d\n", x+2);
	printf("x+3 = %d\n", x+3);

	printf("y = %u\n", y);
	printf("y+1 = %u\n", y + 1);
	printf("y+2 = %u\n", y + 2);
	printf("y+3 = %u\n", y + 3);
	
	return 0;
}*/

/*#include <stdio.h>
int main()
{
	float x = 1.234567890123456789;
	double y = 1.234567890123456789;

	printf("float�� ũ��: %d\n", sizeof(float));
	printf("double�� ũ��: %d\n", sizeof(double));
    printf("long double�� ũ��: %d\n", sizeof(long double));

	printf("x = %30.25f\n", x);
	printf("y = %30.25lf\n", y);

	return 0;
}*/

//Round-off ����
/*#include <stdio.h>
int main()
{
	double x;

	x = (1.0e20 + 5.0) - 1.0e20;
	printf("%f\n", x);

	return 0;
}*/

/*#include <stdio.h>
int main()
{
	char b = '\a';
	printf("first sound: %c", b);
	printf("second sound: \a");

	printf("����ǥ ����ϱ�: \"");

	return 0;
}*/


//5����

/*#include <stdio.h>
#define SEC_PER_MINUTE 60
int main()
{
	int input, minute, second;

	printf("�ʴ���(21���� ����):");
	scanf("%d", &input);

	minute = input / SEC_PER_MINUTE;
	second = input % SEC_PER_MINUTE;

	printf("%d�ʴ� %d�� %d���Դϴ�.\n", input, minute, second);
	return 0;
}*/

/*#include <stdio.h>
int main()
{
	int a = 10;
	int b;

	b = ++a;
	printf("%d", b);
	
	return 0;
}*/

/*#include <stdio.h>
int main()
{
	char c;
	int i;
	float f;

	c = 10000;
	i = 1.23456 + 10;
	f = 10 + 20;

	printf("c = %d, i = %d, f = %f", c, i, f);

	return 0;

}*/

//6����

/*#include <stdio.h>
int main()
{
	char ch;

	scanf("%c", &ch);

	if (ch >= 'A' && ch <= 'Z')
		printf("%c��(��) �빮���Դϴ�.", ch);
	else if (ch >= 'a' && ch <= 'z')
		printf("%c��(��) �ҹ����Դϴ�.", ch);
	else if (ch >= '0' && ch <= '9')
		printf("%c��(��) �����Դϴ�.", ch);
	else
		printf("%c��(��) ��Ÿ�����Դϴ�.", ch);
	
	return 0;
}*/

/*#include <stdio.h>
int main()
{
	int x;
	scanf("%d", &x);

	switch (x)
	{
	case 1:
		printf("�ϳ�\n");
		break;

	case 2:
		printf("��\n");
		break;

	case 3:
		printf("��\n");
		break;
	}
	return 0;
}*/

/*#include <stdio.h>
int main()
{
	char op;
	int a, b;

	scanf("%d %c %d", &a, &op, &b);

	switch (op)
	{
	case '+':
		printf("%d %c %d = %d\n", a, op, b, a + b);
		break;
	case '-':
		printf("%d %c %d = %d\n", a, op, b, a - b);
		break;
	case '*':
		printf("%d %c %d = %d\n", a, op, b, a * b);
		break;
	case '/':
		printf("%d %c %d = %d\n", a, op, b, a / b);
		break;
	case '%':
		printf("%d %c %d = %d\n", a, op, b, a % b);
		break;
	default:
		printf("�������� �ʴ� �������Դϴ�.");
		break;
	}

	return 0;
}*/

/*#include <stdio.h>
int main()
{
	int a;
	scanf("%d", &a);

	switch (a / 10)
	{
	case 10:
	case 9:
		printf("A\n");
		break;
	case 8:
		printf("B\n");
		break;
	case 7:
		printf("C\n");
		break;
	case 6:
		printf("D\n");
		break;
	default:
		printf("���հ�\n");
	}

	return 0;
}*/

/*#include <stdio.h>
int main()
{
	char c;
	scanf("%c", &c);

	if (c >= 'a' && c <= 'z')
	{
		switch (c)
		{
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
			printf("%c�� �����Դϴ�.\n", c);
			break;
		default:
			printf("%c�� �����Դϴ�.\n", c);
			break;
		}
	}
	else
		printf("%c�� ���ĺ� �ҹ��ڰ� �ƴմϴ�.\n",c);

	return 0;
}*/

/*#include <stdio.h>
int main()
{
	int x, y;
	int a;
	
	scanf("%d %d", &x, &y);

	a = (x > 0) ? ((y > 0) ? 1: 4) : ((y > 0) ? 2 : 3);
	
 
	printf("%d��и�\n", a);

	return 0;
}*/

//8����

/*#include <stdio.h>
int main()
{
	int num;
	int sum = 0;

	while (scanf("%d", &num) == 1)
	{
		sum += num;
		printf("q = quit\n");
	}
	printf("sum:%d", sum);

	return 0;
}*/

//9����
/*#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void get_random(int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf(" %6d\n", rand());
}
int main()
{
	srand((unsigned)time(NULL));
	get_random(10);
	return 0;
}*/

/*#include <stdio.h>
#include <Windows.h>
void gotoxy(int x, int y)
{
	COORD Cur = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

int main()
{
	gotoxy(30, 11);
	printf("Hello.C!");

	return 0;
}*/

/*#include <stdio.h>
#include <Windows.h>
#include <conio.h>
void gotoxy(int x, int y)
{
	COORD Cur = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}
int main()
{
	int x = 40, y = 12, ch;
	while (1)
	{
		gotoxy(x, y);
		printf("*");
		ch = _getch();
		if (ch == 224)
			ch = _getch();
		switch (ch) {
		case 72:
			y--;
			break;
		case 80:
			y++;
			break;
		case 75:
			x--;
			break;
		case 77:
			x++;
			break;
		}
	}
}*/

//10����

/*#include <stdio.h>
int inc(int counter);
int main(int counte)
{
	int i;

	i = 10;
	printf("%d\n", i);
	inc(i);
	printf("%d\n", i);

	return 0;
}

int inc(int counter)
{
	counter++;
	return counter;
}*/

/*#include <stdio.h>
void f();
int i;
int main()
{
	for (i = 0; i < 5; i++)
	{
		f();
		return 0;
	}
}

void f()
{
	for (i = 0; i < 10; i++)
		printf("#");
	printf("\n");
}*/

//11����

/*#include <stdio.h>
#define SIZE 10
int main()
{
	int ch[SIZE] = { 0 };
	int a;
	for (a = 0; a < SIZE; a++)
	{
		ch[a] = rand();
	}
	for (a = 0; a < SIZE; a++)
	{
		printf("%d\n", ch[a]);
	}

	return 0;
}*/

/*#include <stdio.h>
#define SIZE 10
int main()
{
	char ch[SIZE];
	int a;

	for (a = 0; a < SIZE; a++)
	{
		ch[a] = 'a' + a;
		printf("%c", ch[a]);
	}

	return 0;
}*/

//12����
/*#include <stdio.h>
void larger_of(double*, double*);
int main()
{
	double x, y;
	scanf("%lf %lf", &x, &y);
	printf("%f %f\n", x, y);
	larger_of(&x, &y);
	printf("%f %f\n", x, y);
	return 0;
}
void larger_of(double *x, double*y)
{
	if (*x > * y)
		*y = *x;
	else
		*x = *y;
}*/

//13����
/*#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#define SIZE 6
#define TIME 5
void show(char* string);
int main()
{
	char word[SIZE], ch, input[SIZE];
	int s_time, j = 0;
	srand(time(0));
	show(word);
	s_time = time(0);
	while (1)
	{
		if (time(0) == s_time + TIME)
		{
			system("cls");
			show(word);
			s_time = time(0);
			j = 0;
		}
		if (_kbhit())
		{
			ch = _getch();

			if (ch == 27)
			{
				break;
			}
			else if (('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z'))
			{
				printf("%c", ch);
				input[j] = ch;
				j++;
			}
			else if (ch == 8)
			{
				printf("\b \b");
				if (j == 0)
					continue;
				j--;
			}
		}
		if (j >= SIZE - 1)
		{
			input[SIZE - 1] = 0;
			if (!strcmp(word, input))
			{
				printf("\n�����Դϴ�!\n");
				Sleep(1000);
			}
			else
			{
				printf("\n��Ÿ���׿�~\n");
				Sleep(1000);
			}
			system("cls");
			show(word);
			s_time = time(0);
			j = 0;
		}
	}
}
void show(char* string)
{
	int i;
	srand(time(NULL));
	for (i = 0; i < 5; i++)
		string[i] = 'a' + (rand() % 26);
	string[i] = '\0';
	printf("%s\n", string);
}*/

/*#include <stdio.h>
#define SIZE 5
#define ASIZE 50
struct student
{
	char name[ASIZE];
	char id[ASIZE];
	char cp[ASIZE];
	char major[ASIZE];
};
void insert(struct student* s, int c);
void show_list(struct student* s, int c);

int main()
{
	int a;
	printf("�޴��� �����ϼ��� (1:�ű� ���, 2:�л� �˻�, 3:�л� ���, 4: ������)");
	scanf("%d", &a);

	struct student st[SIZE];
	int count = 0, sel;
	char sel[2];
	while (count > SIZE)
	{
		insert(st, count);
		count++;
		if (count < SIZE)
		{
			printf("\n��� �Է��Ͻðڽ��ϱ�?");
			gets_s(sel, 2);
			if (!(strcmp(sel, "q")))
				break;
		}
	}
	show_list(st, count);

	return 0;
}

void insert(struct student* s, int c)
{
	printf("�̸�: ");
	gets_s(s[c].name, ASIZE);
	printf("�й�: ");
	gets_s(s[c].id, ASIZE);
	printf("�ڵ��� ��ȣ: ");
	gets_s(s[c].cp, ASIZE);	
	printf("�а���: ");
	gets_s(s[c].major, ASIZE);
}

void show_list(struct student* s, int c)
{
	int i;
	for (i = 0; i < c; i++)
	{
		printf("\n%s(%s)\n", s[i].name, s[i].id);
		printf("\nC.P= %s\n", s[i].cp);
		printf("\nMajor: %s\n", s[i].major);
	}
}*/

//14����
/*#include <stdio.h>
#include <stdlib.h>
void print_random(char**q, int a);
int main()
{
	char* fruit[] = { "apple", "blueberry", "melon" , "mango" };
	int size = sizeof(fruit) / sizeof(fruit[0]);
	srand(time(0));
	print_random(fruit, size);
	return 0;
}
void print_random(char **q, int a)
{
	char c;
	while (1)
	{
		printf("%s\n", q[rand() % a]);
		c = _getch();
		if (c == 27)
			break;
	}
}*/

/*#include <stdio.h>
int main()
{
	int a[3][3] = { {1,2,3},{1,2,3},{1,2,3} };
	int(*p)[3] = a;
	int* q = a;

	for (int i = 0; i < 3; i++)
	{
		printf("a + %d: %p", i, a + i);
		printf("\tp + %d: %p", i, p + i);
		printf("\tq + %d: %p\n", i, q + i);
	}

	return 0;
}*/

//15����

#include <stdio.h>
typedef struct node {
	int data;
	struct node* link;
} NODE;
int main()
{
	NODE* p1;
	p1 = (NODE*)malloc(sizeof(NODE));

	p1->data = 10;
	p1->link = NULL;

	NODE* p2;
	p2 = (NODE*)malloc(sizeof(NODE));
	p2->data = 20;
	p2->link = NULL;
	p1->link = p2;

	free(p1);
	free(p2);

	return 0;
}

//����
#include <stdio.h>

NODE* insert_node(NODE* plist, NODE* pprev, int item)
{
	NODE* pnew = NULL;
	if (!(pnew = (NODE*)malloc(sizeof(NODE))))
	{
		printf("�޸� ���� �Ҵ� ����\n");
		return 0;
	}
	pnew->data = item;
	if (pprev == NULL)
	{
		pnew->link = pprev->link;
		plist = pnew;
	}
	else
	{
		pnew->link = pprev->link;
		pprev->link = pnew;
	}
}

//��ȸ

void print_list(NODE* plist)
{
	NODE* p;
	p = plist;
	printf("(");

	while (p)
	{
		printf("%d ", p->data);
		p = p->link;
	}
	printf(")\n");
}


#include <stdio.h>
#include <stdlib.h>
typedef struct  node {
	int data;
	struct node* link;
}LIST;

LIST* insert_node(LIST* head, int d);

void print_list(LIST* plist);

int main()
{
	LIST* thead = NULL;
	int data;
	char key;

	printf("���Ḯ��Ʈ ����\n");
	while (1)
	{
		printf("�����͸� �Է��ϼ���: ");
		scanf("%d", &data);
		getchar();
		thead = insert_node(thead, data);
		printf("��� ����? ");
		if ((key = getchar()) != 'y')
			break;
		getchar();
	}
	printf("����Ʈ ���\n");
	print_list(thead);
}
LIST* insert_node(LIST* head, int d)
{
	LIST* ptr;
	LIST* nnew = (LIST*)malloc(sizeof(LIST));
	
	if (!nnew)
	{
		printf("�޸� �Ҵ� ����\n");
		exit(1);
	}
	nnew->data = d;
	nnew->link = NULL;
	
	if (!head) // head = NULL
		head = nnew;
	else
	{
		ptr = head;
		while (ptr->link)
			ptr = ptr->link;
		ptr->link = nnew;
	}
	return head;
}

void print_list(LIST* plist)
{
	LIST* p;
	p = plist;
	printf("(");

	while (p)
	{
		printf("%d ", p->data);
		p = p->link;
	}
	printf(")\n");
}