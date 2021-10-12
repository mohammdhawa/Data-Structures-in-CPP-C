#include <stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void display_by_iteration(struct Node*p)
{
    while(p!=NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

void display_by_recursion(struct Node*p)
{
    if(p!=NULL)
    {
        printf("%d ", p->data);
        display_by_recursion(p->next);
    }
}

void reverse_display(struct Node*p)
{
    if(p!=NULL)
    {
        reverse_display(p->next);
        printf("%d ", p->data);
    }
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


    display_by_iteration(head);
    printf("\n");
    display_by_recursion(head);
    printf("\n");
    reverse_display(head);


	return 0;
}
