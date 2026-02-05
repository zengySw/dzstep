#include <iostream>
using namespace std;

class Fraction {
public:
    int num;
    int den;

    void set(int n, int d) {
        num = n;
        den = d;
    }

    void print() {
        cout << num << "/" << den << endl;
    }

    void add(int n2, int d2) {
        int n = num * d2 + n2 * den;
        int d = den * d2;
        cout << "Сумма: " << n << "/" << d << endl;
    }

    void subtract(int n2, int d2) {
        int n = num * d2 - n2 * den;
        int d = den * d2;
        cout << "Разность: " << n << "/" << d << endl;
    }

    void multiply(int n2, int d2) {
        int n = num * n2;
        int d = den * d2;
        cout << "Произведение: " << n << "/" << d << endl;
    }

    void divide(int n2, int d2) {
        int n = num * d2;
        int d = den * n2;
        cout << "Частное: " << n << "/" << d << endl;
    }
};


int main() {
    Fraction f;
    f.set(1, 2); 

    f.print();

    f.add(3, 4);     
    f.subtract(3, 4); 
    f.multiply(3, 4);
    f.divide(3, 4);  
}
