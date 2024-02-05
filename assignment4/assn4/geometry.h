#pragma once
#include <algorithm>
#include <iostream>

using namespace std;

class geometry
{
public:
	virtual void draw2canvas(char** board, char c, int x, int y) = 0;
};

template<typename T, int N>
class point : public geometry
{
private:
	T x, y, sum = 1;		//x point, y point, sum of dimention element
public:
	point(const T* coords);
	~point();		//destructor
	void draw2canvas(char** board, char c, int x_, int y_);
};

template<typename T, int N>
point<T, N>::point(const T* coords)
	:x(coords[0]), y(coords[1])
{
	if (coords[2] != 0)		//포인트 차원 값의 합을 구하는 과정
	{
		sum = 0;
		for (int i = 2; i < N; i++)
			sum += coords[i];
	}
}

template<typename T, int N>
point<T, N>::~point()
{
}

template<typename T, int N>
void point<T, N>::draw2canvas(char** board, char c, int x_, int y_)
{
	if (x <= x_ && y <= y_)		//캔버스를 벗어날 경우 그리지 않음
	{
		if (board[int(y)][int(x)] == c)
			board[int(y)][int(x)] = '0' + (int(sum) % 10);
		else
			board[int(y)][int(x)] = '0' + (((board[int(y)][int(x)] - '0') + int(sum)) % 10);
	}
}


template<typename T>
class rectangle : public geometry
{
private:
	T x1, y1, x2, y2;
public:
	rectangle<T>(T, T, T, T);
	~rectangle();		//destructor
	void draw2canvas(char** board, char c, int x, int y);

	bool is_equal(const rectangle<T>& other);
	bool is_intersect(const rectangle<T>& other);
	bool is_line_overlap(const rectangle<T>& other);
	bool is_point_match(const rectangle<T>& other);
	bool is_disjoint(const rectangle<T>& other);

};

template<typename T>
rectangle<T>::rectangle(T x_1, T y_1, T x_2, T y_2)
	:x1(x_1), y1(y_1), x2(x_2), y2(y_2)
{
	if (x1 == x2 || y1 == y2)		//사각형 넓이가 0인 경우
		throw;
}

template<typename T>
rectangle<T>::~rectangle()
{
}

template<typename T>
void rectangle<T>::draw2canvas(char** board, char c, int x, int y)
{	
	for (int i = int(min(y1, y2)); i <= min(int(max(y1, y2)), y-1); i++)		//최소 좌표부터 최대 좌표까지 반복, 캔버스 벗어나는 경우 고려
	{
		for (int j = int(min(x1, x2)); j <= min(int(max(x1, x2)), x-1); j++)
		{
			if (board[i][j] == c)
				board[i][j] = 1 + '0';
			else
				board[i][j] = '0' + (((board[i][j] - '0') + 1) % 10);
		}
	}
}

template<typename T>
bool rectangle<T>::is_equal(const rectangle<T>& other)
{
	if (minmax(x1, x2) == minmax(other.x1, other.x2) && minmax(y1, y2) == minmax(other.y1, other.y2))
		return true;
	return false;
}

