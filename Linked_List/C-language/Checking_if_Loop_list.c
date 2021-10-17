#include <stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
}*first = NULL, *second = NULL, *third = NULL;

void display(struct Node*p)
{
    while(p!=NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

void create(int A[], int n)
{
    struct Node*temp,*last;
    first = (struct Node*)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for(int i = 1; i<n; i++) {
        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = A[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}

int isLoop(struct Node*first)
{
    struct Node*p, *q;
    p = q = first;

    do {
        p = p->next;
        q = q->next;
        q = q !=NULL ? q->next : NULL;
    }while(q&&p&&p!=q);

    if(p==q)
        return 1;
    else
        return 0;
}

int main()
{
    struct Node*t1, *t2;
    int A[] = {10, 20, 30, 40, 50};
    int n = sizeof(A)/ sizeof(A[0]);

    create(A, n);

    t1 = first->next->next;
    t2 = first->next->next->next->next;
    t2->next = t1;

    printf("%d", isLoop(first));


	return 0;
}
