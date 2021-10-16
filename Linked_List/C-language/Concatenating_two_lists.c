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

void insert(struct Node**head, int val)
{
    struct Node*newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;

    newNode->next = (*head);
    (*head) = newNode;
}

void concatenate(struct Node *a,struct Node *b)
{
    if (a->next == NULL)
        a->next = b;
    else
        concatenate(a->next,b);
}

int main()
{
    struct Node* first = NULL;
    insert(&first, 2);
    insert(&first, 13);
    insert(&first, 8);
    insert(&first, 29);

    struct Node*second = NULL;
    insert(&second, 10);
    insert(&second, 4);
    insert(&second, 7);

    display(first);
    printf("\n");
    display(second);
    printf("\n");

    concatenate(first, second);
    display(first);


	return 0;
}
