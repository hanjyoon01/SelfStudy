#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
	vector<string> names{ "ȫ�浿","��浿" ,"��浿" ,"�ڱ浿", "�̱浿" ,"�ڱ浿" };
	vector<string> names2(names.size());

	string name = move(names[0]);

	move(names.begin(), names.end(), names2.begin());
	for_each(names2.begin(), names2.end(), [](const auto& name) {cout << name << endl; });
}