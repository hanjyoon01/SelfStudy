#include <iostream>
#include <fstream>
#include <string>

using namespace std;

namespace jyhan {
	void printName() {
		std::cout << "학번:202011390 이름:한재윤" << std::endl;
	}
}

int** loadMap(int& row, int& col) {
	ifstream fin("testdata2.txt");
	if (!fin.is_open()) {
		cerr << "파일 오픈 실패";
		exit(0);
	}
	fin >> row >> col;
	int** map = new int* [row];
	for (int i = 0; i < row; i++) {
		map[i] = new int[col];
	}
	
	while (!fin.eof()) {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				fin >> map[i][j];
			}
		}
	}
	return map;
}

void showMap(int** (&map), const int row, const int col) {

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << (map[i][j] == 0 ? "○" : "●");
		}
		cout << endl;
	}
}

void deleteMap(int** (&map), const int row) {

	for (int i = 0; i < row; i++) {
		delete[] map[i];
	}
	delete[] map;
	map = nullptr;
}

int main() {

	jyhan::printName();
	cout << endl;

	int row, col;
	int** map = loadMap(row, col);
	
	if (map != nullptr) {
		showMap(map, row, col);
		deleteMap(map, row);
	}
	cout << endl;
	return 0;
}