#include "Rider.h"

Rider::Rider()
{
	money = 0;
	earnMoney = 0;
	time = 0;
}

Rider::Rider(float money, float earnMoney, float time)
{
	//�Լ��� ���ڰ� ��������� �̸��� ���� ������ this ���
	this->money = money;
	this->earnMoney = earnMoney;
	this->time = time;
}

Rider::Rider(const Rider& rider)
{
	this->money = rider.money;
	this->earnMoney = rider.earnMoney;
	this->time = rider.time;
}

Rider::~Rider()
{
}

void Rider::deliver(float price, float time)
{
	money += price;
	earnMoney += price;
	this->time += time;
}

ostream& operator <<(ostream& os, const Rider& x)
{
	os << "(money, earnMoney, time) : (" << x.money << ", " << x.earnMoney << ", " << x.time << ")" << endl;
	return os;
}