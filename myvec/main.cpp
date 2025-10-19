#include <iostream>
#include "myvector.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "RU");
    int n;
    cout << "Введите размер вектора: ";
    cin >> n;

    MyVector v1(n), v2(n);

    cout << "\nВведите элементы первого вектора:\n";
    v1.input();

    cout << "\nВведите элементы второго вектора:\n";
    v2.input();

    cout << "\nПервый вектор: " << v1 << endl;
    cout << "Второй вектор: " << v2 << endl;

    MyVector v3 = v1 + v2;
    cout << "\nСумма векторов: " << v3 << endl;

    cout << "\nПервый вектор в обратном порядке:\n";
    v1.showReversed();

    cout << "\nДоступ к элементу по индексу [2]: " << v1[2] << endl;

    return 0;
}
