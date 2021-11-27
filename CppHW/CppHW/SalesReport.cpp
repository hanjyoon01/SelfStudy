#include "SalesReport.h"
#include <iostream>
using namespace std;
using std::make_unique;

SalesReport::SalesReport()
	:SalesReport(0)
{
}

SalesReport::SalesReport(const size_t& number)
	: m_number(number), averageSales(0.0), highestSales(0.0), team(new Salesman*[m_number])
{
	if (m_number > 0) {

		/*for (size_t i = 0; i < m_number; i++) {
			team[i]->readInput();
		}*/

		cout << "팀 생성 완료" << endl;
	}
	else
		team = nullptr;
}

SalesReport::~SalesReport()
{
	delete[] team;
	team = nullptr;

	if (team == nullptr)
		cout << "메모리 삭제 완료" << endl;
}

void SalesReport::addMember() {
	if (count >= m_number) {
		cout << "Salesman을 추가할 수 없습니다." << endl;
		return;
	}
	string name;
	double sales;
	cout << "이름: ";
	cin >> name;

	cout << "실적: ";
	cin >> sales;

	team[count++] = new Salesman(name, sales);
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

Salesman* SalesReport::getBestClerk()
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
	string info = "인원수 : " + to_string(m_number);
	info += "\n평균 판매량 : " + to_string(averageSales);
	info += "\n최고 판매량 : " + to_string(highestSales) + "\n";

	return info;
}

size_t SalesReport::getNumber()
{
	return m_number;
}

