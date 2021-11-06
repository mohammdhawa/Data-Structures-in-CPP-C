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
