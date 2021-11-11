int search(struct Node*p, int key)
{
    if(p==NULL)
        return 0;

    if(key==p->data)
        return 1;
    else if(key<p->data)
        return search(p->left, key);
    else
        return search(p->right, key);
};
