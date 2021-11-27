#include "ArrayData.h"
#include <iostream>
using namespace std;

ArrayData::ArrayData() :ArrayData(3)
{
}

ArrayData::ArrayData(const int& capacity, const int& used) : capacity(capacity), used(used)
{
	cout << "������" << endl;
	data = new double[this->capacity];
	//data = make_unique<double[]>(this->capacity);
	//data = shared_ptr<double[]>(new double[this->capacity]);
}

ArrayData::ArrayData(ArrayData& arr) :ArrayData(arr.capacity, arr.used)
{
	cout << "���������" << endl;
	for (size_t i = 0; i < used; i++) {
		data[i] = arr.data[i];
	}
}

ArrayData::ArrayData(ArrayData&& arr) noexcept :capacity(arr.capacity), used(arr.used), data(arr.data)
{
	cout << "�̵�������" << endl;
	arr.data = nullptr;
}

ArrayData::~ArrayData()
{
	if (data != nullptr)
		delete[] data;
	data = nullptr;
}

void ArrayData::addElement(double num)
{
	if (!full())
		data[used++] = num;
	else
		cout << "�� ���� ����\n";
}

bool ArrayData::full() const
{
	return this->capacity == this->used;
}

void ArrayData::emptyArray()
{
	this->used = 0;
}

double& ArrayData::operator[](size_t num)
{
	if (num >= 0 && num < capacity)
		return data[num];
	else {
		cout << "�迭 ���� ����" << endl;
		exit(0);
	}
}

const double& ArrayData::operator[](size_t num) const
{
	if (num >= 0 && num < capacity)
		return data[num];
	else {
		cout << "�迭 ���� ����" << endl;
		exit(0);
	}
}

ArrayData& ArrayData::operator=(const ArrayData& rhs)
{
	cout << "���Կ�����" << endl;
	if (this == &rhs) {
		return *this;
	}
	this->capacity = rhs.capacity;
	this->used = rhs.used;
	if (data != nullptr)
		delete[] data;
	data = new double[capacity];
	//data.reset(new double[capacity]);
	//data = static_cast<shared_ptr<double[]>>(new double[capacity]);
	for (size_t i = 0; i < used; i++) {
		data[i] = rhs.data[i];
	}
	return *this;
}

ArrayData& ArrayData::operator=(ArrayData&& rhs) noexcept
{
	cout << "�̵����Կ�����" << endl;
	this->capacity = rhs.capacity;
	this->used = rhs.used;
	if (data != nullptr)
		delete[] data;
	data = rhs.data;
	//data = move(rhs.data);
	rhs.data = nullptr;
	return *this;
}

void ArrayData::showData() const
{
	for (size_t i = 0; i < used; i++)
		cout << data[i] << " ";
	cout << endl;
}

ostream& operator<<(ostream& out, const ArrayData& arr) {
	for (size_t i = 0; i < arr.getUsed(); i++) {
		//out << data[i] << "\t";
		out << arr.data[i] << "\t";
	}
	out << endl;
	return out;
}