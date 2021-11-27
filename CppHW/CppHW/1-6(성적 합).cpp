#include <iostream>
#include <string>
#include <sstream>

using namespace std;

namespace jyhan{
	void printName() {
		std::cout << "학번:202011390 이름:한재윤" << std::endl;
	}
}

int main() {

	string mystr;
	int score;
	int sum = 0;
	jyhan::printName();
	cout << endl;
	cout << "Enter your data(name kor eng math) : ";
	getline(cin, mystr);
	
	stringstream ss;
	ss.str(mystr);
	
	int count = 0;
	while (ss >> mystr) {
		if (count == 0) {
			cout << mystr;
			count++;
		}
		else {
			stringstream(mystr) >> score;
			sum += score;
		}
	}
	cout << " : " << sum << endl;
	
	return 0;
}
