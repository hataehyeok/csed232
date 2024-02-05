#pragma once
#include "WhiteBoard.h"

//abstract class
class AShape
{
protected:
	char alphabet;
public:
	//Using member initailizer list
	AShape() : alphabet('a') {};
	virtual ~AShape() {};
	virtual void draw(WhiteBoard* board) const = 0;
	virtual void print() const = 0;
	virtual int size() const = 0;
};
