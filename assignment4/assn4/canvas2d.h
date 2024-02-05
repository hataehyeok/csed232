#pragma once
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include "geometry.h"

using vg = std::vector<geometry*>;
using namespace std;

class canvas2d : public vg
{
public:
	int x, y;			//store the x-y size of board
	char c;				//letter that insert the empty space
	char** board;		//2-dimention canvas

	canvas2d(int width, int height, char c_empty);
	~canvas2d();		//destructor
	canvas2d& operator=(const canvas2d& can);		//assignment operator to deep copy
	void draw2stdout();			//print to stdout
};

canvas2d::canvas2d(int width, int height, char c_empty)
	:x(width), y(height), c(c_empty)
{
	board = new char* [y];		//enitialize the board
	for (int i = 0; i < y; i++)
		board[i] = new char[x];

	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
			board[i][j] = c;
	}
}

canvas2d::~canvas2d()
{
	for (int i = 0; i < y; i++)
		delete board[i];
	delete board;
}

canvas2d& canvas2d::operator=(const canvas2d& can)
{
	for (int i = 0; i < y; i++)
		delete board[i];
	delete board;

	x = can.x;
	y = can.y;
	c = can.c;
	//deep copy
	char** board = new char* [y];
	for (int i = 0; i < y; i++)
		board[i] = new char[x];

	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
			board[i][j] = c;
	}

	return *this;
}

void canvas2d::draw2stdout()
{
	vector<geometry*>::iterator i;			//Iterator를 사용해서 각 geometry 접근
	for (i = begin(); i != end(); i++)
	{
		(*i)->draw2canvas(board, c, x, y);
	}

	for (int i = 0; i < y; i++)			//수정된 board 최종 출력
	{
		for (int j = 0; j < x; j++)
			cout << board[i][j];
		cout << endl;
	}
}

class parser
{
public:
	canvas2d parse_canvas(const std::string& line);
	geometry* parse_geometry(const std::string& line);
};

canvas2d parser::parse_canvas(const std::string& line)
{
	stringstream ss(line);
	string temp;
	vector<string> v;			//반점을 기준으로 나눠서 벡터에 저장

	while (getline(ss, temp, ','))
		v.push_back(temp);

	int x = stoi(v[0]);			//typecast from string to int
	int y = stoi(v[1]);
	string str = v[2];
	const char* c_ = str.c_str();
	char c = *c_;				//typecast from string to char

	return canvas2d(x, y, c);
}

geometry* parser::parse_geometry(const std::string& line)
{
	stringstream ss(line);
	string temp;
	vector<string> v;

	while (getline(ss, temp, ','))
		v.push_back(temp);

	if (v[0] == "point")		//case of point
	{
		if (v[1] == "int")		//int case
		{
			int arr[5] = {0,};
			for (int i = 2; i < v.size(); i++)
			{
				arr[i - 2] = stoi(v[i]);
			}
			geometry* temp = new point<int, 5>(arr);
			return temp;
		}
					//float case
		else
		{
			float arr[5] = { 0, };
			for (int i = 2; i < v.size(); i++)
			{
				arr[i - 2] = stof(v[i]);
			}
			geometry* temp = new point<float, 5>(arr);
			return temp;
		}
	}
	else		//case of rectangle
	{
		if (v[1] == "int")
		{
			geometry* temp = new rectangle<int>(stoi(v[2]), stoi(v[3]), stoi(v[4]), stoi(v[5]));
			return temp;
		}
		else
		{
			geometry* temp = new rectangle<float>(stof(v[2]), stof(v[3]), stof(v[4]), stof(v[5]));
			return temp;
		}
	}
}