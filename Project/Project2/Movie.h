#pragma once
#include <string>

using namespace std;
class Movie
{
private:
	string name; //영화 이름
	int* (*seats); //예약 번호 저장
	int ROW, COL; //행, 열
	int LS, FS; //잔여 좌석, 전체 좌석

public:
	Movie() = delete; //디폴트 생성자 삭제
	Movie(const string& name, const int& ROW, const int& COL); //생성자
	Movie(const Movie& mov); //복사생성자
	Movie(Movie&& mov) noexcept; //이동생성자
	~Movie(); //소멸자

	void printSeat(); //좌석 출력
	void setName(const string& str); //영화 이름 변경
	void setRow(const int& r); //행 변경
	void setCol(const int& c); //열 변경
	void decrLS(); //잔여좌석 감소
	void incrLS(); //잔여좌석 증가
	void setSeat(int a, int b, int c); //예약번호 부여

	string getName();

	int getRow(); //행 번호
	int getCol(); //열 번호
	int getLS(); //잔여 좌석
	int getFS(); //전체 좌석
	int getSeat(const int& a, const int& b); //예약 번호
	
};

