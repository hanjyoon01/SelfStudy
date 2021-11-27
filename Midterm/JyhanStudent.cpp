#include "JyhanStudent.h"
#include <iostream>


JyhanStudent::JyhanStudent(const string& name, const double& grade)
	:name(name), grade(grade)
{
}

JyhanStudent::JyhanStudent(const JyhanStudent& s)
	: JyhanStudent(s.name, s.grade)
{
}

JyhanStudent::~JyhanStudent()
{
}

string JyhanStudent::getName()
{
	return name;
}

double JyhanStudent::getGrade()
{
	return grade;
}

ostream& operator<<(ostream& out, const JyhanStudent& jyhan) {

	out << "-----------------" <<endl;
	out << "�̸�: " << jyhan.name << endl;
	out << "����: " << jyhan.grade << endl;
	return out;
}