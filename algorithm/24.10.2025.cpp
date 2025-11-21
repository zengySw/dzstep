#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void bubbleSort(int a[], long size) {
	long i, j;
	int x;
	for (i = 0; i < size; i++) {        
		for (j = size - 1; j > i; j--) { 
			if (a[j - 1] > a[j]) {
				x = a[j - 1];
				a[j - 1] = a[j];
				a[j] = x;
			}
		}
	}
}


int Search(int A[], int Lb, int Ub, int Key)
{
	int M;
	while (1) {
		M = (Lb + Ub) / 2;
		if (Key < A[M])
			Ub = M - 1;
		else if (Key > A[M])
			Lb = M + 1;
		else
			return M;

		if (Lb > Ub)
			return -1;
	}
}

void Print(int arr[], int SIZE)
{
	for (int i = 0; i < SIZE; i++) {

		cout << arr[i] << " ";
	}
	cout << endl;
}

void main() {
	srand(time(NULL));
	const long SIZE = 10;
	int arr[SIZE];
	int key, index;

	for (int i = 0; i < SIZE; i++) {
		arr[i] = rand() % 20;
	}
	Print(arr, SIZE);
	bubbleSort(arr, SIZE);
	Print(arr, SIZE);
	cout << "\n\n";
	cout << "Enter any digit:";
	cin >> key;
	index = Search(arr, 0, SIZE, key);
	cout << "Index: " << index << endl;
	cout << "\n\n";
}

