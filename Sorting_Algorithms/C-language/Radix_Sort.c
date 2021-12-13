#include <stdio.h>
#include <stdlib.h>

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

int Delete(struct Node**ptrBucket, int index)
{
    struct Node*p = ptrBucket[index];
    ptrBucket[index] = ptrBucket[index]->next;
    int x = p->data;
    free(p);
    return x;
}

int countDigits(int x)
{
    int count = 0;
    while(x!=0)
    {
        x = x/10;
        count++;
    }
    return count;
}

void Insert(struct Node**ptrBins, int value, int idx)
{
    struct Node*temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    temp->next = NULL;

    if(ptrBins[idx]==NULL)
        ptrBins[idx] = temp;
    else
    {
        struct Node*p = ptrBins[idx];
        while(p->next!=NULL)
            p = p->next;
        p->next = temp;
    }
}

int getBinIndex(int x, int index)
{
    return (int)(x/pow(10, index))%10;
}

void initializeBins(struct Node**p, int n)
{
    for(int i = 0; i<n; i++)
        p[i] = NULL;
}

void RadixSort(int A[], int n)
{
    int max = findMax(A, n);
    int nPass = countDigits(max);

    struct Node**bins = (struct Node*)malloc(sizeof(struct Node)*10);
    initializeBins(bins, 10);

    for(int pass = 0; pass<nPass; pass++)
    {
        for(int i = 0; i<n; i++)
        {
            int binIdx = getBinIndex(A[i], pass);
            Insert(bins, A[i], binIdx);
        }

        int i = 0;
        int j = 0;
        while(i<10)
        {
            while(bins[i]!=NULL)
                A[j++] = Delete(bins, i);
            i++;
        }
        initializeBins(bins, 10);
    }
    free(bins);
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

	//BucketSort(arr, n);

	RadixSort(arr, n);

	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");


	return 0;
}
