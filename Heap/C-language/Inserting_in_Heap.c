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

int main()
{

    int a[] = { 45, 35, 15, 30, 10, 12, 6, 5, 20, 50 };
    Insert(a, 9);
    Print(a, sizeof(a) / sizeof(a[0]));




    return 0;
}
