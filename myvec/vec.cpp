#include "MyVector.h"
#include <iostream>
#include <cstdlib>
//#include <>
using namespace std;

MyVector::MyVector(int n) {
    size = n;
    if (size > 0)
        data = new int[size];
    else
        data = nullptr;
}

MyVector::MyVector(const MyVector& other) {
    size = other.size;
    data = new int[size];
    for (int i = 0; i < size; i++)
        data[i] = other.data[i];
}

MyVector::~MyVector() {
    delete[] data;
}

MyVector& MyVector::operator=(const MyVector& other) {
    if (this != &other) {
        int* newData = new int[other.size];
        for (int i = 0; i < other.size; i++)
            newData[i] = other.data[i];
        delete[] data;
        data = newData;
        size = other.size;
    }
    return *this;

}

MyVector MyVector::operator+(const MyVector& other) const {
    if (size != other.size)
        throw std::invalid_argument("Vectors must be of the same size to add.");

    MyVector result(size);
    for (int i = 0; i < size; i++)
        result.set_Element(i, data[i] + other.get_Element(i));

    return result;
}


int& MyVector::operator[](int index) {
    if (index >= size)
        throw std::out_of_range("Index out of range");
    return data[index];

}

void MyVector::input() {
    cout << "enter " << size << " elements:\n";
    for (int i = 0; i < size; i++) {
        cout << i + 1 << " element: ";
        cin >> data[i];
    }
}

void MyVector::show() const {
    cout << "vector elements: ";
    for (int i = 0; i < size; i++)
        cout << data[i] << " ";
    cout << endl;
}

void MyVector::show_Reversed() const {
    cout << "vector elements (reversed): ";
    for (int i = size - 1; i >= 0; i--)
        cout << data[i] << " ";
    cout << endl;
}

int MyVector::get_Size() const {
    return size;
}

int MyVector::get_Element(int index) const {
    if (index < 0 || index >= size) throw std::out_of_range("Index out of range");
    return data[index];
}

void MyVector::set_Element(int index, int value) {
    if (index < 0 || index >= size) throw std::out_of_range("Index out of range");
    data[index] = value;
}

void MyVector::random(int from, int to) {
    for (int i = 0; i < size; i++)
    {
        data[i] = from + rand() % to;
    }
}
void MyVector::add(int elem) {
    int* temp = new int[size + 1];
    for (int i = 0; i = size + 1; i++) {
        temp[i] = data[i];
    }
    temp[size] = elem;
    delete[] data;

    size += 1;
    data = temp;
}