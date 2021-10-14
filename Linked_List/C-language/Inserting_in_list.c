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

int count(struct Node*p)
{
    int c = 0;
    while(p)
    {
        p = p->next;
        c++;
    }
    return c;
}


void insertFirst(struct Node**head, int val)
{
    struct Node*newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;

    newNode->next = *(head);
    *(head) = newNode;
}

void insertAt(struct Node**head, int pos, int val)
{
    if(pos<0||pos>count(*head))
    {
        printf("Error: position out of range\n");
        return;
    }
    struct Node*newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;

    if(*(head)==NULL) {
        newNode->next = *(head);
        *(head) = newNode;
        return;
    }

    if(pos==0) {
        insertFirst(*(&head), val);
        return;
    }

    struct Node*curr = *(head);
    for(int i= 0; i<pos-1; i++)
        curr = curr->next;

    newNode->next = curr->next;
    curr->next = newNode;

}

void insertEnd(struct Node**head, int val)
{
    struct Node*newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;

    if(*(head)==NULL){
        newNode->next = *(head);
        *(head) = newNode;
    }

    struct Node*curr = *(head);
    while(curr->next!=NULL)
        curr = curr->next;

    newNode->next = NULL;
    curr->next = newNode;
    curr = newNode;
}

int main()
{
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head = NULL;

    insertFirst(&head, 11);
    insertFirst(&head, 22);
    insertFirst(&head, 33);
    insertFirst(&head, 44);

    display(head);
    printf("\n");

    insertAt(&head, 3, 41);
    display(head);
    printf("\n");


    insertEnd(&head, 5);
    display(head);
    printf("\n");


	return 0;
}
