#pragma once
#include <string>
#include <iostream>
using std::string;
using std::shared_ptr;
using std::unique_ptr;

class Concert
{
private:
	string name;
	int capacity;
	int num = 0;
	//string* rList = nullptr;
	//shared_ptr<string[]> rList = nullptr;
	unique_ptr<string[]> rList = nullptr;
public:
	Concert() = delete;
	Concert(const string& name, const int& capacity = 10);
	Concert(const Concert& concert);
	Concert(Concert&& concert) noexcept;
	~Concert();

	void reservation();
	bool full() const;
	int getCapacity() const;
	int getNum() const;
	void show() const;
};

