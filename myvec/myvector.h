#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <iostream>
using namespace std;

class MyVector {
private:
    int* data;
    int size;

public:
    MyVector(int n = 0);
    MyVector(const MyVector& other);
    ~MyVector();

    MyVector& operator=(const MyVector& other);
    MyVector operator+(const MyVector& other) const;
    int& operator[](int index);

    void input();
    void show() const;
    void show_Reversed() const;

    int get_Size() const;
    int get_Element(int index) const;
    void set_Element(int index, int value);

    void random(int from, int to);
    void add(int elem);
};

#endif
