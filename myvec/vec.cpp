#include "myvector.h"
#include <iostream>
#include <cstdlib>
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
    if (this == &other)
        return *this;

    delete[] data;
    size = other.size;
    data = new int[size];
    for (int i = 0; i < size; i++)
        data[i] = other.data[i];
    return *this;
}

int& MyVector::operator[](int index) {
    if (index < 0 || index >= size) {
        cout << "Ошибка: индекс вне диапазона!\n";
        exit(1);
    }
    return data[index];
}

MyVector MyVector::operator+(const MyVector& other) const {
    if (size != other.size) {
        cout << "Ошибка: разные размеры векторов!\n";
        exit(1);
    }
    MyVector result(size);
    for (int i = 0; i < size; i++)
        result.data[i] = data[i] + other.data[i];
    return result;
}

void MyVector::input() {
    cout << "Введите " << size << " элементов:\n";
    for (int i = 0; i < size; i++) {
        cout << i + 1 << "-й элемент: ";
        cin >> data[i];
    }
}

void MyVector::show() const {
    for (int i = 0; i < size; i++)
        cout << data[i] << " ";
    cout << endl;
}

void MyVector::showReversed() const {
    for (int i = size - 1; i >= 0; i--)
        cout << data[i] << " ";
    cout << endl;
}

ostream& operator<<(ostream& out, const MyVector& v) {
    for (int i = 0; i < v.size; i++)
        out << v.data[i] << " ";
    return out;
}
