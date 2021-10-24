#include <stdio.h>
#include<stdlib.h>

struct Queue
{
    int size;
    int front;
    int rear;
    int*Q;
};

void create(struct Queue*q, int size)
{
    q->size = size;
    q->front = q->rear = -1;
    q->Q = (int*)malloc(sizeof(int)*q->size);
}

int isEmpty(struct Queue q)
{
    if(q.rear==q.front)
        return 1;
    else
        return 0;
}

int isFull(struct Queue q)
{
    if(q.rear==q.size-1)
        return 1;
    else
        return 0;
}

void enQueue(struct Queue*q, int x)
{
    if(q->rear==q->size-1)
        printf("Queue is full\n");
    else
    {
        q->rear++;
        q->Q[q->rear] = x;
    }
}

int deQueue(struct Queue*q)
{
    int x = -1;
    if(q->front==q->rear)
        printf("Queue is empty\n");
    else
    {
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}

void display(struct Queue q)
{
    for(int i =q.front+1; i<=q.rear; i++)
        printf("%d ", q.Q[i]);
    printf("\n");
}

int main()
{
    struct Queue q;

    create(&q, 10);

    enQueue(&q, 11);
    enQueue(&q, 22);
    enQueue(&q, 33);
    enQueue(&q, 44);
    enQueue(&q, 55);

    display(q);

    printf("dequeue: %d \n", deQueue(&q));

    display(q);


    return 0;
}
