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
    return q.front == -1;
}

int isFull(struct Queue q)
{
    return (q.rear+1)%q.size == q.front;
}

void enQueue(struct Queue*q, int x)
{
    if(isFull(*q))
    {
        printf("Queue is full\n");
        return;
    }
    else if(isEmpty(*q))
        q->front = q->rear = 0;
    else
        q->rear = (q->rear+1)%q->size;
    q->Q[q->rear] = x;
}

int deQueue(struct Queue*q)
{
    int x = -1;
    if(isEmpty(*q))
        printf("Queue is empty\n");
    else if(q->rear==q->front)
    {
        x = q->Q[q->front];
        q->rear = q->front = -1;
    }
    else
    {
        x = q->Q[q->front];
        q->front = (q->front+1)%q->size;
    }
    return x;
}

void display(struct Queue q)
{
    for(int i =q.front; i<=q.rear; i++)
        printf("%d ", q.Q[i]);
    printf("\n");
}

int main()
{
    struct Queue q;

    create(&q, 5);

    enQueue(&q, 8);
    enQueue(&q, 12);
    enQueue(&q, 14);
    enQueue(&q, 15);

    display(q);

    printf("front: %d \n", q.Q[q.front]);
    printf("rear: %d \n", q.Q[q.rear]);

    printf("%d has been deleted\n", deQueue(&q));
    enQueue(&q, 17);

    display(q);

    printf("front: %d \n", q.Q[q.front]);
    printf("rear: %d \n", q.Q[q.rear]);

    return 0;
}
