#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node*next;
}*front=NULL, *rear=NULL;

int isEmpty()
{
    if(front==NULL)
    {
        return 1;
    }
    return 0;
}

void enQueue(int x)
{
    struct Node*t = (struct Node*)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;

    if(isEmpty()){
        front = rear = t;
    }
    else
    {
        rear->next = t;
        rear = t;
    }
}

int deQueue()
{
    int x = -1;
    struct Node*temp = NULL;
    if(front==NULL)
    {
        printf("Queue is empty\n");
        return x;
    }
    else
    {
        x = front->data;
        temp = front;
        front = front->next;
        free(temp);
        return x;
    }
}

void BFS(int G[][7], int start, int n)
{
    int i = start, j;

    int visited[7] = {0};

    printf("%d ", i);
    visited[i] = 1;
    enQueue(i);

    while(!isEmpty())
    {
        i = deQueue();
        for(j = 1; j<n; j++)
        {
            if(G[i][j]==1&&visited[j]==0)
            {
                printf("%d ", j);
                visited[j] = 1;
                enQueue(j);
            }
        }
    }
}

int main()
{

	int G[7][7]={{0,0,0,0,0,0,0},
                    {0,0,1,1,0,0,0},
                    {0,1,0,0,1,0,0},
                    {0,1,0,0,1,0,0},
                    {0,0,1,1,0,1,1},
                    {0,0,0,0,1,0,0},
                    {0,0,0,0,1,0,0}};

    BFS(G, 4, 7);
    printf("\n");


	return 0;
}
