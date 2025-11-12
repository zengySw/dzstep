#include <iostream>
using namespace std;

template <typename T>
class Matrix {
private:
    T data[10][10];
    int size;

public:
    Matrix() {
        size = 0;
    }

    Matrix(int n) {
        size = n;
    }

    void initMatrix() {
        cout << "Enter elements for " << size << "x" << size << " matrix:\n";
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                cin >> data[i][j];
            }
        }
    }

    void printMatrix() {
        cout << "\nMatrix " << size << "x" << size << ":\n";
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                cout << data[i][j] << "\t";
            }
            cout << endl;
        }
    }
};

int main() {
    int n;
    cout << "Enter matrix size (max 10): ";
    cin >> n;

    Matrix<int> m(n);
    m.initMatrix();
    m.printMatrix();

}
