#include <iostream>
using namespace std;

class ArrayHandler {
private:
    int arr[10];  
    int size;      
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

class Firm {
private:
    double profit[6]; 
public:
    void inputProfit() {
        cout << "Введите прибыль фирмы за 6 месяцев:\n";
        for (int i = 0; i < 6; i++) {
            cout << i + 1 << "-й месяц: ";
            cin >> profit[i];
        }
    }

    double totalProfit() {
        double sum = 0;
        for (int i = 0; i < 6; i++) {
            sum += profit[i];
        }
        return sum;
    }

    void showTotal() {
        cout << "\nОбщая прибыль за 6 месяцев: "
            << totalProfit() << " у.е." << endl;
    }
};

int main() {
	setlocale(LC_ALL, "Russian");
    Firm firm;      
    firm.inputProfit();
    firm.showTotal();

    ArrayHandler arrayObj;  
    arrayObj.inputArray();
    arrayObj.showReversed();
}
