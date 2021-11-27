#pragma once
#include "Movie.h"
#include <memory>

class MovieManager
{
private:
	int count; //��ȭ ���� ����
	string txt; //���� �̸�
	Movie** movie; //Movie Ŭ���� �迭 
public:
	MovieManager() = delete; //����Ʈ������ ����
	MovieManager(const string& txt); //������
	MovieManager(const MovieManager& MM); //���� ������
	MovieManager(MovieManager&& MM) noexcept; //�̵� ������
	~MovieManager(); //�Ҹ���

	void ticketing(); //1�� �޴�
	void ticketCancel(); //2�� �޴�
	void ticketCheck(); //3�� �޴�
	void startMenu(); //�޴� ���
};

