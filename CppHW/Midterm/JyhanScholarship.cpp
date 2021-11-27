#include "JyhanScholarship.h"

JyhanScholarship::JyhanScholarship(const string& name, const int& capacity)
	:name(name), capacity(capacity)
{
	students = new JyhanStudent*[capacity];
	
	for(size_t i=0; i<capacity;i++)
		students[i] = new JyhanStudent("null", 0.0);
}

JyhanScholarship::JyhanScholarship(const JyhanScholarship& Sch)
{
	cout << "���� ������" << endl;
	name = Sch.name;
	capacity = Sch.capacity;
	count = Sch.count;
	students = new JyhanStudent*[Sch.capacity];
	for (size_t i = 0; i < capacity; i++)
		students[i] = new JyhanStudent("null", 0.0);
	for (int i = 0; i < count; i++) {
		students[i] = new JyhanStudent(*Sch.students[i]);
	}
}

JyhanScholarship::JyhanScholarship(JyhanScholarship&& Sch) noexcept
	:name(Sch.name), capacity(Sch.capacity), count(Sch.count), students(Sch.students)
{
	cout << "�̵� ������" << endl;
	Sch.students = nullptr;
}

JyhanScholarship::~JyhanScholarship()
{
	for (int i = 0; i < capacity; i++) {
		delete students[i];
		students[i] = nullptr;
	}
	delete students;
	students = nullptr;
}

void JyhanScholarship::apply(JyhanStudent& s) 
{
	if (count >= capacity) {
		cout << "��û����" << endl;
	}
	else {
		*students[count++] = s;
		cout << "��û�Ϸ�" << endl;
	}
}
ostream& operator<<(ostream& out, const JyhanScholarship& jyhanSch)
{
	out << "-----------------" << endl;
	out << "���бݸ�: " << jyhanSch.name << endl;
	out << "�����ο�: " << jyhanSch.capacity << endl;
	
	double sum = 0.0;
	for (size_t i = 0; i < jyhanSch.count; i++) {
		sum += jyhanSch.students[i]->getGrade();
	}
	double average = sum / (jyhanSch.count);

	out << "�������: " << average << endl;
	out << "��û�ڼ�: " << jyhanSch.count << endl;

	for (size_t i = 0; i < jyhanSch.count; i++) {
		out << *jyhanSch.students[i];
	}

	return out;
}
