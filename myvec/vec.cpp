#include "MyVector.h"
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

MyVector MyVector::operator+(const MyVector& other) const {
    if (size != other.size) {
        cout << "Ошибка: размеры векторов не совпадают!" << endl;
        exit(1);
    }

    MyVector result(size);
    for (int i = 0; i < size; i++)
        result.setElement(i, data[i] + other.getElement(i));

    return result;
}

int& MyVector::operator[](int index) {
    if (index < 0 || index >= size) {
        cout << "Ошибка: индекс вне диапазона!" << endl;
        exit(1);
    }
    return data[index];
}

void MyVector::input() {
    cout << "Введите " << size << " элементов:\n";
    for (int i = 0; i < size; i++) {
        cout << i + 1 << "-й элемент: ";
        cin >> data[i];
    }
}

void MyVector::show() const {
    cout << "Элементы вектора: ";
    for (int i = 0; i < size; i++)
        cout << data[i] << " ";
    cout << endl;
}

void MyVector::showReversed() const {
    cout << "Элементы вектора (обратно): ";
    for (int i = size - 1; i >= 0; i--)
        cout << data[i] << " ";
    cout << endl;
}

int MyVector::getSize() const {
    return size;
}

int MyVector::getElement(int index) const {
    if (index < 0 || index >= size) {
        cout << "Ошибка: индекс вне диапазона!" << endl;
        exit(1);
    }
    return data[index];
}

void MyVector::setElement(int index, int value) {
    if (index < 0 || index >= size) {
        cout << "Ошибка: индекс вне диапазона!" << endl;
        exit(1);
    }
    data[index] = value;
}
