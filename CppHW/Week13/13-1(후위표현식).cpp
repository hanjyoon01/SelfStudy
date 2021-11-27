#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <sstream>

using namespace std;

namespace jyhan {
	void printName() {
		std::cout << "학번:202011390 이름:한재윤" << std::endl;
	}
}

int main() {

	jyhan::printName();
	cout << endl;

	string operation;
	stack<int> num;
	int n1;

	cout << "계산식 입력: ";
	getline(cin, operation);

	istringstream ss(operation);
	string stringBuffer;
	vector<string> op;

	while (getline(ss, stringBuffer, ' ')) {
		op.push_back(stringBuffer);
	}


	for (auto n : op) {

		if (n != "+" && n != "-" && n != "*" && n != "/") {
			num.push(stoi(n));
		}
		else {
			int n1 = num.top();
			num.pop();
			int n2 = num.top();
			num.pop();

			if (n.compare("+") == 0) {
				num.push(n1 + n2);
			}
			else if (n.compare("-") == 0) {
				num.push(n2 - n1);
			}
			else if (n.compare("*") == 0) {
				num.push(n1 * n2);
			}
			else if (n.compare("/") == 0) {
				num.push(n2 / n1);
			}
		}
	}

	cout << "\n값: " << num.top() << endl << endl;
	num.pop();
}