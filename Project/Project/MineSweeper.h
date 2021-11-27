#pragma once

class MineSweeper
{
private:
	int row, col; //행, 열 값 저장
	int **Map; //지뢰, 주변 지뢰 개수 저장
	int **Status; //오픈, 깃발 여부 저장
	int saveCount = 0; //저장된 게임 개수 저장
	double ratio; //난이도에 따른 지뢰 비율 저장
	bool isEnd = false; //게임 종료 여부 저장
	bool isClear = false; //게임 클리어 여부 저장
public:
	MineSweeper(); //기본 생성자
	~MineSweeper(); //소멸자(필요x)
	void start(); //메뉴 화면 출력
	void play(); //플레이 화면
	void makeMap(); //맵 생성
	void deleteMap(); //Map배열, Status배열 삭제
	void printMap(); //맵 화면 출력
	void openMine(int mx, int my); //Enter키 입력 시 (오픈)
	void checkMine(int mx, int my); //Tab키 입력 시 (깃발)
	void loadSavedMap(int i); //저장된 맵 불러오기
	void loadSaveCount(); //saveCount 초기화
};

