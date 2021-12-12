#include <stdio.h>
#include <stdlib.h>

void swap(int*a, int *b)
{
    int temp=*a;
    *a = *b;
    *b = temp;
}

void merge(int A[], int l, int mid, int h)
{
    int i, j, k;
    i = l;
    j = mid+1;
    k = l;

    int B[h+1];

    while(i<=mid&&j<=h)
    {
        if(A[i]<A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }

    for(; i<=mid; i++)
        B[k++] = A[i];
    for(; j<=h; j++)
        B[k++] = A[j];

    for(i = l; i<=h; i++)
        A[i] = B[i];
}

void iterative_mergeSort(int A[], int n)
{
    int l, mid, h, p, i;

    for(p = 2; p<=n; p = p*2)
    {
        for(i = 0; i+p-1<n; i= i+p)
        {
            l = i;
            h = i+p-1;
            mid = (l+h)/2;
            merge(A, l, mid, h);
        }
    }
    if(p/2<n)
        merge(A, 0, p/2-1, n-1);
}

void mergeSort(int A[], int low, int high)
{
    if(low<high)
    {
        int mid = (low+high)/2;
        mergeSort(A, low, mid);
        mergeSort(A, mid+1, high);
        merge(A, low, mid, high);
    }
}

int main()
{

	int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
	int n = sizeof(arr) / sizeof(arr[0]);

	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");

	//iterative_mergeSort(arr, n);

	mergeSort(arr, 0, n-1);

	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");


	return 0;
}
