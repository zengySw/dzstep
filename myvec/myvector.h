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
    void showReversed() const;

    // Геттеры и сеттеры
    int getSize() const;
    int getElement(int index) const;
    void setElement(int index, int value);
};

#endif
