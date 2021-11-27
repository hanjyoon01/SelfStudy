#include <iostream>

using namespace std;

namespace jyhan {
	void printName() {
		std::cout << "학번:202011390 이름:한재윤" << std::endl;
	}
}

int main() {

	jyhan::printName();
	cout << endl;

	int sum = 0;
	int i, acount = 0 , lcount = 0;

	while (true) {
		cout << "1)아메리카노(100원) 2)카페라떼(200원) 3)결제 4)종료\n  선택하세요 : ";
		cin >> i;

		if (i == 1) {
			sum += 100;
			acount++;
			cout << "아메리카노를 주문하셨습니다.\n"<<endl;
		}
		else if (i == 2) {
			sum += 200;
			lcount++;
			cout << "카페라떼를 주문하셨습니다.\n" << endl;
		}
		else if (i == 3) {
			cout << "=====================" << endl;
			cout << "      결제금액" << endl;
			cout << "=====================" << endl;
			if (acount != 0)
				cout << "아메리카노 " << acount << "잔 " << 100 * acount << "원" << endl;
			if (lcount != 0)
				cout << "카페라떼 " << lcount << "잔 " << 200 * lcount << "원" << endl;
			cout << "=====================" << endl;
			cout << "총 합계 : " << sum << "원" << endl;
			cout << "=====================\n" << endl;
			cout << "결제가 완료되었습니다." << endl;
			cout << "===================================\n" << endl;

			sum = 0;
			acount = 0;
			lcount = 0;
		}
		else if (i == 4)
			break;
	}
	return 0;
}