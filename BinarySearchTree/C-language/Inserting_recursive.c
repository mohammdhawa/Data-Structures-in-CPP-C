

struct Node* insert(struct Node*p, int key)
{
    // if the tree is empty, return a new node
    if(p==NULL)
    {
        struct Node*t = (struct Node*)malloc(sizeof(struct Node));
        t->data = key;
        t->left = t->right = NULL;
        return t;
    }

    // otherwise, recurse down the tree
    if(key<p->data)
        p->left = insert(p->left, key);
    else if(key>p->data)
        p->right = insert(p->right, key);

    return p;
};
