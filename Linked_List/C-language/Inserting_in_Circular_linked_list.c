#include <stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
}*head = NULL;

int length(struct Node*p)
{
    int c = 0;
    do {
        c++;
        p = p->next;
    }while(p!=head);

    return c;
}

void display(struct Node*p)
{
    do {
        printf("%d ", p->data);
        p = p->next;
    }while(p!=head);
    printf("\n");
}

void display_r(struct Node*p)
{
    static int flag = 0;
    if(p!=head || flag == 0)
    {
        flag = 1;
        printf("%d ", p->data);
        display_r(p->next);
    }
    flag = 0;
}

void create(int A[], int n)
{
    struct Node*temp,*last;
    head = (struct Node*)malloc(sizeof(struct Node));
    head->data = A[0];
    head->next = head;  // not NULL as always
    last = head;

    for(int i = 1; i<n; i++) {
        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = A[i];
        temp->next = last->next;
        last->next = temp;
        last = temp;
    }
}

void insertAt(struct Node*p, int pos, int val)
{
    struct Node*newNode = (struct Node*)malloc(sizeof(struct Node));
    //struct Node* p;

    if(pos<0 || pos>length(p))
    {
        printf("Error: position out of range\n");
        return;
    }

    newNode->data = val;
    if(pos==0)
    {
        if(head == NULL)
        {
            head = newNode;
            head->next = head;
        }
        else
        {
            p = head;
            while(p->next !=head)
                p = p->next;
            p->next = newNode;
            newNode->next = head;
            head = newNode;
        }
    }
    else
    {
        p = head;
        for(int i = 0; i<pos-1; i++)
            p = p->next;
        newNode->next = p->next;
        p->next = newNode;
    }
}

void insertFirst(struct Node*p, int val)
{
    struct Node*newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;

    if(head == NULL)
        {
            head = newNode;
            head->next = head;
        }
        else
        {
            p = head;
            while(p->next !=head)
                p = p->next;
            p->next = newNode;
            newNode->next = head;
            head = newNode;
        }
}

int main()
{
    int A[] = {10, 20, 30, 40, 50};
    int n = sizeof(A)/ sizeof(A[0]);

    create(A, n);

    display(head);

    display_r(head);
    printf("\n");

    insertFirst(head, 5);
    display(head);

    insertAt(head, 3, 29);
    display(head);



	return 0;
}
