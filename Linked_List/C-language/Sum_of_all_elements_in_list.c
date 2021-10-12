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

int Add(struct Node*p)
{
    int sum = 0;
    while(p)
    {
        sum += p->data;
        p = p->next;
    }
    return sum;
}

int Add_r(struct Node*p)
{
    if(p==NULL)
        return 0;
    else
        return Add_r(p->next)+ p->data;
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

    printf("Sum of all elements in list: %d\n", Add(head));
    printf("Sum of all elements in list: %d\n", Add_r(head));


	return 0;
}
