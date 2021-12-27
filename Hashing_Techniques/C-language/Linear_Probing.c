#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

void print(int A[], int n, char ch[])
{
    printf("%s: [", ch);
    for(int i = 0; i<n; i++)
    {
        printf("%d", A[i]);
        if(i<n-1)
            printf(", ");
    }
    printf("]\n");
}

int Hash(int key)
{
    return key%SIZE;
}

int LinearProbing(int H[], int key)
{
    int idx = Hash(key);
    int i = 0;

    while(H[(idx+i)%SIZE]!=0)
        i++;
    return (idx+i)%SIZE;
}

int Insert(int H[], int key)
{
    int idx = Hash(key);

    if(H[idx]!=0)
        idx = LinearProbing(H, key);
    H[idx] = key;
}

int search(int H[], int key)
{
    int idx = Hash(key);
    int i = 0;

    while(H[(idx+i)%SIZE]!=key)
    {
        i++;
        if(H[(idx+i)%SIZE]==0)
            return -1;
    }
    return (idx+i)%SIZE;
}

int main()
{

    int A[] = {26, 30, 45, 23, 25, 43, 74, 19, 29};
    int n = sizeof(A)/sizeof(A[0]);
    print(A, n, "A");

    // Hash Table
    int HT[10] = {0};
    for(int i = 0; i<n; i++)
        Insert(HT, A[i]);

    print(HT, SIZE, "HT");

    int index = search(HT, 25);
    printf("Key found at: %d\n", index);

    index = search(HT, 35);
    printf("Key found at: %d\n", index);





    return 0;
}

