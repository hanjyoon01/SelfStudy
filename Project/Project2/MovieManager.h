#pragma once
#include "Movie.h"
#include <memory>

class MovieManager
{
private:
	int count; //영화 개수 저장
	string txt; //파일 이름
	Movie** movie; //Movie 클래스 배열 
public:
	MovieManager() = delete; //디폴트생성자 삭제
	MovieManager(const string& txt); //생성자
	MovieManager(const MovieManager& MM); //복사 생성자
	MovieManager(MovieManager&& MM) noexcept; //이동 생성자
	~MovieManager(); //소멸자

	void ticketing(); //1번 메뉴
	void ticketCancel(); //2번 메뉴
	void ticketCheck(); //3번 메뉴
	void startMenu(); //메뉴 출력
};

