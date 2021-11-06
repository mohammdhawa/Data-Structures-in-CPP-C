#include <stdio.h>
#include<stdlib.h>

#include "Queue.h"

struct Node*root = NULL;

void Create()
{
    struct Node*p, *t;
    int x;
    struct Queue q;
    create(&q, 100);

    printf("Enter root value: ");
    scanf("%d", &x);

    root = (struct Node*)malloc(sizeof(struct Node));
    root->data = x;
    root->left = root->right = NULL;

    enQueue(&q, root);

    while(!isEmpty(q))
    {
        p = deQueue(&q);
        printf("Enter left child of %d: ", p->data);
        scanf("%d", &x);
        if(x!=-1)
        {
            t = (struct Node*)malloc(sizeof(struct Node));
            t->data = x;
            t->left = t->right = NULL;
            p->left = t;
            enQueue(&q, t);
        }

        printf("Enter right child of %d: ", p->data);
        scanf("%d", &x);
        if(x!=-1)
        {
            t = (struct Node*)malloc(sizeof(struct Node));
            t->data = x;
            t->right = t->left = NULL;
            p->right = t;
            enQueue(&q, t);
        }
    }
}

void preOrder(struct Node*p)
{
    if(p)
    {
        printf("%d ", p->data);
        preOrder(p->left);
        preOrder(p->right);
    }
}

void inOrder(struct Node*p)
{
    if(p)
    {
        inOrder(p->left);
        printf("%d ", p->data);
        inOrder(p->right);
    }
}

void postOrder(struct Node*p)
{
    if(p)
    {
        postOrder(p->left);
        postOrder(p->right);
        printf("%d ", p->data);
    }
}

void levelOrder(struct Node*p)
{
    struct Queue q;
    create(&q, 100);

    printf("%d ", p->data);
    enQueue(&q, p);

    while(!isEmpty(q))
    {
        p = deQueue(&q);

        if(p->left)
        {
            printf("%d ", p->left->data);
            enQueue(&q, p->left);
        }
        if(p->right)
        {
            printf("%d ", p->right->data);
            enQueue(&q, p->right);
        }
    }
}

int count(struct Node*p)
{
    if(p)
        return count(p->right)+count(p->left)+1;
    else
        return 0;
}

int height(struct Node*p)
{
    int x, y;
    x = y = 0;

    if(p==NULL)
        return 0;

    x = height(p->left);
    y = height(p->right);

    if(x>y)
        return x+1;
    else
        return y+1;
}

int main()
{
    Create();

    preOrder(root);
    printf("\n----------------\n");
    levelOrder(root);

    printf("\n\ncount: %d\n", count(root));

    printf("height of tree: %d\n", height(root));


    return 0;
}


/////////////////////////////////////////// header file ///////////////////////////////////////////////////////
#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

struct Node
{
    struct Node*left;
    int data;
    struct Node*right;
};

struct Queue
{
    int size;
    int front;
    int rear;
    struct Node**Q;
};

void create(struct Queue*q, int size)
{
    q->size = size;
    q->front = q->rear = -1;
    q->Q = (struct Node**)malloc(q->size*sizeof(struct Node*));
}

int isEmpty(struct Queue q)
{
    return q.front == -1;
}

int isFull(struct Queue q)
{
    return (q.rear+1)%q.size == q.front;
}

void enQueue(struct Queue*q, struct Node* x)
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

struct Node* deQueue(struct Queue*q)
{
    struct Node* x = NULL;
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

#endif // QUEUE_H_INCLUDED
