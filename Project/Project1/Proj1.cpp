#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <ctime>

using namespace std;

namespace jyhan {
	void printName() {
		std::cout << "  �й�:202011390 �̸�:������" << std::endl;
	}
}

//��ȭ ����ü
struct movie {
	string name; // ����
	int ROW; // ��
	int COL; // ��
	int FS; // ��ü �¼� ��
	int LS; // �ܿ��¼� ��
	int* (*NUM); // �����ȣ
};


// 1)��ȭ ����
void ticketing(movie* (&m), int c) {


	system("cls");

	cout << "\n";
	jyhan::printName();
	cout << "\n";

	int s; //��ȭ ���� �Ű�����
	cout << "========================��ȭ ����========================\n\n";

	//��ȭ ��� ���
	for (int i = 0; i < c; i++) {
		cout << "\t" << i + 1 << ")" << left << setw(20) << m[i].name << "\t\t" << m[i].LS << "/" << m[i].FS << (m[i].LS == 0 ? "(����)" : "") << endl;
	}

	//��ȭ ����
	cout << "\n     ������ ��ȭ�� �����ϼ���(��ȣ): ";
	cin >> s;

	int ROW = m[s - 1].ROW; // ��
	int COL = m[s - 1].COL; // ��

	system("cls");

	cout << "\n";
	jyhan::printName();
	cout << "\n";
	cout << "========================��ȭ ����========================\n\n";

	//�¼� ���
	for (int i = 0; i < COL; i++)
		cout << "  " << '\t' << i + 1;
	cout << "\n\n";

	for (int i = 0; i < ROW; i++) {
		cout << "  " << static_cast<char>('A' + i) << '\t';
		for (int j = 0; j < COL; j++) {
			cout << (m[s - 1].NUM[i][j] == 0 ? "��" : "��") << '\t';
		}
		cout << "\n\n";
	}

	//���� �¼� �Է�
	cout << "  �¼� �Է� (ex ==> A1) : ";
	char x;
	int y;
	cin >> x >> y;

	//�¼� ����
	if (x < 'A' or x >= 'A' + ROW or y < 1 or y > COL) {
		cout << "\n ���� �ڸ��Դϴ�. �ٽ� �Է��ϼ���.\n\n ";
	}
	else {
		int c = 0;
		if (m[s - 1].NUM[x - 'A'][y - 1] != 0) {
			cout << "\n �̹� ���ŵ� �ڸ��Դϴ�. (���Ź�ȣ: " << m[s - 1].NUM[x - 'A'][y - 1] << ")\n\n ";
		}

		//���� ��ȣ �ߺ� ����
		else {
			while (true) {
				m[s - 1].NUM[x - 'A'][y - 1] = rand() % 999 + 1;
				for (int i = 1; i < c; i++) {
					for (int j = 0; j < ROW; j++) {
						for (int k = 0; k < COL; k++) {
							if (m[s - 1].NUM[x - 'A'][y - 1] == m[i].NUM[j][k])
								c++;
						}
					}
				}
				//���� �Ϸ�� �ܿ� �¼� ����
				if (c == 0) {
					cout << "\n ���Ű� �Ϸ�Ǿ����ϴ�. (���Ź�ȣ: " << m[s - 1].NUM[x - 'A'][y - 1] << ")\n\n ";
					m[s - 1].LS--;
					break;
				}
			}
		}
	}
	system("pause");
	system("cls");
}

// 2)���� ���
void ticketcancel(movie* (&m), int c) {

	system("cls");

	int cancelnum; //����� ��ȣ

	cout << "\n";
	jyhan::printName();
	cout << "\n";
	cout << "====================���� ���====================\n\n";
	cout << " ���� ��ȣ�� �Է����ּ���: ";
	cin >> cancelnum;

	int count = 0; //���� ��ȣ ���� ���� Ȯ��

	//���� ��ȣ �� �� ���
	for (int i = 0; i < c; i++) {
		for (int j = 0; j < m[i].ROW; j++) {
			for (int k = 0; k < m[i].COL; k++) {
				if (cancelnum == m[i].NUM[j][k]) {
					cout << "\n ���� ��Ұ� �Ϸ�Ǿ����ϴ�.";
					cout << "(" << m[i].name << ", " << char('A' + j) << k + 1 << ")\n\n ";
					m[i].LS++; //�ܿ��¼� �߰�
					m[i].NUM[j][k] = 0; //���� ��ȣ �ʱ�ȭ
					count++;
					system("pause");
					system("cls");
				}
			}
		}
	}

	//���� ��ȣ �������
	if (count == 0) {
		cout << "\n ���� ��ȣ�� �������� �ʽ��ϴ�.\n\n ";
		system("pause");
		system("cls");
	}
}

