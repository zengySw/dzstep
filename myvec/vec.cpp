#include "MyVector.h"
#include <iostream>
#include <stdexcept>
using namespace std;

MyVector::MyVector(int n) {
    if (n < 0)
        throw invalid_argument("Vector size cannot be negative!");
    size = n;
    data = (n > 0) ? new int[n] : nullptr;
}

MyVector::MyVector(const MyVector& other) {
    size = other.size;
    data = (size > 0) ? new int[size] : nullptr;
    for (int i = 0; i < size; ++i)
        data[i] = other.data[i];
}

MyVector::~MyVector() {
    delete[] data;
}

MyVector& MyVector::operator=(const MyVector& other) {
    if (this != &other) {
        delete[] data;
        size = other.size;
        data = (size > 0) ? new int[size] : nullptr;
        for (int i = 0; i < size; ++i)
            data[i] = other.data[i];
    }
    return *this;
}

MyVector MyVector::operator+(const MyVector& other) const {
    if (size != other.size)
        throw logic_error("Vectors must have the same size for addition!");

    MyVector result(size);
    for (int i = 0; i < size; ++i)
        result.data[i] = data[i] + other.data[i];
    return result;
}

int& MyVector::operator[](int index) {
    if (index < 0 || index >= size)
        throw out_of_range("Index out of range!");
    return data[index];
}

void MyVector::input() {
    if (size <= 0)
        throw logic_error("Vector size is zero or negative!");
    for (int i = 0; i < size; ++i)
        cin >> data[i];
}

void MyVector::show() const {
    if (size == 0)
        throw logic_error("Vector is empty!");
    for (int i = 0; i < size; ++i)
        cout << data[i] << " ";
    cout << endl;
}

void MyVector::show_Reversed() const {
    if (size == 0)
        throw logic_error("Vector is empty!");
    for (int i = size - 1; i >= 0; --i)
        cout << data[i] << " ";
    cout << endl;
}

int MyVector::get_Size() const {
    return size;
}

int MyVector::get_Element(int index) const {
    if (index < 0 || index >= size)
        throw out_of_range("Index out of range!");
    return data[index];
}

void MyVector::set_Element(int index, int value) {
    if (index < 0 || index >= size)
        throw out_of_range("Index out of range!");
    data[index] = value;
}

void MyVector::random(int from, int to) {
    if (from > to)
        throw invalid_argument("Invalid range for random generation!");
    for (int i = 0; i < size; ++i)
        data[i] = rand() % (to - from + 1) + from;
}

void MyVector::add(int elem) {
    if (size < 0)
        throw logic_error("Invalid vector state!");
    int* newData = new int[size + 1];
    for (int i = 0; i < size; ++i)
        newData[i] = data[i];
    newData[size] = elem;
    delete[] data;
    data = newData;
    ++size;
}
