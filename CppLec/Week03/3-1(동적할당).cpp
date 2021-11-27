//동적할당 예제1
/*
#include <iostream>
#include <string>
using namespace std;
int main() {

	//정적 할당
	int arr[3][4];
	cout << typeid(arr).name() << endl;
	cout << typeid(arr[0]).name() << endl;
	cout << typeid(arr[0][0]).name() << endl;

	//동적 할당
	//int(*parr)[3][4] = &arr;
	//int(*parr)[4] = arr; // arr ==> &arr[0] ==> &int[4]
	
	int row,col;
	cin >> row >> col;
	int* (*parr) = new int* [row]; //층 생성

	for (int i = 0; i < row; i++) //방 생성
		parr[i] = new int[col];

	for (int i = 0; i < row; i++) //방 삭제
		delete[] parr[i];

	delete parr; //층 삭제
	parr = nullptr;

	return 0;
}*/

//메모리 누수 체크
/*
#include <iostream>
#include <string>
using namespace std;

#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK, __FILE__, __LINE__)
#define new DBG_NEW
#endif // !DBG_NEW
#endif


int* makeArray(const int SIZE) {

	int* temp = new int[SIZE];
	for (int i = 0; i < SIZE; i++)
		temp[i] = rand() % 10;
	return temp;
}

void printArray(int* (&arr), const int SIZE) {
	for (int i = 0; i < SIZE; i++)
		cout << arr[i] << "\t";
	cout << endl;
}

int main() {

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	int* arr = makeArray(10);
	printArray(arr, 10);
	delete[] arr;
	arr = nullptr;

	return 0;
}*/

//동적할당 예제2
/*
#include <iostream>
#include <string>
using namespace std;

int* makeArray(int& num) {

	cout << "학생 수 : ";
	cin >> num;
	int* temp = new int[num];
	for (int i = 0; i < num; i++) {
		cout << i + 1 << "번 학생 성적 : ";
		cin >> temp[i];
	}
	return temp;
}

void printArray(int* (&arr), const int SIZE) {

	cout << "원본 데이터 : ";
	for (int i = 0; i < SIZE; i++)
		cout << arr[i] << "\t";
	cout << endl;
}


void deleteArray(int* (&arr)) {
	delete[] arr;
	arr = nullptr;
}

void deleteSortedArray(int** (&arr)) {
	delete[] arr;
	arr = nullptr;
}

int** sortArray(const int* std, const int num) {
	int** arr = new int* [num];
	for (int i = 0; i < num; i++) {
		arr[i] = const_cast<int*>(&std[i]);
	}

	for (int i = 0; i < num - 1; i++) {
		for (int j = i + 1; j < num; j++) {
			if (*arr[i] > * arr[j]) {
				int* temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	return arr;
}

void printSortedArray(int** (&arr), const int SIZE) {

	cout << "정렬 데이터 : ";
	for (int i = 0; i < SIZE; i++)
		cout << *arr[i] << "\t";
	cout << endl;
}

int main() {

	int num;
	int* std = makeArray(num);
	printArray(std, num);
	int** sortedStd = sortArray(std, num);
	printSortedArray(sortedStd, num);	
	printArray(std, num);
	deleteArray(std);
	deleteSortedArray(sortedStd);
	if (std == nullptr) {
		cout << "int* 정리 완료" << endl;
	}
	if (sortedStd == nullptr) {
		cout << "int** 메모리 정리 완료" << endl;
	}

	return 0;
}*/

//2차원 동적할당
/*
#include <iostream>
#include <string>
using namespace std;

int** makeArray() {
	int row, col;
	cout << "행과 열을 입력 : ";
	cin >> row >> col;
	int* (*arr) = new int* [row];
	for (int i = 0; i < row; i++) {
		arr[i] = new int[col];
	}
	return arr;
}

void initArray(int** (&arr)) {

	size_t row = _msize(arr) / sizeof(arr[0]);
	size_t col = _msize(arr[0]) / sizeof(arr[0][0]);
	int num = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			arr[i][j] = num++;
		}
	}
	for (int i = 0; i < 100; i++){
		int r1 = rand() % row;
		int c1 = rand() % col;
		int r2 = rand() % row;
		int c2 = rand() % col;
		if (r1 != r2 || c1 != c2) {
			int temp = arr[r1][c1];
			arr[r1][c1] = arr[r2][c2];
			arr[r2][c2] = temp;
		}
	}
}

void printArray(int** (&arr)) {
	size_t row = _msize(arr) / sizeof(arr[0]);
	size_t col = _msize(arr[0]) / sizeof(arr[0][0]);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

void deleteArray(int** (&arr)) {
	size_t row = _msize(arr) / sizeof(arr[0]);
	for (int i = 0; i < row; i++) {
		delete[] arr[i];
	}
	delete[] arr;
	arr = nullptr;
}

int main() {
	
	int** arr = makeArray();
	initArray(arr);
	printArray(arr);
	deleteArray(arr);
	return 0;

}*/