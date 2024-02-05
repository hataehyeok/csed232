#include "AVerticalLine.h"
#include <iostream>

AVerticalLine::AVerticalLine()
	:x(0), y_start(0), y_end(0)
{
	alphabet = 'a';
}

AVerticalLine::AVerticalLine(int x_, int y_start_, int y_end_, char alphabet_)
	: x(x_), y_start(y_start_), y_end(y_end_)
{
	alphabet = alphabet_;
}

AVerticalLine::~AVerticalLine()
{
}

void AVerticalLine::draw(WhiteBoard* board) const
{
	for (int i = y_start; i <= y_end; i++)
		board->fillPoint(i, x, alphabet);
}

void AVerticalLine::print() const
{
	std::cout << "AVerticalLine with [alphabet: " << alphabet
	<< "] and [x: " << x << "] [y_start: " << y_start <<  "] [y_end: " << y_end
	<< "] [size: " << size() << "]" << std::endl;
}

int AVerticalLine::size() const
{
	return y_end - y_start + 1;
}