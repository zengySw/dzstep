#include <iostream>
using namespace std;

void sortArray(int arr[], int size, int direction = 1) {
    for (int i = 0; i < size - 1; ++i) {
        int targetIndex = i;

        for (int j = i + 1; j < size; ++j) {

            if (direction == 0) {
                if (arr[j] < arr[targetIndex]) {
                    targetIndex = j;
                }
            }
            else if (direction == 1) {
                if (arr[j] > arr[targetIndex]) {
                    targetIndex = j;
                }
            }
        }

        if (targetIndex != i) {
            int temp = arr[i];
            arr[i] = arr[targetIndex];
            arr[targetIndex] = temp;
        }
    }

    if (direction == 1) {
        cout << "Array sorted in descending order (Selection Sort)." << endl;
    }
    else if (direction == 0) {
        cout << "Array sorted in ascending order (Selection Sort)." << endl;
    }
}

void printArray(const int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << (i == size - 1 ? "" : " ");
    }
    cout << endl;
}

int main() {

    const int ARRAY_SIZE = 10;

    int data1[ARRAY_SIZE] = { 5, 2, 9, 1, 5, 6, 3, 8, 0, 7 };
    int data2[ARRAY_SIZE] = { 5, 2, 9, 1, 5, 6, 3, 8, 0, 7 };

    cout << "Initial array: ";
    printArray(data1, ARRAY_SIZE);

    cout << "Default Sort (Descending)" << endl;
    sortArray(data1, ARRAY_SIZE);
    cout << "Result: ";
    printArray(data1, ARRAY_SIZE);

    cout << " Ascending Sort (direction = 0) " << endl;
    sortArray(data2, ARRAY_SIZE, 0);
    cout << "Result: ";
    printArray(data2, ARRAY_SIZE);

    return 0;
}