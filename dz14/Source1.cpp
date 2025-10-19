#include <iostream>
using namespace std;

class ArrayHandler {
private:
    int arr[10];   // массив из 10 элементов (можно изменить при желании)
    int size;      // фактический размер массива
public:
    void inputArray() {
        cout << "Введите количество элементов массива (до 10): ";
        cin >> size;
        cout << "Введите элементы массива:\n";
        for (int i = 0; i < size; i++) {
            cout << i + 1 << "-й элемент: ";
            cin >> arr[i];
        }
    }

    void showReversed() {
        cout << "\nМассив в обратном порядке:\n";
        for (int i = size - 1; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    ArrayHandler arrayObj;  // создаём объект класса
    arrayObj.inputArray();
    arrayObj.showReversed();

    return 0;
}
