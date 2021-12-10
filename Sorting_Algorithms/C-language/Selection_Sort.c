#include <stdio.h>
#include <stdlib.h>

void swap(int*a, int *b)
{
    int temp=*a;
    *a = *b;
    *b = temp;
}

void selectionSort(int A[], int n)
{
    for(int i = 0; i<n-1; i++)
    {
        int k;
        for(int j = k = i; j<n; j++)
        {
            if(A[j]<A[i])
                k = j;
        }
        swap(&A[k], &A[i]);
    }
}

int main()
{

	int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
	int n = sizeof(arr) / sizeof(arr[0]);

	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");

	selectionSort(arr, n);

	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");


	return 0;
}


