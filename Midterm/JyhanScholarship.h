#pragma once
#include <iostream>
#include <string>
#include "JyhanStudent.h"
using namespace std;

class JyhanScholarship
{
private:
	string name;
	int capacity;
	int count = 0;
	JyhanStudent** students;

public:
	JyhanScholarship() = delete;
	JyhanScholarship(const string& name, const int& capacity);
	JyhanScholarship(const JyhanScholarship& Sch);
	JyhanScholarship(JyhanScholarship&& Sch) noexcept;
	~JyhanScholarship();

	void apply(const string& name, const double& grade);

	friend ostream& operator<<(ostream& out, const JyhanScholarship& jyhanSch);
};

