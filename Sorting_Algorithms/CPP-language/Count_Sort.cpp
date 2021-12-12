#include <iostream>

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

int findMax(int A[], int n) {
	int mx = A[0];
	for (int i = 1; i < n; i++) {
		if (mx < A[i])
			mx = A[i];
	}
	return mx;
}

void countSort(int A[], int n) {
	int max;
	int* c;
	max = findMax(A, n);
	c = new int[max + 1];

	int i, j;
	for (i = 0; i < max + 1; i++)
		c[i] = 0;

	for (i = 0; i < n; i++)
		c[A[i]]++;

	i = 0; 
	j = 0; 

	while (i < max + 1) {
		if (c[i] > 0) {
			A[j++] = i;
			c[i]--;
		}
		else
			i++;
	}
	delete[] c;
}

int main()
{

	int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
	int n = sizeof(arr) / sizeof(arr[0]);

	for (int i = 0; i < n; i++)
		std::cout << arr[i] << ' ';
	std::cout << std::endl;

	countSort(arr, n);

	for (int i = 0; i < n; i++)
		std::cout << arr[i] << ' ';
	std::cout << std::endl;


	return 0;
}
