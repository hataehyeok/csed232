#include "AHorizontalLine.h"
#include <iostream>

AHorizontalLine::AHorizontalLine()
	:y(0), x_start(0), x_end(0)
{
	alphabet = 'a';
}

AHorizontalLine::AHorizontalLine(int y_, int x_start_, int x_end_, char alphabet_)
	: y(y_), x_start(x_start_), x_end(x_end_)
{
	alphabet = alphabet_;
}

AHorizontalLine::~AHorizontalLine()
{
}

void AHorizontalLine::draw(WhiteBoard* board) const
{
	for (int i = x_start; i <= x_end; i++)
		board->fillPoint(y, i, alphabet);
}

void AHorizontalLine::print() const
{
	std::cout << "AHorizontalLine with [alphabet: " << alphabet
		<< "] and [y: " << y << "] [x_start: " << x_start << "] [x_end: " << x_end
		<< "] [size: " << size() << "]" << std::endl;
}

int AHorizontalLine::size() const
{
	return x_end - x_start + 1;
}