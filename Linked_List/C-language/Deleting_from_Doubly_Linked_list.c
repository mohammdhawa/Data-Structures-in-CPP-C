#include <stdio.h>
#include<stdlib.h>

struct Node
{
    struct Node*prev;
    int data;
    struct Node*next;
}*first = NULL;

int length(struct Node*p)
{
    int c = 0;
    while(p)
    {
        c++;
        p = p->next;
    }
    return c;
}

void create(int A[], int n)
{
    first = (struct Node*)malloc(sizeof(struct Node));
    struct Node*last, *newNode;

    first->prev = NULL;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for(int i = 1; i<n; i++)
    {
        newNode = (struct NOde*)malloc(sizeof(struct Node));
        newNode->data = A[i];
        newNode->next = last->next;
        newNode->prev = last;
        last->next = newNode;
        last = newNode;
    }
}

void display(struct Node*p)
{
    while(p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void deleteFisrt(struct Node*p)
 {
     first = first->next;
     if(first)
        first->prev = NULL;

     int x = p->data;
     free(p);

     printf("%d has been deleted\n", x);
 }

 void deleteFrom(struct Node*p, int pos)
 {
     if(pos<1 || pos>length(p))
     {
         printf("Error position out of range");
         return;
     }
     if(pos==1)
     {
        first = first->next;
        if(first)
            first->prev = NULL;

        int x = p->data;
        free(p);

        printf("%d has been deleted\n", x);
     }
     else
     {
         for(int i = 0; i<pos-1; i++)
            p = p->next;
         int x = p->data;
         p->prev->next = p->next;
         if(p->next)
            p->next->prev = p->prev;
         free(p);

         printf("%d has been deleted\n", x);
     }
 }

 void deleteEnd(struct Node*p)
 {
     if(p==NULL)
     {
         printf("you con not delete from empty list\n");
         return;
     }
     else
     {
         while(p->next)
            p = p->next;
         int x = p->data;
         p->prev->next = NULL;
         free(p);

         printf("%d has been deleted\n", x);
     }
 }

int main()
{
    int A[] = {10, 20, 30, 40, 50};
    int n = sizeof(A)/sizeof(A[0]);

    create(A, n);

    display(first);

    deleteFisrt(first);
    display(first);

    deleteFrom(first, 3);
    display(first);

    deleteEnd(first);
    display(first);


	return 0;
}
