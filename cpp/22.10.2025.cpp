#include <iostream>
using namespace std;

template <typename T>
class Compare {
public:
    T getMax(T a, T b) {
        return (a > b) ? a : b;
    }

    T getMin(T a, T b) {
        return (a < b) ? a : b;
    }
};

int main() {
    Compare<int> c1;
    Compare<double> c2;

    cout << "Max (int): " << c1.getMax(10, 20) << endl;
    cout << "Min (int): " << c1.getMin(10, 20) << endl;

    cout << "Max (double): " << c2.getMax(3.14, 2.71) << endl;
    cout << "Min (double): " << c2.getMin(3.14, 2.71) << endl;

    return 0;
}
