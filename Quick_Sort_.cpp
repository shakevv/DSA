#include<iostream>

template<typename T>
int partition(T* arr, int start, int end) {
	int pIdx = start;
	T pivot = arr[end];
	for (int i = start; i < end; ++i) {
		if (arr[i] < pivot) {
			std::swap(arr[i], arr[pIdx++]);
		}
	}
	std::swap(arr[end], arr[pIdx]);
	return pIdx;
}


template <typename T>
void quickSort(T* arr, int start, int end) {
	if (start < end) {
		int p = partition(arr, start, end);
		quickSort(arr, start, --p);
		quickSort(arr, ++p, end);
	}
}


int main() {
	int arr[5];
	for (int i = 0; i < 5; ++i) {
		arr[i] = rand() % 10;
	}
	std::cout << "The array is: \n";
	for (int i = 0; i < 5; ++i) {
		std::cout << arr[i] << " ";
	}
	quickSort(arr, 0, 4);

	std::cout << "Sorted array is: \n";
	for (int i = 0; i < 5; ++i) {
		std::cout << arr[i] << " ";
	}

	return 0;
}