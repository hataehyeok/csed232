#ifndef VECTOR_H_
#define VECTOR_H_

class Vector
{
private:
    int data_size;      //데이터 크기
    int memory_allocation;      //메모리할당량
    float* data;        //데이터

public:
    typedef float* iterator;
    typedef const float* const_iterator;

    //constructors
    Vector();
    Vector(int size);
    Vector(int size, const float& init);
    Vector(int size, const float* init);
    Vector(const Vector& v);

    //distructor
    ~Vector();

    //methods
    int capacity() const { return memory_allocation; }
    int size() const { return data_size; }
    iterator begin() { return data; }
    const_iterator begin() const { return data; }
    iterator end() { return data + data_size; }
    const_iterator end() const { return data + data_size; }
    float& front() { return *data; }
    const float& front() const { return *data; }
    float& back() { return *(data + data_size - 1); }
    const float& back() const { return *(data + data_size - 1); }
    void allocate(int capacity);
    void resize(int size);
    void push_back(const float& value);
    void pop_back();
    void insert(iterator position, const float& value);
    void insert(iterator position, const float* first, const float* last);
    void erase(iterator position);
    void clear();
    float& operator[](int index) { return data[index]; }
    const float& operator[](int index) const { return data[index]; }
    Vector& operator=(const Vector& v);
};

#endif