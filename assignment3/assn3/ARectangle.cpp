#include "ARectangle.h"
#include <iostream>

ARectangle::ARectangle()
	:x_start(0), x_end(0), y_start(0), y_end(0)
{
	alphabet = 'a';
}

ARectangle::ARectangle(int x_start_, int x_end_, int y_start_, int y_end_, char alphabet_)
	: x_start(x_start_), x_end(x_end_), y_start(y_start_), y_end(y_end_)
{
	alphabet = alphabet_;
}

ARectangle::~ARectangle()
{
}

void ARectangle::draw(WhiteBoard* board) const
{
	for (int i = x_start; i <= x_end; i++)
	{
		for(int j = y_start; j <= y_end; j++)
			board->fillPoint(j, i, alphabet);
	}
}

void ARectangle::print() const
{
	std::cout << "ARectangle with [alphabet: " << alphabet
		<< "] and [x_start: " << x_start << "] [x_end: " << x_end
		<< "] [y_start: " << y_start << "] [y_end: " << y_end
		<< "] [size: " << size() << "]" << std::endl;
}

int ARectangle::size() const
{
	return (x_end - x_start + 1) * (y_end - y_start + 1);
}