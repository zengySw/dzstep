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
    int& operator[](int index);
    MyVector operator+(const MyVector& other) const;

    void input();
    void show() const;
    void showReversed() const;

    friend ostream& operator<<(ostream& out, const MyVector& v);
};

#endif
