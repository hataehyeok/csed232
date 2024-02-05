#pragma once
#include "AShape.h"
#include "WhiteBoard.h"

class ARectangle : public AShape
{
private:
	int x_start;
	int x_end;
	int y_start;
	int y_end;
public:
	ARectangle();
	ARectangle(int x_start_, int x_end_, int y_start_, int y_end_, char alphabet_);
	~ARectangle();
	void draw(WhiteBoard* board) const;
	void print() const;
	int size() const;
};