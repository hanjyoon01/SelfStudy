#include "Movie.h"
#include <iostream>

using namespace std;

Movie::Movie(const string& name, const int& R, const int& C)
	: name(name), ROW(R), COL(C)
{
	//cout << "Movie 생성자" << endl; //생성자 테스트용

	//예약 번호 2차원 배열 생성
	seats = new int* [ROW];
	for (int i = 0; i < ROW; i++) {
		seats[i] = new int[COL];
	}

	//예약번호 0 부여
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			seats[i][j] = 0;
		}
	}

	//잔여 좌석, 전체 좌석 초기화
	LS = ROW * COL;
	FS = ROW * COL;
}

Movie::Movie(const Movie& mov)
	:Movie(mov.name, mov.ROW, mov.COL)
{
	cout << "Movie 복사 생성자" << endl;
	for (int i = 0; i < mov.ROW; i++) {
		*seats[i] = *mov.seats[i];
	}
}

Movie::Movie(Movie&& mov) noexcept : name(mov.name), ROW(mov.ROW), COL(mov.COL), seats(move(mov.seats))
{
	cout << "Movie 이동 생성자" << endl;
	mov.seats = nullptr;
}


Movie::~Movie()
{	
	//cout << "Movie 소멸자" << endl; //소멸자 테스트용

	//seats 메모리 해제
	if (seats != nullptr) {
		for (int i = 0; i < ROW; i++) {
			delete[] seats[i];
		}
		delete[] seats;
		seats = nullptr;
	}
}

//영화 좌석 출력
void Movie::printSeat()
{
	for (int i = 0; i < COL; i++)
		cout << "  " << '\t' << i + 1;
	cout << "\n\n";

	for (int i = 0; i < ROW; i++) {
		cout << "  " << static_cast<char>('A' + i) << '\t';
		for (int j = 0; j < COL; j++) {
			cout << (seats[i][j] == 0 ? "○" : "●") << '\t';
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
