#include <Windows.h>

void ending(int* try)
{
	char b;
	printf("\n그렇게 보물을 찾는데 필요한 모든 것들을 얻은 주인공은...");
	Sleep(2500);
	system("cls");
	printf("\n목재, 못, 그리고 망치로 배를 만들고...");
	Sleep(2500);
	system("cls");
	printf("\n지도와 나침반, 망원경을 이용해서...");
	Sleep(2500);
	system("cls");
	printf("\n보물섬으로 가 그토록 원하던 보물을 찾을 수 있었답니다..!");
	Sleep(2500);
	system("cls");
	printf("\n게임을 클리어했습니다! (시도횟수: %d회) \n\n처음부터 다시 하시겠습니까? (y or n): ", *try);
	while ((b = getchar()) != 224)
	if (b == 'y')
	{
		printf("\n처음부터 다시 시작합니다...");
		Sleep(2000);
		system("cls");
		*try = 1;
		prologue(try);
	}
	else if (b == 'n')
	{
		printf("\n메뉴로 돌아갑니다...\n\n");
		Sleep(2000);
		system("cls");
		main();
	}
}