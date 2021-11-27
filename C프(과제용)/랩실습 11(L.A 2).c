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
	printf("메뉴를 선택하세요 (1:신규 등록  2:학생 검색  3:학생 출력  4: 끝내기): ");
}

void insert_student(struct student* s, int* c)
{
	char sel[2];

	if (*c >= SIZE)
	{
		printf("\n더 이상 입력할 수 없습니다. 메뉴로 돌아갑니다.");
		Sleep(3000);
		system("cls");
	}
	else
	{
		printf("\n이름: ");
		gets_s(s[*c].name, ASIZE);
		printf("학번: ");
		gets_s(s[*c].id, ASIZE);
		printf("핸드폰 번호: ");
		gets_s(s[*c].cp, ASIZE);
		printf("학과명: ");
		gets_s(s[*c].major, ASIZE);
		(*c)++;

		printf("\n계속 입력하시겠습니까? (q를 누르면 종료) ");
		gets_s(sel, 2);
		if (!(strcmp(sel, "q")))
		{
			printf("\n메뉴로 돌아갑니다.");
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
	printf("\n학생 이름을 입력하세요: ");
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
		printf("\n해당 학생이 명단에 없습니다. \n");
	
	printf("\n다시 입력하시겠습니까? (q를 누르면 종료) ");
	gets_s(sel, 2);
	if (!(strcmp(sel, "q")))
	{
		printf("\n메뉴로 돌아갑니다.");
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
	printf("\n메뉴로 돌아가려면 아무키나 누르세요...");
	ch = _getch();
	system("cls");
}
