//Lap Assignment 1
/*#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 6
int main()
{
	while (1)
	{
		char word[SIZE];
		char input[SIZE];
		char answer[2];
		int i;
		srand(time(NULL));
		for (i = 0; i < 5; i++)
			word[i] = 'a' + (rand() % 26);
		word[i] = '\0';
		printf("%s\n", word);
		Sleep(2000);
		system("cls");
		printf("글자를 입력하세요: ");
		gets_s(input, SIZE);
		if (!strcmp(word, input))
			printf("정답입니다!\n");
		else
			printf("안타깝네요~\n");
		printf("다시 수행하시겠습니까? 계속하시려면 y 혹은 Y를 눌러주세요: ");
		gets_s(answer, 2);
		if ((strcmp(answer, "y") == 0) || (strcmp(answer, "Y") == 0))
		{
			printf("게임을 다시 시작합니다...");
			Sleep(1000);
			system("cls");
		}
		else
		{
			printf("게임이 종료되었습니다...\n");
			break;
		}
	}
	return 0;
}*/

//Lap Assignment 2
/*#include <stdio.h>
#include <string.h>
#define SIZE 41
int main()
{
	char string[SIZE];
	int alphabet[26] = { 0 };
	int a,b;
	printf("문장을 입력하세요: \n");
	gets_s(string, 40);
	for (a = 0; a < strlen(string); a++)
	{
		for (b = 0; b < 26; b++)
		{
			if (string[a] == ('a' + b))
				alphabet[b]++;
		}
	}
	for (a = 0; a < 26; a++)
		printf("%c:%2d ", 'A' + a, alphabet[a]);
	printf("\n");

	return 0;
}*/
