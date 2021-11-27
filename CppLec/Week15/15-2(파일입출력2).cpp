#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>

using namespace std;
using namespace std::filesystem;

void changeNumberByID(const string& filename, int id, const string& newNumber) {
	fstream data(filename);
	if (data.fail()) {
		cerr << "파일 열기 실패" << endl;
		return;
	}
	while (!data.eof()) {
		int temp;
		data >> temp;
		if (data.fail()) {
			break;
		}
		if (temp == id) {
			data.seekp(data.tellg());
			data << " " << newNumber;
			break;
		}
	}
}

int main() {
	//changeNumberByID("userlist.txt", 125, "010-1111-5555");
	
	//path p1("c:\\");
	//p1.append("users");
	//p1.append("한재윤");
	//p1 /= "test.txt";
	//cout << p1 << endl;
	//for (auto& c : p1) {
	//	cout << c << endl;
	//}

	//directory_entry file(p1);
	//if (file.exists() && file.is_regular_file()) {
	//	cout << file.file_size() << endl;
	//}
	//else {
	//	cout << "파일이 존재하지 않음" << endl;
	//}

	path p1("c:/users/한재윤");
	auto begin = recursive_directory_iterator(p1);
	auto end = recursive_directory_iterator();
	for (auto it = begin; it != end; it++) {
		string spacer(it.depth() * 2, ' ');
		auto& entry = *it;
		if (is_regular_file(entry)) {
			cout << spacer << "File: " << entry.path();
			cout << "(" << file_size(entry) << "byte" << endl;
		}
		else if (is_directory(entry)) {
			cout << spacer << "Directory: " << entry.path() << endl;
		}
	}

}