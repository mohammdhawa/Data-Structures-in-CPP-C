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

void insertFirst(struct Node**p, int val)
{
    struct Node*t = (struct Node*)malloc(sizeof(struct Node));
    t->data = val;
    t->prev = NULL;

    t->next = (*p);
    (*p)->prev = t;
    (*p) = t;
}

void insertAt(struct Node*p, int pos, int val)
{
    if(pos<0 || pos>length(p))
    {
        printf("Error: position out of range\n");
        return;
    }

    struct Node*t = (struct Node*)malloc(sizeof(struct Node));
    t->data = val;

    if(pos==0)
    {
        t->prev = NULL;
        t->next = p;
        p->prev = t;
        p = t;
    }
    else
    {
        for(int i = 0; i<pos-1; i++)
            p = p->next;

        t->next = p->next;
        t->prev = p;
        if(p->next != NULL)
            p->next->prev = t;
        p->next = t;
    }
}

void insertEnd(struct Node*p, int val)
{
    struct Node*t = (struct Node*)malloc(sizeof(struct Node));
    t->data = val;
    t->next = NULL;

    if(p == NULL)
    {
        t->prev = NULL;
        p = t;
        return;
    }

    struct Node*last = p;
    while(last->next != NULL)
        last = last->next;

    last->next = t;
    t->prev = last;
}

int main()
{
    int A[] = {10, 20, 30, 40, 50};
    int n = sizeof(A)/sizeof(A[0]);

    create(A, n);

    display(first);

    insertFirst(&first, 5);
    display(first);

    insertAt(first, 4, 33);
    display(first);

    insertEnd(first, 99);
    display(first);

	return 0;
}
