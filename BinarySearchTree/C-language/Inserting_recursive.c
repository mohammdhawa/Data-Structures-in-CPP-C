// A utility function to create a new BST node
struct Node* newNode(int item)
{
    struct Node*temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
};

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
