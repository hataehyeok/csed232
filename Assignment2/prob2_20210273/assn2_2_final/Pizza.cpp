#include "Pizza.h"

Pizza::Pizza()
{
	money = 10000;
	timeA = 10;
	timeB = 20;
	A = Vector_Customer(5);
	B = Vector_Customer(5);
	R = Vector_Rider(5);
	setPrice();
}

Pizza::Pizza(float money)
{
	this->money = money;
	timeA = 10;
	timeB = 20;
	A = Vector_Customer(5);
	B = Vector_Customer(5);
	R = Vector_Rider(5);
	setPrice();
}

Pizza::Pizza(const Pizza& pizza)
{
	money = pizza.money;
	timeA = pizza.timeA;
	timeB = pizza.timeB;
	A = pizza.A;
	B = pizza.B;
	R = pizza.R;
	priceA = pizza.priceA;
	priceB = pizza.priceB;
	feeA = pizza.feeA;
	feeB = pizza.feeA;
}

Pizza::~Pizza()
{
}

void Pizza::setPrice()
{
	priceA = 100 - 3 * A.size();
	priceB = 100 - 6 * B.size();
	feeA = 10 - A.size();
	feeB = 10 - B.size();
}

void Pizza::setPrice(float a, float b)
{
	priceA = 100 - a * A.size();
	priceB = 100 - b * B.size();
	feeA = 10 - A.size();
	feeB = 10 - B.size();
}

void Pizza::hire(const Rider& rider)
{
	R.erase(R.begin());
	R.push_back(rider);
}

void Pizza::hire(const Rider* riders, int size)
{
	for (int i = 0; i < size; i++)
		hire(riders[i]);
}

void Pizza::enroll(const Customer& customer, bool a)
{
	if (a)		//문제 선입선출 조건에 맞게 고객을 등록하는 시스템
	{
		if (A.size() < 9)
		{
			B.erase(B.begin());
			A.push_back(customer);
		}
		else
		{
			A.erase(A.begin());
			A.push_back(customer);
		}
	}
	else
	{
		if (B.size() < 9)
		{
			A.erase(A.begin());
			B.push_back(customer);
		}
		else
		{
			B.erase(B.begin());
			B.push_back(customer);
		}
	}
	setPrice();
}

void Pizza::enroll(const Customer* customers, int size, bool a)
{
	for (int i = 0; i < size; i++)
		enroll(customers[i], a);
	setPrice();
}

int Pizza::numCustomers(bool a) const
{
	if (a)
		return A.size();
	else
		return B.size();
}

float Pizza::meanFee() const
{
	float total_money = 0;
	for (int i = 0; i < 5; i++)
		total_money += R[i].reportMoney();
	return total_money / 5;		//최종 돈을 개수로 나눠서 평균 계산
}

float Pizza::meanTimeRiders() const
{
	float total_time = 0;
	for (int i = 0; i < 5; i++)
		total_time += R[i].reportTime();
	return total_time / 5;		//최종 time을 개수로 나눠서 평균 계산
}

float Pizza::meanMoneyCustomers() const
{
	float total_money = 0;
	for (int i = 0; i < A.size(); i++)
		total_money += A[i].reportMoney();
	for (int i = 0; i < B.size(); i++)
		total_money += B[i].reportMoney();

	return total_money / 10;
}

float Pizza::meanTimeCustomers() const
{
	float total_time = 0;
	for (int i = 0; i < A.size(); i++)
		total_time += A[i].reportTime();
	for (int i = 0; i < B.size(); i++)
		total_time += B[i].reportTime();

	return total_time / 10;
}


void Pizza::deliver()
{
	//Until A region deliver is finished
	int i;
	for (i = 0; i < A.size(); i++)
	{
		A[i].pay(priceA, timeA);
		money += priceA;
		money -= feeA;
		R[i % 5].deliver(feeA, timeA);
	}
	//Until B region deliver is finished
	for (int j = 0; j < B.size(); j++)
	{
		B[j].pay(priceB, timeB);
		money += priceB;
		money -= feeB;
		R[i % 5].deliver(feeB, timeB);
		i++;
	}
}

ostream& operator <<(ostream& os, const Pizza& x)
{
	os << "1) Money : " << x.money << endl;
	os << "2) (Customers, Price, Fee)" << endl;
	os << "- A : (" << x.A.size() << ", " << x.priceA << ", " << x.feeA << ")" << endl;
	os << "- B : (" << x.B.size() << ", " << x.priceB << ", " << x.feeB << ")" << endl;
	os << "3) Riders: " << x.R.size() << endl;

	return os;
}