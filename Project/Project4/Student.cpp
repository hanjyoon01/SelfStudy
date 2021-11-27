#include "Student.h"

Student::Student()
{
}

Student::~Student()
{
}

Student::Student(const string& name, const int& score)
	:name(name),  score(score)
{
}

string Student::getName() const
{
	return name;
}

int Student::getScore() const
{
	return score;
}

ostream& operator<<(ostream& out, const Student& student)
{
	out << student.getName() << " " << student.getScore();
	return out;
}

bool Student::operator==(const Student& student) {
	return name == student.name && score == student.score;
}

bool Student::operator==(const string& n)
{
	return name == n;
}
