#include <stdio.h>
#include <stdlib.h>

void swap(int*a, int *b)
{
    int temp=*a;
    *a = *b;
    *b = temp;
}

void insertionSort(int A[], int n)
{
    for(int i = 1; i<n; i++)
    {
        int j = i-1;
        int x = A[i];
        while(j>-1&&A[j]>x)
        {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = x;
    }
}

int main()
{

	int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
	int n = sizeof(arr) / sizeof(arr[0]);

	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");

	insertionSort(arr, n);

	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");


	return 0;
}
