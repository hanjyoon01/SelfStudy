#pragma once
#include <memory>

using namespace std;

class ArrayData
{
private:
	double* data = nullptr;
	//unique_ptr<double[]> data;
	//shared_ptr<double[]> data;
	int capacity;
	int used;

public:
	ArrayData();
	ArrayData(const int& capacity, const int& used=0);
	ArrayData(ArrayData& arr);
	ArrayData(ArrayData&& arr) noexcept;
	~ArrayData();

	void addElement(double num);
	bool full() const;
	void showData() const;
	void emptyArray();
	int getCapacity() const {
		return this->capacity;
	}
	int getUsed() const {
		return this->used;
	}
};

