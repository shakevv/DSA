#include<iostream>


void countingSort(int* arr, size_t size, size_t range) {
	int* res = new int[size];
	int* count_arr = new int [range];
	for (int i = 0; i < range; ++i) {
		count_arr[i] = 0;
	}
	for (int i = 0; i < size; ++i) {
		++count_arr[arr[i]];
	}
	for (int i = 1; i < range; ++i) {
		count_arr[i] += count_arr[i - 1];
	}
	for (int i = 0; i < size; ++i) {
		res[--count_arr[arr[i]]] = arr[i];
	}
	for (int i = 0; i < size; ++i) {
		arr[i] = res[i];
	}
	delete[] res;
	delete[] count_arr;
}
int main() {
	size_t size = 7;
	size_t range = 10;
	
	int* arr = new int[size];
	for (int i = 0; i < size; ++i) {
		arr[i] = rand() % 10;
	}
	std::cout << "Array is: ";
	for (int i = 0; i < size; ++i) {
		std::cout << arr[i] << " ";
	}
	countingSort(arr, size, range);
	std::cout << "\nSorted array is: ";
	for (int i = 0; i < size; ++i) {
		std::cout << arr[i] << " ";
	}
	delete[] arr;
	return 0;
}