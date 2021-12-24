#include <stdio.h>
#include <stdlib.h>

void Insert(int A[], int n)
{
    int i = n;
    int temp = A[n];
    while(i>0&&temp>A[i%2==0?(i/2)-1:i/2])
    {
        A[i] = A[i%2==0?(i/2)-1:i/2];
        i = i%2==0?(i/2)-1:i/2;
    }
    A[i] = temp;
}

void Print(int A[], int n)
{
    printf("Max heap: [");
    for(int i = 0; i<n; i++)
    {
        printf("%d", A[i]);
        if(i<n-1)
            printf(", ");
    }
    printf("]\n");
}

void createHeap(int A[], int n)
{
    for(int i = 0; i<n; i++)
    {
        Insert(A, i);
    }
}

int main()
{

    printf("Create Heap\n");
    int b[] = { 10, 20, 30, 25, 5, 40, 35 };
    Print(b, sizeof(b) / sizeof(b[0]));

    printf("Inplace Insert\n");
    createHeap(b, sizeof(b) / sizeof(b[0]));
    Print(b, sizeof(b) / sizeof(b[0]));


    return 0;
}
