#include <stdio.h>
#include <stdlib.h>

void swap(int*a, int *b)
{
    int temp=*a;
    *a = *b;
    *b = temp;
}

void BubbleSort(int A[], int n)
{
    int flag;
    for(int i =0; i<n-1; i++)
    {
        flag = 0;
        for(int j = 0; j<n-i-1; j++)
        {
            if(A[j]>A[j+1])
            {
                swap(&A[j], &A[j+1]);
                flag = 1;
            }
        }
        if(flag == 0)
            break; // or return
    }
}

int main()
{

	int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
	int n = sizeof(arr) / sizeof(arr[0]);

	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");

	BubbleSort(arr, n);

	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");


	return 0;
}
