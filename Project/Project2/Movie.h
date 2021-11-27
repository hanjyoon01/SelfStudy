#pragma once
#include <string>

using namespace std;
class Movie
{
private:
	string name; //��ȭ �̸�
	int* (*seats); //���� ��ȣ ����
	int ROW, COL; //��, ��
	int LS, FS; //�ܿ� �¼�, ��ü �¼�

public:
	Movie() = delete; //����Ʈ ������ ����
	Movie(const string& name, const int& ROW, const int& COL); //������
	Movie(const Movie& mov); //���������
	Movie(Movie&& mov) noexcept; //�̵�������
	~Movie(); //�Ҹ���

	void printSeat(); //�¼� ���
	void setName(const string& str); //��ȭ �̸� ����
	void setRow(const int& r); //�� ����
	void setCol(const int& c); //�� ����
	void decrLS(); //�ܿ��¼� ����
	void incrLS(); //�ܿ��¼� ����
	void setSeat(int a, int b, int c); //�����ȣ �ο�

	string getName();

	int getRow(); //�� ��ȣ
	int getCol(); //�� ��ȣ
	int getLS(); //�ܿ� �¼�
	int getFS(); //��ü �¼�
	int getSeat(const int& a, const int& b); //���� ��ȣ
	
};

