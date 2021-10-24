#include <stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node*next;
}*rear=NULL, *front=NULL;

int isEmpty()
{
    if(front==NULL)
        return 1;
    else
        return 0;
}

int isFull()
{
    struct Node*t = (struct Node*)malloc(sizeof(struct Node));
    if(t = NULL)
        return 1;
    else
        return 0;
}

void enQueue(int x)
{
    struct Node*t = (struct Node*)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;
    if(isEmpty())
        rear = front = t;
    else
    {
        rear->next = t;
        rear = t;
    }
}

int deQueue()
{
    int x = -1;
    if(isEmpty())
        printf("Queue is empty");

    struct Node*p = front;
    front = front->next;
    x = p->data;

    if(front == NULL)
        rear = NULL;
    free(p);

    return x;
}

int Front()
{
    if(!isEmpty())
        return front->data;
    else
        return -1;
}

int Rear()
{
    if(!isEmpty())
        return rear->data;
    else
        return -1;
}

void display()
{
    struct Node*p = front;
    while(p!=NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    enQueue(8);
    enQueue(12);
    enQueue(14);
    enQueue(15);

    display();
    printf("front: %d \n", Front());
    printf("rear: %d \n",  Rear());

    printf("%d has been deleted\n", deQueue());
    enQueue(17);
    display();

    printf("front: %d \n", Front());
    printf("rear: %d \n",  Rear());


    return 0;
}
