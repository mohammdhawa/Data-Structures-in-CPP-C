#include <stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
}*head = NULL;

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

int main()
{
    int A[] = {10, 20, 30, 40, 50};
    int n = sizeof(A)/ sizeof(A[0]);

    create(A, n);

    display(head);

    display_r(head);
    printf("\n");


	return 0;
}
