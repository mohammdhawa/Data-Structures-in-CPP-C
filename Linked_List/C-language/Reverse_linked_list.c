#include <stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int count(struct Node*p)
{
    int c = 0;
    while(p)
    {
        c++;
        p = p->next;
    }
}

void display(struct Node*p)
{
    while(p!=NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

void reverse_Array(struct Node*head)
{
    int *A;
    int i = -1;
    A = (int*)malloc(sizeof(int)*count(head));
    struct Node*p = head;

    while(p)
    {
        A[++i] = p->data;
        p = p->next;
    }

    p = head;
    while(p)
    {
        p->data = A[i--];
        p = p->next;
    }
}

void reverse(struct Node**head)
{
    struct Node*p, *q, *r;
    p = (*head);
    q = NULL;
    r = NULL;
    while(p)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    (*head) = q;
}

int main()
{
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node*temp;
    struct Node*last;



    int A[] = {2, 4, 6, 8, 10};

    head->data = A[0];
    head->next = NULL;
    last = head;

    for(int i = 1; i<sizeof(A)/sizeof(A[0]); i++)
    {
        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = A[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }


    display(head);
    printf("\n");


    reverse(&head);
    display(head);
    printf("\n");




	return 0;
}
