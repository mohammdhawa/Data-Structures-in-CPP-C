// Recursive Traversal
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
