#include <stdio.h>
#include<stdlib.h>

struct Node
{
    struct Node*prev;
    int data;
    struct Node*next;
}*first = NULL;

int length(struct Node*p)
{
    int c = 0;
    while(p)
    {
        c++;
        p = p->next;
    }
    return c;
}

void create(int A[], int n)
{
    first = (struct Node*)malloc(sizeof(struct Node));
    struct Node*last, *newNode;

    first->prev = NULL;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for(int i = 1; i<n; i++)
    {
        newNode = (struct NOde*)malloc(sizeof(struct Node));
        newNode->data = A[i];
        newNode->next = last->next;
        newNode->prev = last;
        last->next = newNode;
        last = newNode;
    }
}

void display(struct Node*p)
{
    while(p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void reverse(struct Node*p)
{
    struct Node*temp;

     while(p!=NULL)
     {
         temp = p->prev;
         p->prev = p->next;
         p->next = temp;
         p = p->prev;

     }
     if(temp!=NULL)
        first = temp->prev;
}

int main()
{
    int A[] = {10, 20, 30, 40, 50};
    int n = sizeof(A)/sizeof(A[0]);

    create(A, n);

    display(first);

    reverse(first);

    display(first);


    return 0;
}