template<typename T>
bool rectangle<T>::is_intersect(const rectangle<T>& other)
{
	if (!is_equal(other))
	{
		//this가 other보다 크거나 같은 경우
		if (min(x1, x2) <= min(other.x1, other.x2) && min(other.x1, other.x2) < max(x1, x2)
			&& min(y1, y2) <= min(other.y1, other.y2) && min(other.y1, other.y2) < max(y1, y2))
		{
			return true;
		}
		else if (min(x1, x2) < max(other.x1, other.x2) && max(other.x1, other.x2) <= max(x1, x2)
			&& min(y1, y2) <= min(other.y1, other.y2) && min(other.y1, other.y2) < max(y1, y2))
		{
			return true;
		}
		else if (min(x1, x2) < max(other.x1, other.x2) && max(other.x1, other.x2) <= max(x1, x2)
			&& min(y1, y2) < max(other.y1, other.y2) && max(other.y1, other.y2) <= max(y1, y2))
		{
			return true;
		}
		else if (min(x1, x2) <= min(other.x1, other.x2) && min(other.x1, other.x2) < max(x1, x2)
			&& min(y1, y2) < max(other.y1, other.y2) && max(other.y1, other.y2) <= max(y1, y2))
		{
			return true;
		}

		//Other가 this보다 크거나 같은 경우
		else if (min(other.x1, other.x2) <= min(x1, x2) && min(x1, x2) < max(other.x1, other.x2)
			&& min(other.y1, other.y2) <= min(y1, y2) && min(y1, y2) < max(other.y1, other.y2))
		{
			return true;
		}
		else if (min(other.x1, other.x2) < max(x1, x2) && max(x1, x2) <= max(other.x1, other.x2)
			&& min(other.y1, other.y2) <= min(y1, y2) && min(y1, y2) < max(other.y1, other.y2))
		{
			return true;
		}
		else if (min(other.x1, other.x2) < max(x1, x2) && max(x1, x2) <= max(other.x1, other.x2)
			&& min(other.y1, other.y2) < max(y1, y2) && max(y1, y2) <= max(other.y1, other.y2))
		{
			return true;
		}
		else if (min(other.x1, other.x2) <= min(x1, x2) && min(x1, x2) < max(other.x1, other.x2)
			&& min(other.y1, other.y2) < max(y1, y2) && max(y1, y2) <= max(other.y1, other.y2))
		{
			return true;
		}
	}
	return false;
}

template<typename T>
bool rectangle<T>::is_line_overlap(const rectangle<T>& other)
{
	if (!is_equal(other) && !is_intersect(other))
	{
		if (max(x1, x2) == min(other.x1, other.x2)
			&& ((min(y1, y2) <= min(other.y1, other.y2) && min(other.y1, other.y2) < max(y1, y2))
				|| (min(y1, y2) < max(other.y1, other.y2) && max(other.y1, other.y2) <= max(y1, y2))
				|| (min(y1, y2) >= min(other.y1, other.y2) && max(other.y1, other.y2) >= max(y1, y2))))
		{
			return true;
		}
		else if (min(y1, y2) == max(other.y1, other.y2)
			&& ((min(x1, x2) <= min(other.x1, other.x2) && min(other.x1, other.x2) < max(x1, x2))
				|| (min(x1, x2) < max(other.x1, other.x2) && max(other.x1, other.x2) <= max(x1, x2))
				|| (min(x1, x2) >= max(other.x1, other.x2) && max(other.x1, other.x2) >= max(x1, x2))))
		{
			return true;
		}
		else if (min(x1, x2) == max(other.x1, other.x2)
			&& ((min(y1, y2) <= min(other.y1, other.y2) && min(other.y1, other.y2) < max(y1, y2))
				|| (min(y1, y2) < max(other.y1, other.y2) && max(other.y1, other.y2) <= max(y1, y2))
				|| (min(y1, y2) >= max(other.y1, other.y2) && max(other.y1, other.y2) >= max(y1, y2))))
		{
			return true;
		}
		else if (max(y1, y2) == min(other.y1, other.y2)
			&& ((min(x1, x2) <= min(other.x1, other.x2) && min(other.x1, other.x2) < max(x1, x2))
				|| (min(x1, x2) < max(other.x1, other.x2) && max(other.x1, other.x2) <= max(x1, x2))
				|| (min(x1, x2) >= max(other.x1, other.x2) && max(other.x1, other.x2) >= max(x1, x2))))
		{
			return true;
		}
	}
	return false;
}

template<typename T>
bool rectangle<T>::is_point_match(const rectangle<T>& other)
{
	if (!is_equal(other) && !is_intersect(other) && !is_line_overlap(other))
	{
		if (max(x1, x2) == min(other.x1, other.x2)
			&& (min(y1, y2) == max(other.y1, other.y2) || max(y1, y2) == min(other.y1, other.y2)))
		{
			return true;
		}
		else if (min(x1, x2) == max(other.x1, other.x2)
			&& (min(y1, y2) == max(other.y1, other.y2) || max(y1, y2) == min(other.y1, other.y2)))
		{
			return true;
		}
	}
	return false;
}

template<typename T>
bool rectangle<T>::is_disjoint(const rectangle<T>& other)
{
	if (!is_equal(other) && !is_intersect(other) && !is_line_overlap(other) && !is_point_match(other))
		return true;
	return false;
}
