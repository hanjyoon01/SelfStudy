#include "Movie.h"
#include <iostream>

using namespace std;

Movie::Movie(const string& name, const int& R, const int& C)
	: name(name), ROW(R), COL(C)
{
	//cout << "Movie ������" << endl; //������ �׽�Ʈ��

	//���� ��ȣ 2���� �迭 ����
	seats = new int* [ROW];
	for (int i = 0; i < ROW; i++) {
		seats[i] = new int[COL];
	}

	//�����ȣ 0 �ο�
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			seats[i][j] = 0;
		}
	}

	//�ܿ� �¼�, ��ü �¼� �ʱ�ȭ
	LS = ROW * COL;
	FS = ROW * COL;
}

Movie::Movie(const Movie& mov)
	:Movie(mov.name, mov.ROW, mov.COL)
{
	cout << "Movie ���� ������" << endl;
	for (int i = 0; i < mov.ROW; i++) {
		*seats[i] = *mov.seats[i];
	}
}

Movie::Movie(Movie&& mov) noexcept : name(mov.name), ROW(mov.ROW), COL(mov.COL), seats(move(mov.seats))
{
	cout << "Movie �̵� ������" << endl;
	mov.seats = nullptr;
}


Movie::~Movie()
{	
	//cout << "Movie �Ҹ���" << endl; //�Ҹ��� �׽�Ʈ��

	//seats �޸� ����
	if (seats != nullptr) {
		for (int i = 0; i < ROW; i++) {
			delete[] seats[i];
		}
		delete[] seats;
		seats = nullptr;
	}
}

//��ȭ �¼� ���
void Movie::printSeat()
{
	for (int i = 0; i < COL; i++)
		cout << "  " << '\t' << i + 1;
	cout << "\n\n";

	for (int i = 0; i < ROW; i++) {
		cout << "  " << static_cast<char>('A' + i) << '\t';
		for (int j = 0; j < COL; j++) {
			cout << (seats[i][j] == 0 ? "��" : "��") << '\t';
		}
		cout << "\n\n";
	}
}

void Movie::setName(const string& str)
{
	name = str;
}

void Movie::setRow(const int& r)
{
	ROW = r;
}

void Movie::setCol(const int& c)
{
	COL = c;
}

void Movie::decrLS()
{
	LS--;
}

void Movie::incrLS()
{
	LS++;
}

void Movie::setSeat(int a, int b, int c)
{
	seats[a][b] = c;
}

string Movie::getName()
{
	return name;
}

int Movie::getRow()
{
	return ROW;
}

int Movie::getCol()
{
	return COL;
}

int Movie::getLS()
{
	return LS;
}

int Movie::getFS()
{
	return FS;
}

int Movie::getSeat(const int& a, const int& b)
{
	return seats[a][b];
}
