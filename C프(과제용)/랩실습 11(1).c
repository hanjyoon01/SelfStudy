//Lap Assignment
#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#define SIZE 6
#define TIME_LIMIT 5
void show_string(char* w);
int main()
{
	char word[SIZE], ch, input[SIZE];
	int s_time, j = 0;
	srand(time(0));
	show_string(word);
	s_time = time(0);
	while (1)
	{
		if (time(0) == s_time + TIME_LIMIT)
		{
			system("cls");
			show_string(word);
			s_time = time(0);
			j = 0;
		}
		if (_kbhit())
		{
			ch = _getch();
			if (ch == 27)
				break;
			else if (('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z'))
			{
				printf("%c", ch);
				input[j] = ch;
				j++;
			}
			else if (ch == 8)
			{
				if (j == 0)
					continue;
				printf("\b \b");
				j--;
			}
		}
		if (j >= SIZE - 1)
		{
			input[SIZE - 1] = 0;
			if (!strcmp(word, input))
			{
				printf("\n정답입니다!\n");
				Sleep(1000);
			}
			else
			{
				printf("\n안타깝네요~\n");
				Sleep(1000);
			}
			system("cls");
			show_string(word);
			s_time = time(0);
			j = 0;
		}
	}
}
void show_string(char* w)
{
	int i;
	srand(time(NULL));
	for (i = 0; i < 5; i++)
		w[i] = 'a' + (rand() % 26);
	w[i] = '\0';
	printf("%s\n", w);
}

