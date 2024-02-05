#include "WhiteBoard.h"

using namespace std;

WhiteBoard::WhiteBoard()
{
	for (int i = 0; i < 15; i++)		//initailize all index of Whiteboard to '*'
	{
		for (int j = 0; j < 15; j++)
			board[i][j] = '*';
	}
}

WhiteBoard::~WhiteBoard()
{
}

void WhiteBoard::fillPoint(int x, int y, char alphabet)
{
	board[x][y] = alphabet;
}


void WhiteBoard::reset()
{
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
			board[i][j] = '*';
	}
}

void WhiteBoard::display() const
{
	cout << "[WhiteBoard]" << endl << "===============" << endl;

	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
			cout << board[i][j];
		cout << endl;
	}
	cout << "===============" << endl;
}