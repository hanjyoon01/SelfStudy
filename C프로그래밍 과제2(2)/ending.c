#include <Windows.h>

void ending(int* try)
{
	char b;
	printf("\n�׷��� ������ ã�µ� �ʿ��� ��� �͵��� ���� ���ΰ���...");
	Sleep(2500);
	system("cls");
	printf("\n����, ��, �׸��� ��ġ�� �踦 �����...");
	Sleep(2500);
	system("cls");
	printf("\n������ ��ħ��, �������� �̿��ؼ�...");
	Sleep(2500);
	system("cls");
	printf("\n���������� �� ����� ���ϴ� ������ ã�� �� �־���ϴ�..!");
	Sleep(2500);
	system("cls");
	printf("\n������ Ŭ�����߽��ϴ�! (�õ�Ƚ��: %dȸ) \n\nó������ �ٽ� �Ͻðڽ��ϱ�? (y or n): ", *try);
	while ((b = getchar()) != 224)
	if (b == 'y')
	{
		printf("\nó������ �ٽ� �����մϴ�...");
		Sleep(2000);
		system("cls");
		*try = 1;
		prologue(try);
	}
	else if (b == 'n')
	{
		printf("\n�޴��� ���ư��ϴ�...\n\n");
		Sleep(2000);
		system("cls");
		main();
	}
}