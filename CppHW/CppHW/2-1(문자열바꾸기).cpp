#include <iostream>
#include <string>
#include <fstream>

using namespace std;

namespace jyhan {
	void printName() {
		std::cout << "�й�:202011390 �̸�:������" << std::endl;
	}
}

int main() {

	jyhan::printName();
	cout << endl;

	ifstream fin("testdata.txt");
	if (!fin.is_open()) {
		cerr << "���� �б� ����\n";
		return 1;
	}
	string data;
	while (!fin.eof()) {
		string str;
		getline(fin, str);
		data += str + '\n';
	}
	cout << data << '\n';
	cout << "ã�� ���ڿ��� �Է��ϼ��� : ";
	string findstr;
	getline(cin, findstr);
	cout << "�ٲ� ���ڿ��� �Է��ϼ��� : ";
	string replacestr;
	getline(cin, replacestr);
	cout << endl;
	int startpos = 0;

	size_t pos = data.find(findstr, startpos);
	if (pos == string::npos) {
		cerr << "ã�� ���ڰ� ����" << endl;
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