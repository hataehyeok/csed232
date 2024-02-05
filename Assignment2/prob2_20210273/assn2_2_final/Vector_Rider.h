#pragma once
#include "Rider.h"

class Vector_Rider
{
private:
    int data_size;      //데이터 크기
    int memory_allocation;      //메모리할당량
    Rider* data;        //데이터

public:
    typedef Rider* iterator;
    typedef const Rider* const_iterator;

    //constructors
    Vector_Rider();
    Vector_Rider(int size);
    Vector_Rider(int size, const Rider& init);
    Vector_Rider(int size, const Rider* init);        //function default argument랑 construct의 default argument는 다른가?
    Vector_Rider(const Vector_Rider& v);

    //distructor
    ~Vector_Rider();

    //methods
    int capacity() const { return memory_allocation; }
    int size() const { return data_size; }
    iterator begin() { return data; }
    const_iterator begin() const { return data; }
    iterator end() { return data + data_size; }
    const_iterator end() const { return data + data_size; }
    Rider& front() { return *data; }
    const Rider& front() const { return *data; }
    Rider& back() { return *(data + data_size); }
    const Rider& back() const { return *(data + data_size); }
    void allocate(int capacity);
    void resize(int size);
    void push_back(const Rider& value);
    void pop_back();
    void insert(iterator position, const Rider& value);
    void insert(iterator position, const Rider* first, const Rider* last);
    void erase(iterator position);
    void clear();
    Rider& operator[](int index) { return data[index]; }
    const Rider& operator[](int index) const { return data[index]; }
    Vector_Rider& operator=(const Vector_Rider& v);
};