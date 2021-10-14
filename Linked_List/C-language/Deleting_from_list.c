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

int deleteFirst(struct Node**head)
{
    if((*head)==NULL)
    {
        printf("This list is empty");
        exit(1);
    }

    struct Node*temp = (*head);
    int x = (*head)->data;

    *head = (*head)->next;
    free(temp);

    return x;
}

int deleteEnd(struct Node**head)
{
    if((*head)==NULL)
    {
        printf("This list is empty");
        exit(1);
    }

    struct Node*temp = (*head);
    while(temp->next->next)
    {
        temp = temp->next;
    }

    int x = temp->next->data;
    free(temp->next);
    temp->next = NULL;

    return x;
}

int deleteFrom(struct Node**head, int pos)
{
    if(pos<1 ||pos>count((*head)))
    {
        printf("Error: position is out of range\n");
        exit(1);
    }

    if(pos==1)
    {
        struct Node*temp = (*head);
        int x = (*head)->data;

        (*head) = (*head)->next;
        free(temp);

        return x;
    }
    else
    {
        struct Node*curr = (*head);
        struct Node*prev = NULL;

        for(int i = 0; i<pos-1; i++)
        {
            prev = curr;
            curr = curr->next;
        }

        int x = curr->data;

        prev->next = curr->next;
        free(curr);

        return x;
    }
}

int main()
{
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node*temp;
    struct Node*last;



    int A[] = {1, 7, 9, 15, 23, 19, 35};

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

    printf("%d has been deleted from list\n", deleteFirst(&head));

    display(head);
    printf("\n");

    printf("%d has been deleted from list\n", deleteEnd(&head));

    display(head);
    printf("\n");

    printf("%d has been deleted from list\n", deleteFrom(&head, 3));

    display(head);
    printf("\n");



	return 0;
}
