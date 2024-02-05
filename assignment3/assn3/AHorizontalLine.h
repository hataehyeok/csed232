#pragma once
#include "AShape.h"
#include "WhiteBoard.h"

class AHorizontalLine : public AShape
{
private:
	int y;
	int x_start;
	int x_end;
public:
	AHorizontalLine();
	AHorizontalLine(int y_, int x_start_, int x_end_, char alphabet_);
	~AHorizontalLine();
	void draw(WhiteBoard* board) const;
	void print() const;
	int size() const;
};