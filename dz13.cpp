#include <iostream>
using namespace std;

class Sorter {
private:
    int* arr;
    int size;

public:
    Sorter(int* input_arr, int arr_size) {
        arr = input_arr;
        size = arr_size;
    }

    void bubble_sort_desc() {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (arr[j] < arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    void print_array() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int numbers[7] = {5, 2, 9, 1, 7, 3, 8};

    Sorter sorter(numbers, 7);

    cout << "Before sorting: ";
    sorter.print_array();

    sorter.bubble_sort_desc();

    cout << "After sorting (descending): ";
    sorter.print_array();

}
