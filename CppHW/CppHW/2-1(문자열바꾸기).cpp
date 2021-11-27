#include <iostream>
#include <string>
#include <fstream>

using namespace std;

namespace jyhan {
	void printName() {
		std::cout << "학번:202011390 이름:한재윤" << std::endl;
	}
}

int main() {

	jyhan::printName();
	cout << endl;

	ifstream fin("testdata.txt");
	if (!fin.is_open()) {
		cerr << "파일 읽기 실패\n";
		return 1;
	}
	string data;
	while (!fin.eof()) {
		string str;
		getline(fin, str);
		data += str + '\n';
	}
	cout << data << '\n';
	cout << "찾을 문자열을 입력하세요 : ";
	string findstr;
	getline(cin, findstr);
	cout << "바꿀 문자열을 입력하세요 : ";
	string replacestr;
	getline(cin, replacestr);
	cout << endl;
	int startpos = 0;

	size_t pos = data.find(findstr, startpos);
	if (pos == string::npos) {
		cerr << "찾는 문자가 없음" << endl;
	}
	else {
		while (pos != string::npos) {
			data = data.replace(pos, findstr.length(), replacestr);
			pos = data.find(findstr, startpos);
		}
	}
	cout << data << '\n';

	return 0;
}