#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int> vec, int left, int right, int target) {

	while (left <= right) {
		int mid = (left + right) / 2;
		if (vec[mid] > target)
			right = mid - 1;

		else if (vec[mid] < target)
			left = mid + 1;

		else return mid;
	}
	return -1;
}

int main() {
	vector<int> vec(10);
	for (int i = 0; i < 10; ++ i) {
		vec[i] = i;
	}
	int element = rand() % 10;
	cout << "The element is: " << element << endl;
	int res = binarySearch(vec, 0, vec.size() - 1, element);
	cout << "The position of the element is: " << res;
	return 0;
}
