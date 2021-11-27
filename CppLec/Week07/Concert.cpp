#include "Concert.h"
#include <iostream>
using namespace std;
 
//Concert::Concert(const string& name, const int& capacity)
//	:name(name), capacity(capacity), rList(new string[capacity])
//{
//	cout << "������" << endl;
//}

Concert::Concert(const string& name, const int& capacity)
	: name(name), capacity(capacity), rList(make_unique<string[]>(capacity))
{
	cout << "������" << endl;
}

Concert::Concert(const Concert& concert)
	:Concert(concert.name, concert.capacity)
{
	cout << "���������" << endl;
	num = concert.num;
	for (size_t i = 0; i < num; i++) {
		rList[i] = concert.rList[i];
	}
}

Concert::Concert(Concert&& concert) noexcept
	:name(concert.name), capacity(concert.capacity), rList(move(concert.rList)), num(concert.num)
{
	cout << "�̵�������" << endl;
	concert.num = 0;
	//concert.rList = nullptr;
}

Concert::~Concert()
{
	cout << name << "�Ҹ���" << endl;
	/*if (rList != nullptr)
		delete[] rList;
	rList = nullptr;*/
}

void Concert::reservation()
{
	if (!full() && rList != nullptr) {
		cout << "������ �̸��� �Է��ϼ��� : ";
		cin >> rList[num++];
		cout << "������ �Ϸ�Ǿ����ϴ�." << endl;
	}
	else {
		cout << "�ܼ�Ʈ ������ ����Ǿ����ϴ�." << endl;
	}
}

bool Concert::full() const
{
	return capacity == num;
}

int Concert::getCapacity() const
{
	return capacity;
}

int Concert::getNum() const
{
	return num;
}

void Concert::show() const
{
	cout << "�ܼ�Ʈ ��: " << name << endl;
	cout << "���� ��: " << num << endl;
	cout << "������ ����Ʈ: " << endl;
	cout << "===============" << endl;
	for (size_t i = 0; i < num; i++) {
		cout << rList[i] << endl;
	}
	cout << "===============" << endl;
}
