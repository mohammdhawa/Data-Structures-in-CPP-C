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


struct Node*search(struct Node*p, int key)
{
    while(p)
    {
        if(key==p->data)
            return p;
        p = p->next;
    }
    return NULL;
};

struct Node*search_r(struct Node*p, int key)
{
    if(p==NULL)
        return NULL;
    if(key==p->data);
        return p;
    return search_r(p->next, key);
};

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

    struct Node*srch = search_r(head, 3);

    if(srch)
        printf("Node is found");
    else
        printf("Node not found");

	return 0;
}
