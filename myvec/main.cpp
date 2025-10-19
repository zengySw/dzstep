#include <iostream>
#include "MyVector.h"
using namespace std;

int main() {
    int n;
    cout << "Введите размер вектора: ";
    cin >> n;

    MyVector v1(n), v2(n);

    cout << "\nВведите элементы первого вектора:\n";
    v1.input();

    cout << "\nВведите элементы второго вектора:\n";
    v2.input();

    cout << "\nПервый вектор: ";
    v1.show();

    cout << "Второй вектор: ";
    v2.show();

    MyVector v3 = v1 + v2;
    cout << "\nСумма векторов: ";
    v3.show();

    cout << "\nПервый вектор в обратном порядке:\n";
    v1.showReversed();

    cout << "\nРазмер вектора v1: " << v1.getSize() << endl;
    cout << "Третий элемент v1: " << v1.getElement(2) << endl;

    v1.setElement(2, 999);
    cout << "После изменения третьего элемента:\n";
    v1.show();

    return 0;
}
