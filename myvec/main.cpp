#include <iostream>
#include "MyVector.h"
#include <stdexcept>
using namespace std;

int main() {
    srand(int(time(0)));

    int n;
    cout << "Enter vector size: ";
    cin >> n;

    MyVector v1(n), v2(n);

    cout << "\nEnter elements of the first vector:\n";
    v1.input();

    cout << "\nEnter elements of the second vector:\n";
    v2.input();
    try {
    cout << "\nFirst vector: ";
    v1.show();

    cout << "Second vector: ";
    v2.show();

    MyVector v3 = v1 + v2;
    cout << "\nSum of vectors: ";
    v3.show();

    cout << "\nFirst vector in reverse order:\n";
    v1.show_Reversed();

    cout << "\nSize of v1: " << v1.get_Size() << endl;
    cout << "Third element of v1: " << v1.get_Element(2) << endl;

    v1.set_Element(2, 999);
    cout << "After changing the third element:\n";
    v1.show();
    }
    catch (const out_of_range& e) {
        cout << "Range error: " << e.what() << endl;
    }
    catch (const logic_error& e) {
        cout << "Logic error: " << e.what() << endl;
    }
    catch (...) {
        cout << "Unknown error!" << endl;
    }

    return 0;
}
