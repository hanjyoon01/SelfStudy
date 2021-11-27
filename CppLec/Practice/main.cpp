#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
	vector<string> names{ "홍길동","김길동" ,"고길동" ,"박길동", "이길동" ,"박길동" };
	vector<string> names2(names.size());

	string name = move(names[0]);

	move(names.begin(), names.end(), names2.begin());
	for_each(names2.begin(), names2.end(), [](const auto& name) {cout << name << endl; });
}