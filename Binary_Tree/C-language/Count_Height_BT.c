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
