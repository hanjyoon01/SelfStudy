#include <iostream>

using namespace std;

namespace jyhan {
	void printName() {
		std::cout << "�й�:202011390 �̸�:������" << std::endl;
	}
}

int main() {

	jyhan::printName();
	cout << endl;

	int sum = 0;
	int i, acount = 0 , lcount = 0;

	while (true) {
		cout << "1)�Ƹ޸�ī��(100��) 2)ī���(200��) 3)���� 4)����\n  �����ϼ��� : ";
		cin >> i;

		if (i == 1) {
			sum += 100;
			acount++;
			cout << "�Ƹ޸�ī�븦 �ֹ��ϼ̽��ϴ�.\n"<<endl;
		}
		else if (i == 2) {
			sum += 200;
			lcount++;
			cout << "ī��󶼸� �ֹ��ϼ̽��ϴ�.\n" << endl;
		}
		else if (i == 3) {
			cout << "=====================" << endl;
			cout << "      �����ݾ�" << endl;
			cout << "=====================" << endl;
			if (acount != 0)
				cout << "�Ƹ޸�ī�� " << acount << "�� " << 100 * acount << "��" << endl;
			if (lcount != 0)
				cout << "ī��� " << lcount << "�� " << 200 * lcount << "��" << endl;
			cout << "=====================" << endl;
			cout << "�� �հ� : " << sum << "��" << endl;
			cout << "=====================\n" << endl;
			cout << "������ �Ϸ�Ǿ����ϴ�." << endl;
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