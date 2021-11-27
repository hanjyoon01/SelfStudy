#include <stdio.h>
#include <string.h>
#include <Windows.h>
#define SIZE 5
#define ASIZE 50
struct student
{
	char name[ASIZE+1];
	char id[ASIZE+1];
	char cp[ASIZE+1];
	char major[ASIZE+1];
};

void show_menu();
void insert_student(struct student* s, int* c);
void search_student(struct student* s, int c);
void show_list(struct student* s, int c);

int main()
{
	struct student st[SIZE];
	int count = 0, sel;

	while (1)
	{
		show_menu();
		scanf("%d", &sel);
		getchar();
		if (sel == 4)
			break;
		if (sel < 1 || sel > 4)
			continue;
		switch (sel)
		{
		case (1):
			insert_student(st, &count);
			break;
		case (2):
			search_student(st, count);
			break;
		case (3):
			show_list(st, count);
			break;
		}	
	}
	return 0;
}
void show_menu()
{
	printf("�޴��� �����ϼ��� (1:�ű� ���  2:�л� �˻�  3:�л� ���  4: ������): ");
}

void insert_student(struct student* s, int* c)
{
	char sel[2];

	if (*c >= SIZE)
	{
		printf("\n�� �̻� �Է��� �� �����ϴ�. �޴��� ���ư��ϴ�.");
		Sleep(3000);
		system("cls");
	}
	else
	{
		printf("\n�̸�: ");
		gets_s(s[*c].name, ASIZE);
		printf("�й�: ");
		gets_s(s[*c].id, ASIZE);
		printf("�ڵ��� ��ȣ: ");
		gets_s(s[*c].cp, ASIZE);
		printf("�а���: ");
		gets_s(s[*c].major, ASIZE);
		(*c)++;

		printf("\n��� �Է��Ͻðڽ��ϱ�? (q�� ������ ����) ");
		gets_s(sel, 2);
		if (!(strcmp(sel, "q")))
		{
			printf("\n�޴��� ���ư��ϴ�.");
			Sleep(3000);
			system("cls");
		}
		else
			insert_student(s, c);
	}
}
void search_student(struct student* s, int c)
{
	int i;
	char s_name[ASIZE+1];
	char sel[2], sum = 0;
	int count = 0;
	printf("\n�л� �̸��� �Է��ϼ���: ");
	gets_s(s_name, ASIZE);
	for (i = 0; i < c; i++)
	{
		if (!(strcmp(s_name, s[i].name)))
		{
			printf("\n%s(%s)\n", s[i].name, s[i].id);
			printf("C.P= %s\n", s[i].cp);
			printf("Major: %s\n", s[i].major);
			count++;
		}
	}
	if (count == 0)
		printf("\n�ش� �л��� ��ܿ� �����ϴ�. \n");
	
	printf("\n�ٽ� �Է��Ͻðڽ��ϱ�? (q�� ������ ����) ");
	gets_s(sel, 2);
	if (!(strcmp(sel, "q")))
	{
		printf("\n�޴��� ���ư��ϴ�.");
		Sleep(3000);
		system("cls");
	}
	else
	{
		search_student(s, c);
	}
}
void show_list(struct student* s, int c)
{
	int i;
	char ch;
	for (i = 0; i < c; i++)
	{
		printf("\n%s(%s)\n", s[i].name, s[i].id);
		printf("C.P= %s\n", s[i].cp);
		printf("Major: %s\n", s[i].major);
	}
	printf("\n�޴��� ���ư����� �ƹ�Ű�� ��������...");
	ch = _getch();
	system("cls");
}
