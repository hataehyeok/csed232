#include <iostream>
#include "Vector_Rider.h"

using namespace std;

Vector_Rider::Vector_Rider()
{
	data_size = 0;
	memory_allocation = 0;
	data = NULL;
}

Vector_Rider::Vector_Rider(int size)
{
	data_size = size;
	memory_allocation = size;
	data = new Rider[memory_allocation];
	for (int i = 0; i < data_size; i++)
		data[i] = Rider();		//object array consturct
}

Vector_Rider::Vector_Rider(int size, const Rider& init)
{
	data_size = size;
	memory_allocation = size;
	data = new Rider[memory_allocation];
	for (int i = 0; i < data_size; i++)
		data[i] = init;
}

Vector_Rider::Vector_Rider(int size, const Rider* init)
{
	data_size = size;
	memory_allocation = size;
	data = new Rider[memory_allocation];
	for (int i = 0; i < data_size; i++)
		data[i] = init[i];
}

Vector_Rider::Vector_Rider(const Vector_Rider& v)		//copy constructor
{
	data_size = v.data_size;
	memory_allocation = v.memory_allocation;
	data = new Rider[memory_allocation];
	for (int i = 0; i < data_size; i++)
		data[i] = v.data[i];
}

Vector_Rider::~Vector_Rider()
{
	if (data != NULL)		//When data don't have anything, delete does not work.
		delete[] data;
}

void Vector_Rider::allocate(int capacity)
{
	Rider* data_copy = new Rider[capacity];
	int copy_size = (capacity >= memory_allocation ? memory_allocation : capacity);		//배열에 없는 값이 할당되는 걸 막기 위한 변수

	for (int i = 0; i < copy_size; i++)
		data_copy[i] = data[i];

	delete[] data;

	data = data_copy;
	data_size = (capacity >= memory_allocation ? data_size : capacity);
	memory_allocation = capacity;
}

void Vector_Rider::resize(int size)
{
	allocate(size);

	if (size >= data_size)		//Size가 늘어난 경우 초기화 값을 데이터에 넣어줌
	{
		for (int i = data_size; i < size; i++)
			data[i] = Rider();
		data_size = size;
	}
}

void Vector_Rider::push_back(const Rider& value)
{
	int final_data_size = data_size + 1;    //최종 데이터 개수 = 저장된 데이터 개수 + 추가되는 데이터 개수

	//메모리 할당 규칙
	if (final_data_size >= memory_allocation)
	{
		if (final_data_size < 5) allocate(final_data_size);
		else allocate(final_data_size * 2);
	}
	data[data_size] = value;
	data_size++;
}

void Vector_Rider::pop_back()
{
	data_size--;
}

void Vector_Rider::insert(iterator position, const Rider& value)
{
	int final_data_size = data_size + 1;    //최종 데이터 개수 = 저장된 데이터 개수 + 추가되는 데이터 개수
	int pos = position - data;

	//메모리 할당 규칙
	if (final_data_size >= memory_allocation)
	{
		if (final_data_size < 5) allocate(final_data_size);
		else allocate(final_data_size * 2);
	}

	for (int i = data_size; i > pos; i--) data[i] = data[i - 1];

	data[pos] = value;
	data_size = final_data_size;
}

void Vector_Rider::insert(iterator position, const Rider* first, const Rider* last)
{
	int arr_size = last - first;
	int final_data_size = data_size + arr_size;    //최종 데이터 개수 = 저장된 데이터 개수 + 추가되는 데이터 개수
	int pos = position - data;

	if (final_data_size >= memory_allocation)
	{
		if (final_data_size < 5) allocate(final_data_size);
		else allocate(final_data_size * 2);
	}

	for (int i = data_size + arr_size - 1; i > arr_size - 1; i--)
		data[i] = data[i - arr_size];
	for (int i = 0; i < arr_size; i++)
		data[pos + i] = *(first + i);

	data_size = final_data_size;
}

void Vector_Rider::erase(iterator position)
{
	int pos = position - data;
	for (int i = pos; i < data_size - 1; i++)
		data[i] = data[i + 1];
	data_size--;
}

void Vector_Rider::clear()
{
	data_size = 0;
	memory_allocation = 0;
	delete[] data;
	data = NULL;
}

Vector_Rider& Vector_Rider::operator=(const Vector_Rider& v)
{
	data_size = v.data_size;
	memory_allocation = v.memory_allocation;
	data = new Rider[memory_allocation];

	for (int i = 0; i < data_size; i++)
		data[i] = v.data[i];

	return *this;
}