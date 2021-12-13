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

void QuickSort(int A[], int low, int high)
{
    if(low<high)
    {
        int pviot = partition(A, low, high);
        QuickSort(A, low, pviot-1);
        QuickSort(A, pviot+1, high);
    }
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

void countSort(int A[], int n)
{
    int max = findMax(A, n);
    int *c = (int*)malloc(sizeof(int)*max+1);
    int i, j;

    for(i = 0; i<max+1; i++)
        c[i] = 0;

    for(i = 0; i<n; i++)
        c[A[i]]++;

    i = 0;
    j = 0;

    while(i<max+1)
    {
        if(c[i]>0)
        {
            A[j++] = i;
            c[i]--;
        }
        else
            i++;
    }

    free(c);
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
////////////////////////////////////////////////

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

void ShellSort(int A[], int n)
{
    for(int gap = n/2; gap>=1; gap/=2)
    {
        for(int j = gap; j<n; j++)
        {
            int temp = A[j];
            int i = j-gap;
            while(i>=0&&A[i]>temp)
            {
                A[i+gap] = A[i];
                i = i-gap;
            }
            A[i+gap] = temp;
        }
    }
}

int main()
{

	int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
	int n = sizeof(arr) / sizeof(arr[0]);

	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");

	//BubbleSort(arr, n);

	//insertionSort(arr, n);

	//selectionSort(arr, n);

	//QuickSort(arr, 0, n-1);

	//iterative_mergeSort(arr, n);

	//mergeSort(arr, 0, n-1);

	//countSort(arr, n);

	//BucketSort(arr, n);

	//RadixSort(arr, n);

	//ShellSort(arr, n);

	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");


	return 0;
}


