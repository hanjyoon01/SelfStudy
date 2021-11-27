#pragma once
#include <string>
using namespace std;

class JyhanStudent
{
private:
	string name;
	double grade;

public:
	JyhanStudent() = delete;
	JyhanStudent(const string& name, const double& grade);
	JyhanStudent(const JyhanStudent& s);
	~JyhanStudent();

	string getName();
	double getGrade();

	friend ostream& operator<<(ostream& out, const JyhanStudent& jyhan);
};



