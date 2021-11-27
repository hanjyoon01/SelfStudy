#pragma once

class MineSweeper
{
private:
	int row, col; //��, �� �� ����
	int **Map; //����, �ֺ� ���� ���� ����
	int **Status; //����, ��� ���� ����
	int saveCount = 0; //����� ���� ���� ����
	double ratio; //���̵��� ���� ���� ���� ����
	bool isEnd = false; //���� ���� ���� ����
	bool isClear = false; //���� Ŭ���� ���� ����
public:
	MineSweeper(); //�⺻ ������
	~MineSweeper(); //�Ҹ���(�ʿ�x)
	void start(); //�޴� ȭ�� ���
	void play(); //�÷��� ȭ��
	void makeMap(); //�� ����
	void deleteMap(); //Map�迭, Status�迭 ����
	void printMap(); //�� ȭ�� ���
	void openMine(int mx, int my); //EnterŰ �Է� �� (����)
	void checkMine(int mx, int my); //TabŰ �Է� �� (���)
	void loadSavedMap(int i); //����� �� �ҷ�����
	void loadSaveCount(); //saveCount �ʱ�ȭ
};

