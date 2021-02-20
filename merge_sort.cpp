#include<iostream>

template<typename T>
void merge(T* arr, int left, int mid, int right) {
	int i = left;
	int j = mid + 1;
	int k = left;
	T* temp = new T[right - left + 1];
	while (i <= mid && j <= right) {
		if (arr[i] <= arr[j])  temp[k] = arr[i++];

		else temp[k] = arr[j++];
			
		++k;
	}
	while (i <= mid) {
		temp[k++] = arr[i++];
	}

	while (j <= right) {
		temp[k++] = arr[j++];
	}

	for (int p = left; p <= right; ++p) {
		arr[p] = temp[p];
	}
	delete[] temp;
}

template <typename T>
void mergeSort(T* arr, int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
}

int main() {

	int arr[5];

	for (int i = 0; i < 5; ++i) {
		arr[i] = rand() % 100;
	}
	
	std::cout << "Array is:\n";

	for (int i = 0; i < 5; ++i) {
		std::cout << arr[i] << " ";
	}

	mergeSort(arr, 0, 4);

	std::cout << "\n\nSorted array is:\n";
	
	for (int i = 0; i < 5; ++i) {
		std::cout << arr[i] << " ";
	}

	return 0;
}
