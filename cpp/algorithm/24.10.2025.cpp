#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void bubble_sort(int array[], long array_size) {
	long i, j;
	int temp_val;
	for (i = 0; i < array_size; i++) {
		for (j = array_size - 1; j > i; j--) {
			if (array[j - 1] > array[j]) {
				temp_val = array[j - 1];
				array[j - 1] = array[j];
				array[j] = temp_val;
			}
		}
	}
}


int search_array(int array[], int lower_bound, int upper_bound, int search_key)
{
	int middle;
	while (1) {
		middle = (lower_bound + upper_bound) / 2;
		if (search_key < array[middle])
			upper_bound = middle - 1;
		else if (search_key > array[middle])
			lower_bound = middle + 1;
		else
			return middle;

		if (lower_bound > upper_bound)
			return -1;
	}
}

void print_array(int array[], int array_size)
{
	for (int i = 0; i < array_size; i++) {

		cout << array[i] << " ";
	}
	cout << endl;
}

void main() {
	srand(time(NULL));
	const long array_size = 10;
	int array[array_size];
	int search_key, found_index;

	for (int i = 0; i < array_size; i++) {
		array[i] = rand() % 20;
	}
	print_array(array, array_size);
	bubble_sort(array, array_size);
	print_array(array, array_size);
	cout << "\n\n";
	cout << "Enter any digit:";
	cin >> search_key;
	found_index = search_array(array, 0, array_size, search_key);
	cout << "Index: " << found_index << endl;
	cout << "\n\n";
}