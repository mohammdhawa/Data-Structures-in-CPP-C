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

int max(struct Node*p)
{
    int m = INT_MIN;
    while(p)
    {
        if(p->data>m)
            m = p->data;
        p = p->next;
    }
    return m;
}

int max_r(struct Node*p)
{
    int x = 0;

    if(p==NULL)
        return INT_MIN;

    x = max(p->next);
    return x>p->data ? x : p->data;
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

    printf("The maximum number of list: %d\n", max(head));
    printf("The maximum number of list: %d\n", max_r(head));


	return 0;
}
