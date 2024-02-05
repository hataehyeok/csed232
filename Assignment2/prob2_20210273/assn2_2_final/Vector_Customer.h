#pragma once
#include "Customer.h"

class Vector_Customer
{
private:
    int data_size;      //데이터 크기
    int memory_allocation;      //메모리할당량
    Customer* data;        //데이터

public:
    typedef Customer* iterator;
    typedef const Customer* const_iterator;

    //constructors
    Vector_Customer();
    Vector_Customer(int size);
    Vector_Customer(int size, const Customer& init);
    Vector_Customer(int size, const Customer* init);
    Vector_Customer(const Vector_Customer& v);

    //distructor
    ~Vector_Customer();

    //methods
    int capacity() const { return memory_allocation; }
    int size() const { return data_size; }
    iterator begin() { return data; }
    const_iterator begin() const { return data; }
    iterator end() { return data + data_size; }
    const_iterator end() const { return data + data_size; }
    Customer& front() { return *data; }
    const Customer& front() const { return *data; }
    Customer& back() { return *(data + data_size); }
    const Customer& back() const { return *(data + data_size); }
    void allocate(int capacity);
    void resize(int size);
    void push_back(const Customer& value);
    void pop_back();
    void insert(iterator position, const Customer& value);
    void insert(iterator position, const Customer* first, const Customer* last);
    void erase(iterator position);
    void clear();
    Customer& operator[](int index){ return data[index]; }
    const Customer& operator[](int index) const{ return data[index]; }
    Vector_Customer& operator=(const Vector_Customer& v);
};