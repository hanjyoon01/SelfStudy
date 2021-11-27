#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <conio.h>
#include <time.h>
#define EASY 6
#define MEDIUM 7
#define HARD 12
#define PLAYER_MARK  "¡ß"
#define WALL_MARK  "¡á"
#define FLAG_MARK  "¢º"
void gotoxy(int x, int y);
void easy(int* try);
void medium(int* try);
void hard(int* try);
void prologue(int* try);
void scenario_1(int* try);
void scenario_2(int* try);
void ending(int* try);