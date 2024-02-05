#pragma once

#include <iostream>
#include "Vector_Customer.h"
#include "Vector_Rider.h"
#include "Customer.h"
#include "Rider.h"


using namespace std;

class Pizza
{
private:
	float money;
	float priceA;
	float priceB;
	float feeA;
	float feeB;
	float timeA;
	float timeB;
	Vector_Customer A;
	Vector_Customer B;
	Vector_Rider R;

public:
	Pizza();
	Pizza(float money);
	Pizza(const Pizza& pizza);
	~Pizza();
	void setPrice();
	void setPrice(float a, float b);
	void hire(const Rider& rider);
	void hire(const Rider* riders, int size);
	void enroll(const Customer& customer, bool a);
	void enroll(const Customer* customers, int size, bool a);
	float reportMoney() const { return money; }
	int numRiders() const { return R.size(); }
	int numCustomers(bool a) const;
	float meanFee() const;
	float meanTimeRiders() const;
	float meanMoneyCustomers() const;
	float meanTimeCustomers() const;
	void deliver();
	friend ostream& operator <<(ostream& os, const Pizza& x);
};