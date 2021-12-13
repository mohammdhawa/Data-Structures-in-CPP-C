#include <iostream>

void ShellSort(int A[], int n) {
	for (int gap = n / 2; gap >= 1; gap /= 2) {
		for (int j = gap; j < n; j++) {
			int temp = A[j];
			int i = j - gap;
			while (i >= 0 && A[i] > temp) {
				A[i + gap] = A[i];
				i = i - gap;
			}
			A[i + gap] = temp;
		}
	}
}

int main()
{

	int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
	int n = sizeof(arr) / sizeof(arr[0]);

	for (int i = 0; i < n; i++)
		std::cout << arr[i] << ' ';
	std::cout << std::endl;

	//QuickSort(arr, 0, n-1);

	//iterative_mergeSort(arr, n);

	//mergeSort(arr, 0, n - 1);

	//countSort(arr, n);

	//bucketSort(arr, n);

	//RadixSort(arr, n);

	ShellSort(arr, n);

	for (int i = 0; i < n; i++)
		std::cout << arr[i] << ' ';
	std::cout << std::endl;


	return 0;
}


