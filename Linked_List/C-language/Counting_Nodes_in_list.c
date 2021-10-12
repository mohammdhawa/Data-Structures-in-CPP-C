#include <stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void display(struct Node*p)
{
    while(p!=NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

int count(struct Node*p)     // using iteration
{
    int c = 0;
    while(p!=NULL)
    {
        c++;
        p = p->next;
    }
    return c;
}

int rcount(struct Node*p)   // using recursion
{
    if(p==NULL)
        return 0;
    else
        return rcount(p->next) + 1;
}

int main()
{
    int A[] = { 3, 5, 7, 10, 15 };

    struct Node*head;
    head = (struct Node*)malloc(sizeof(struct Node));

    head->data = A[0];
    head->next = NULL;

    struct Node*temp, *last;
    last = head;
    for(int i = 1; i<sizeof(A)/ sizeof(A[0]); i++)
    {
        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = A[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }

    display(head);
    printf("\n");

    printf("Number of nodes in list: %d\n", count(head));
    printf("Number of nodes in list: %d\n", rcount(head));


	return 0;
}
