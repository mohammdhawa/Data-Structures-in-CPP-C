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

void insertInSorted(struct Node**head, int val)
{
    struct Node*curr = *(head);
    struct Node*prev = NULL;

    while(curr && curr->data<val)
    {
        prev = curr;
        curr = curr->next;
    }

    struct Node*newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;

    newNode->next = prev->next;
    prev->next = newNode;
}

int main()
{
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node*temp;
    struct Node*last;



    int A[] = {7, 9, 15, 23};

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

    insertInSorted(&head, 18);
    display(head);
    printf("\n");



	return 0;
}
