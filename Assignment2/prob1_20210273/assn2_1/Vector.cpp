#include <iostream>
#include "Vector.h"

using namespace std;

Vector::Vector()
{
	data_size = 0;
	memory_allocation = 0;
	data = NULL;
}

Vector::Vector(int size)
{
	data_size = size;
	memory_allocation = size;
	data = new float[memory_allocation];
	for (int i = 0; i < size; i++)
		data[i] = 0;	//Initialization each data element to 0
}

Vector::Vector(int size, const float& init)
{
	data_size = size;
	memory_allocation = size;
	data = new float[memory_allocation];
	for (int i = 0; i < size; i++)
		data[i] = init;		//Initialization each data element to init
}

Vector::Vector(int size, const float* init)
{
	data_size = size;
	memory_allocation = size;
	data = new float[memory_allocation];
	for (int i = 0; i < data_size; i++)
		data[i] = init[i];		//Initialization each data element to each init element
}

Vector::Vector(const Vector& v)		//copy constructor
{
	data_size = v.data_size;
	memory_allocation = v.memory_allocation;
	data = new float[memory_allocation];
	for (int i = 0; i < data_size; i++)
		data[i] = v.data[i];
}

Vector::~Vector()
{
	if (data != NULL)		//When data don't have anything, delete does not work.
		delete[] data;
}

void Vector::allocate(int capacity)
{
	float* data_copy = new float[capacity];
	int copy_size = (capacity >= memory_allocation ? memory_allocation : capacity);		//배열에 없는 값이 할당되는 걸 막기 위한 변수

	for (int i = 0; i < copy_size; i++)
		data_copy[i] = data[i];

	delete[] data;

	data = data_copy;
	data_size = (capacity >= memory_allocation ? data_size : capacity);
	memory_allocation = capacity;
}

void Vector::resize(int size)
{
	allocate(size);

	if (size >= data_size)		//Size가 늘어난 경우 초기화 값을 데이터에 넣어줌
	{
		for (int i = data_size; i < size; i++)
			data[i] = 0;
		data_size = size;
	}
}

void Vector::push_back(const float& value)
{
	int final_data_size = data_size + 1;    //최종 데이터 개수 = 저장된 데이터 개수 + 추가되는 데이터 개수

	if (final_data_size >= memory_allocation)		//메모리 할당 규칙
	{
		if (final_data_size < 5)
			allocate(final_data_size);
		else
			allocate(final_data_size * 2);
	}
	data[data_size] = value;
	data_size++;
}

void Vector::pop_back()
{
	data_size--;
}

void Vector::insert(iterator position, const float& value)
{
	int final_data_size = data_size + 1;    //최종 데이터 개수 = 저장된 데이터 개수 + 추가되는 데이터 개수
	int pos = position - data;		//position의 인덱스를 int값으로 알아내기 위한 변수

	if (final_data_size >= memory_allocation)		//메모리 할당 규칙
	{
		if (final_data_size < 5)
			allocate(final_data_size);
		else
			allocate(final_data_size * 2);
	}

	for (int i = data_size; i > pos; i--)
		data[i] = data[i - 1];

	data[pos] = value;
	data_size = final_data_size;
}

void Vector::insert(iterator position, const float* first, const float* last)
{
	int fin_idx = last - first;
	int final_data_size = data_size + fin_idx;    //최종 데이터 개수 = 저장된 데이터 개수 + 추가되는 데이터 개수
	int pos = position - data;

	if (final_data_size >= memory_allocation)
	{
		if (final_data_size < 5)
			allocate(final_data_size);
		else
			allocate(final_data_size * 2);
	}

	for (int i = data_size + fin_idx - 1; i > fin_idx - 1; i--)
		data[i] = data[i - fin_idx];
	for (int i = 0; i < fin_idx; i++)
		data[pos + i] = *(first + i);

	data_size = final_data_size;
}

void Vector::erase(iterator position)
{
	int pos = position - data;
	for (int i = pos; i < data_size - 1; i++)
		data[i] = data[i + 1];
	data_size--;
}

void Vector::clear()
{
	data_size = 0;
	memory_allocation = 0;
	delete[] data;
	data = NULL;
}

Vector& Vector::operator=(const Vector& v)
{
	data_size = v.data_size;
	memory_allocation = v.memory_allocation;
	data = new float[memory_allocation];

	for (int i = 0; i < data_size; i++)
		data[i] = v.data[i];

	return *this;
}