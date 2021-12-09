#include <iostream>

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void insertionSort(int arr[], int n) {
	for (int i = 1; i < n; i++) {
		int j = i - 1;
		int x = arr[i];
		while (j > -1 && arr[j] > x) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = x;
	}
}

int main()
{

	int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
	int n = sizeof(arr) / sizeof(arr[0]);

	for (int i = 0; i < n; i++)
		std::cout << arr[i] << ' ';
	std::cout << std::endl;

	insertionSort(arr, n);

	for (int i = 0; i < n; i++)
		std::cout << arr[i] << ' ';
	std::cout << std::endl;


	return 0;
}


