#pragma once
#include<iostream>

class WhiteBoard
{
private:
	char board[15][15];
public:
	WhiteBoard();
	~WhiteBoard();
	void fillPoint(int x, int y, char alphabet);
	void reset();
	void display() const;
};