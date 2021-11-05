
struct Node
{
    struct Node*left;
    int data;
    struct Node*right;
};

// Queue structure
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

// Binary Tree structure
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

int main()
{
    Create();

    return 0;
}
