#include <stdio.h>
#include <stdlib.h>

void swap(int*a, int *b)
{
    int temp=*a;
    *a = *b;
    *b = temp;
}

int partition(int A[], int low, int high)
{
    int pviot = A[high];
    int i = low-1;

    for(int j = low; j<=high-1; j++)
    {
        if(A[j]<pviot)
        {
            i++;
            swap(&A[i], &A[j]);
        }
    }
    swap(&A[i+1], &A[high]);
    return i+1;
}

int QuickSort(int A[], int low, int high)
{
    if(low<high)
    {
        int pviot = partition(A, low, high);
        QuickSort(A, low, pviot-1);
        QuickSort(A, pviot+1, high);
    }
}

int main()
{

	int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
	int n = sizeof(arr) / sizeof(arr[0]);

	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");

	QuickSort(arr, 0, n-1);

	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");


	return 0;
}
