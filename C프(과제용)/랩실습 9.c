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
		printf("���ڸ� �Է��ϼ���: ");
		gets_s(input, SIZE);
		if (!strcmp(word, input))
			printf("�����Դϴ�!\n");
		else
			printf("��Ÿ���׿�~\n");
		printf("�ٽ� �����Ͻðڽ��ϱ�? ����Ͻ÷��� y Ȥ�� Y�� �����ּ���: ");
		gets_s(answer, 2);
		if ((strcmp(answer, "y") == 0) || (strcmp(answer, "Y") == 0))
		{
			printf("������ �ٽ� �����մϴ�...");
			Sleep(1000);
			system("cls");
		}
		else
		{
			printf("������ ����Ǿ����ϴ�...\n");
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
	printf("������ �Է��ϼ���: \n");
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
