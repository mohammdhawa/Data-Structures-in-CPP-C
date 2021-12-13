#include <stdio.h>
#include <stdlib.h>

void swap(int*a, int *b)
{
    int temp=*a;
    *a = *b;
    *b = temp;
}

int findMax(int A[], int n)
{
    int mx = A[0];
    for(int i=1; i<n; i++)
    {
        if(mx<A[i])
            mx = A[i];
    }
    return mx;
}

struct Node
{
    int data;
    struct Node*next;
};

void insert(struct Node**ptrBucket, int index)
{
    struct Node*temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = index;
    temp->next = NULL;

    if(ptrBucket[index]==NULL)
        ptrBucket[index]= temp;
    else
    {
        struct Node*p = ptrBucket[index];
        while(p->next!=NULL)
            p = p->next;
        p->next = temp;
    }
}
int Delete(struct Node**ptrBucket, int index)
{
    struct Node*p = ptrBucket[index];
    ptrBucket[index] = ptrBucket[index]->next;
    int x = p->data;
    free(p);
    return x;
}

void BucketSort(int A[], int n)
{
    int max, i, j;
    max = findMax(A, n);

    struct Node**Bucket = (struct Node*)malloc(sizeof(struct Node)*(max+1));

    for(i = 0; i<max+1; i++)
        Bucket[i] = NULL;

    for(i = 0; i<n; i++)
        insert(Bucket, A[i]);

    i = 0; j = 0;
    while(i<max+1)
    {
        while(Bucket[i]!=NULL)
            A[j++] = Delete(Bucket, i);
        i++;
    }
    free(Bucket);
}

int main()
{

	int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
	int n = sizeof(arr) / sizeof(arr[0]);

	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");

	//QuickSort(arr, 0, n-1);

	//iterative_mergeSort(arr, n);

	//mergeSort(arr, 0, n-1);

	//countSort(arr, n);

	BucketSort(arr, n);

	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");


	return 0;
}
