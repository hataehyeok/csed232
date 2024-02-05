#include "APoint.h"
#include <iostream>

using namespace std;

APoint::APoint()
	:x(0), y(0)
{
	alphabet = 'a';
}

APoint::APoint(int x_, int y_, char alphabet_)
	:x(x_), y(y_)
{
	alphabet = alphabet_;
}

APoint::~APoint()
{
}

void APoint::draw(WhiteBoard* board) const
{
	board->fillPoint(y, x, alphabet);
}

void APoint::print() const
{
	cout << "APoint with [alphabet: " << alphabet;
	cout << "] and [x: " << x << " ] [y: " << y << "] [size: " << size() << "]" << endl;
}

int APoint::size() const
{
	return 1;
}