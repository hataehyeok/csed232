#pragma once
#include "AShape.h"
#include "WhiteBoard.h"

class AVerticalLine : public AShape
{
private:
	int x;
	int y_start;
	int y_end;
public:
	AVerticalLine();
	AVerticalLine(int x_, int y_start_, int y_end_, char alphabet_);
	~AVerticalLine();
	void draw(WhiteBoard* board) const;
	void print() const;
	int size() const;
};