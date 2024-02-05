#pragma once
#include <iostream>
using namespace std;

class Customer
{
private:
	float money;
	float paidMoney;
	float time;

public:
	Customer();
	Customer(float money, float paidMoney, float time);
	Customer(const Customer& customer);
	~Customer();
	float reportMoney() const { return paidMoney; }
	float reportTime() const { return time; }
	void pay(float price, float time);
	friend ostream& operator <<(ostream& os, const Customer& x);
};