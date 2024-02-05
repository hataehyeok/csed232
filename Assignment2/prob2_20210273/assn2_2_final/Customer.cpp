#include "Customer.h"

Customer::Customer()
{
	money = 1000;
	paidMoney = 0;
	time = 0;
}

Customer::Customer(float money, float paidMoney, float time)
{
	//�Լ��� ���ڰ� ��������� �̸��� ���� ������ this ���
	this->money = money;
	this->paidMoney = paidMoney;
	this->time = time;
}

Customer::Customer(const Customer& customer)
{
	this->money = customer.money;
	this->paidMoney = customer.paidMoney;
	this->time = customer.time;
}

Customer::~Customer()
{
}

void Customer::pay(float price, float time)
{
	money -= price;
	paidMoney += price;
	this->time += time;
}

ostream& operator <<(ostream& os, const Customer& x)
{
	os << "(money, paidMoney, time) : (" << x.money << ", " << x.paidMoney << ", " << x.time << ")" << endl;
	return os;
}