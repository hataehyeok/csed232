#pragma once
#include "AShape.h"
#include "WhiteBoard.h"

class APoint : public AShape
{
private:
	int x;
	int y;
public:
	APoint();
	APoint(int x_, int y_, char alphabet_);
	~APoint();
	void draw(WhiteBoard* board) const;
	void print() const;
	int size() const;
};