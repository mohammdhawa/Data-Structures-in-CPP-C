struct Node* search(struct Node*p, int key)
{
    while(p)
    {
        if(key==p->data)
        {
            return p;
        }
        else if(key<p->data)
        {
            p = p->left;
        }
        else
        {
            p = p->right;
        }
    }
    return NULL;
};

int x = search(root, 40);
    if(x){
        printf("40 found in BST\n");
    }
    else
        printf("40 not found in BST\n");