// 3)���� Ȯ��
void ticketcheck(movie* (&m), int c) {

	system("cls");
	int checknum; //Ȯ���� ��ȣ
	int count = 0; //���� ��ȣ ���� ���� Ȯ��
	cout << "\n";
	jyhan::printName();
	cout << "\n";
	cout << "====================���� Ȯ��====================\n\n";
	cout << " ���� ��ȣ�� �Է����ּ���: ";
	cin >> checknum;

	//���� ��ȣ �� �� ���� ���
	for (int i = 0; i < c; i++) {
		for (int j = 0; j < m[i].ROW; j++) {
			for (int k = 0; k < m[i].COL; k++) {
				if (checknum == m[i].NUM[j][k]) {

					//���� ���� ���
					cout << "\n �����Ͻ� ��ȭ: " << m[i].name << endl;
					cout << "\n �����Ͻ� �¼�: " << char('A' + j) << k + 1 << "\n\n";
					cout << "====================���� �¼�====================\n\n";

					//���� �¼� ���
					for (int l = 0; l < m[i].COL; l++)
						cout << "  " << '\t' << l + 1;
					cout << "\n\n ";

					for (int y = 0; y < m[i].ROW; y++) {
						cout << "  " << static_cast<char>('A' + y) << '\t';
						for (int z = 0; z < m[i].COL; z++) {
							cout << (checknum == m[i].NUM[y][z] ? "��" : "��") << '\t';
						}
						cout << "\n\n ";
						count++;
					}
					system("pause");
					system("cls");
				}
			}
		}
	}

	//���� ��ȣ �������
	if (count == 0) {
		cout << "\n ���� ��ȣ�� �������� �ʽ��ϴ�.\n\n ";
		system("pause");
		system("cls");
	}
}

int main() {

	int count; //��ȭ ����
	int menu; //�޴� ����

	string name;
	string end;
	ifstream fin("movieinfo.txt");
	srand((unsigned)time(NULL));

	if (!fin.is_open()) {
		cerr << "���� ���� ����" << endl;
		exit(0);
	}

	//��ȭ ���� ����
	fin >> count;
	getline(fin, end);

	//����ü �迭 �����Ҵ�
	movie* moviethr = new movie[count];

	//���Ϸκ��� ��ȭ ����, �¼��� ����
	for (int i = 0; i < count; i++) {
		getline(fin, moviethr[i].name); //��ȭ ���� ����
		fin >> moviethr[i].ROW >> moviethr[i].COL; //��, �� ����
		getline(fin, end);
	}

	//�¼� �� �ʱ�ȭ
	for (int i = 0; i < count; i++) {
		moviethr[i].FS = moviethr[i].LS = moviethr[i].ROW * moviethr[i].COL;
	}

	//���Ź�ȣ �����Ҵ�
	for (int i = 0; i < count; i++) {
		moviethr[i].NUM = new int* [moviethr[i].ROW];
	}
	for (int i = 0; i < count; i++) {
		for (int j = 0; j < moviethr[i].ROW; j++) {
			moviethr[i].NUM[j] = new int[moviethr[i].COL];
		}
	}

	//���Ź�ȣ 0���� �ʱ�ȭ
	for (int i = 0; i < count; i++) {
		for (int j = 0; j < moviethr[i].ROW; j++) {
			for (int k = 0; k < moviethr[i].COL; k++) {
				moviethr[i].NUM[j][k] = 0;
			}
		}
	}

	while (true) {

		cout << "\n";
		jyhan::printName();
		cout << "\n";
		int menu;
		cout << "===========================GGV===========================\n" << endl;
		cout << "  1) ��ȭ ����  2) ���� ���  3) ���� Ȯ��  4) ����\n" << endl;
		cout << "  �޴��� �����ϼ���: ";
		cin >> menu;

		//1�� �޴�
		if (menu == 1) {
			ticketing(moviethr, count);
		}
		//2�� �޴�
		else if (menu == 2) {
			ticketcancel(moviethr, count);
		}
		//3�� �޴�
		else if (menu == 3) {
			ticketcheck(moviethr, count);
		}
		//���� �� �޸� ���� üũ, �޸� ���� �� ����
		else if (menu == 4) {

			_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

			cout << "\n  ��ȭ ���Ÿ� �����մϴ�.\n\n  ";

			//�����Ҵ��� NUM�迭 ����
			for (int i = 0; i < count; i++) {
				for (int j = 0; j < moviethr[i].ROW; j++) {
					delete[] moviethr[i].NUM[j];
				}
				delete[] moviethr[i].NUM;
				moviethr[i].NUM = nullptr;
			}

			//����ü moviethr�迭 ����
			delete[] moviethr;
			moviethr = nullptr;
			return 0;
		}
	}
}