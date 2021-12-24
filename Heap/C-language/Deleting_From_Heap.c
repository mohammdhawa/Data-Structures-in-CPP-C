#include <stdio.h>
#include <stdlib.h>

/*
struct Node
{
    int data;
    struct Node*left;
    struct Node*right;
};

struct Node* create(int key)
{
    struct Node*root = (struct Node*)malloc(sizeof(struct Node));
    root->data = key;
    root->left = root->right = NULL;
    return root;
};

struct Node*insert(struct Node*root, int key)
{
    if(root == NULL)
        root = create(key);
    else
    {
        if(key<root->data)
            root->left = insert(root->left, key);
        else if(key>root->data)
            root->right = insert(root->right, key);
    }
    return root;
};

int count(struct Node*p)
{
    if(p==NULL)
        return 0;
    else
        return 1+count(p->left)+count(p->right);
}

void inorder(struct Node*p)
{
    if(p)
    {
        inorder(p->left);
        printf("%d ", p->data);
        inorder(p->right);
    }
    else
        return;
}

int sum(struct Node*p)
{
    if(p==NULL)
        return 0;
    else
        return p->data+sum(p->left)+sum(p->right);
}

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
*/

void insert(int H[], int n)
{
    int i=n, temp;
    temp = H[i];

    while(i>1&&temp>H[i/2])
    {
        H[i] = H[i/2];
        i = i/2;
    }
    H[i] =temp;
}

int Delete(int A[], int n)
{
    int val = A[1];
    int i, j, x, temp;
    x = A[n];
    A[1] = A[n];
    A[n] = val;
    i = 1;
    j = 2*i;

    while(j<n-1)
    {
        if(A[j+1]>A[j])
            j = j+1;
        if(A[i]<A[j])
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i = j;
            j = 2*j;
        }
        else
            break;
    }

    return val;
}

int main()
{

    int H[] = {0, 10, 20, 30, 25, 5, 40, 35};
    // 40, 25, 35, 10, 5, 20, 30

    for(int i=2; i<=sizeof(H)/sizeof(H[0])-1; i++)
        insert(H, i);

    for(int i = 1; i<=7; i++)
        printf("%d ", H[i]);
    printf("\n");

    printf("Deleted value is: %d\n", Delete(H, 7));

    for(int i = 1; i<=7; i++)
        printf("%d ", H[i]);
    printf("\n");


    return 0;
}
