Node* search(Node*p, int key)
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
