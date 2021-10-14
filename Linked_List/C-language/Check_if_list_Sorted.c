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
    return c;
}

void display(struct Node*p)
{
    while(p!=NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

int check_if_list_sorted(struct Node*head)
{
    int x = -32768;
    struct Node*p = head;

    while(p)
    {
        if(p->data<x)
            return 0;
        x = p->data;
        p = p->next;
    }
    return 1;
}

int main()
{
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node*temp;
    struct Node*last;



    int A[] = {1, 7, 9, 15, 23, 35};

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


    if(check_if_list_sorted(head))
        printf("The list is sorted\n");
    else
        printf("The list is not sorted\n");



	return 0;
}
