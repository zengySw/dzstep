#include <iostream>
#include "MyVector.h"
using namespace std;

int main() {
    int n;
    cout << "Введите размер вектора: ";
    cin >> n;

    MyVector v1(n);
    v1.input();

    cout << "\nИсходный вектор: " << v1 << endl;

    ++v1;
    cout << "После ++ (добавлен элемент 0): " << v1 << endl;

    --v1;
    cout << "После -- (удалён последний элемент): " << v1 << endl;

    MyVector v2 = v1; // копирующий конструктор
    cout << "\nСкопированный вектор: " << v2 << endl;

    MyVector v3 = move(v1); // конструктор переноса
    cout << "Перемещённый вектор: " << v3 << endl;

}
