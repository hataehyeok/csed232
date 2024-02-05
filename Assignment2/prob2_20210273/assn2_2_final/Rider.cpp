#include "Rider.h"

Rider::Rider()
{
	money = 0;
	earnMoney = 0;
	time = 0;
}

Rider::Rider(float money, float earnMoney, float time)
{
	//함수의 인자가 멤버변수와 이름이 같기 때문에 this 사용
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