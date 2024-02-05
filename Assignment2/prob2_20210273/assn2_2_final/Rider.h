#pragma once

#include<iostream>
using namespace std;

class Rider
{
private:
	float money;
	float earnMoney;
	float time;

public:
	Rider();
	Rider(float money, float earnMoney, float time);
	Rider(const Rider& rider);
	~Rider();
	float reportMoney() const { return earnMoney; }
	float reportTime() const { return time; }
	void deliver(float price, float time);
	friend ostream& operator <<(ostream& os, const Rider& x);
};