#include "MyVector.h"
#include <iostream>
#include <cstdlib>
using namespace std;

MyVector::MyVector(int n) {
    size = n;
    data = (size > 0) ? new int[size] : nullptr;
}

MyVector::MyVector(const MyVector& other) {
    size = other.size;
    data = (size > 0) ? new int[size] : nullptr;
    for (int i = 0; i < size; i++)
        data[i] = other.data[i];
}

MyVector::MyVector(MyVector&& other) noexcept {
    size = other.size;
    data = other.data;

    other.size = 0;
    other.data = nullptr;
}

MyVector::~MyVector() {
    delete[] data;
}

MyVector& MyVector::operator=(const MyVector& other) {
    if (this == &other)
        return *this;

    delete[] data;
    size = other.size;
    data = (size > 0) ? new int[size] : nullptr;
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

MyVector& MyVector::operator++() {
    int* newData = new int[size + 1];
    for (int i = 0; i < size; i++)
        newData[i] = data[i];
    newData[size] = 0;

    delete[] data;
    data = newData;
    size++;

    return *this;
}

MyVector& MyVector::operator--() {
    if (size == 0) {
        cout << "Ошибка: вектор пуст, нечего удалять!\n";
        return *this;
    }

    int* newData = (size > 1) ? new int[size - 1] : nullptr;
    for (int i = 0; i < size - 1; i++)
        newData[i] = data[i];

    delete[] data;
    data = newData;
    size--;

    return *this;
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
