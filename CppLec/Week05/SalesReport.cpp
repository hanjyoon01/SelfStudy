#include "SalesReport.h"
#include <iostream>
using namespace std;
using std::make_unique;

SalesReport::SalesReport()
	:SalesReport(0)
{
}

SalesReport::SalesReport(const size_t& number)
	:m_number(number), averageSales(0.0), highestSales(0.0), team(new shared_ptr<Salesman>[m_number])
{
	if (m_number > 0) {
		//team = new Salesman[m_number];
		//team = make_unique<Salesman[]>(m_number);
		//team = shared_ptr<Salesman[]>(new Salesman[m_number]);

		/*for (size_t i = 0; i < m_number; i++) {
			team[i]->readInput();
		}*/
		cout << "�� ���� �Ϸ�" << endl;
	}
	else
		team = nullptr;
}

SalesReport::~SalesReport()
{
	/*if (team != nullptr) {
		delete[] team;
	}*/
}

void SalesReport::addMember() {
	if (count >= m_number) {
		cout << "Salesman�� �߰��� �� �����ϴ�." << endl;
		return;
	}
	string name;
	double sales;
	cout << "�̸�: ";
	cin >> name;
	
	cout << "����: ";
	cin >> sales;

	team[count++] = make_shared<Salesman>(name, sales);
}

void SalesReport::computeStats()
{
	if (team != nullptr) {
		double sum = team[0]->getSales();
		highestSales = team[0]->getSales();
		for (size_t i = 1; i < count; i++) {
			if (highestSales < team[i]->getSales()) {
				highestSales = team[i]->getSales();
			}
			sum += team[i]->getSales();
		}
		averageSales = sum / m_number;
	}
	
}

shared_ptr<Salesman> SalesReport::getBestClerk()
{
	size_t bestIndex = 0;
	for (size_t i = 1; i < count; i++) {
		if (team[bestIndex]->getSales() < team[i]->getSales()) {
			bestIndex = i;
		}
	}
	return team[bestIndex];
}

string SalesReport::getTeamInfo()
{
	string info = "�ο��� : " + to_string(m_number);
	info += "\n��� �Ǹŷ� : "+ to_string(averageSales);
	info += "\n�ְ� �Ǹŷ� : " + to_string(highestSales)+"\n";

	return info;
}

size_t SalesReport::getNumber()
{
	return m_number;
}

