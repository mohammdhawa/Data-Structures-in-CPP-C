#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node*left;
    int data;
    struct Node*right;
}*root = NULL;

void insert(int key)
{
    if(root == NULL)
    {
        struct Node*t = (struct Node*)malloc(sizeof(struct Node));
        t->data = key;
        t->left = t->right = NULL;
        root = t;
    }
    struct Node*p = root;
    struct Node*r = NULL;

    while(p)
    {
        r = p;

        if(key==p->data)
            return;
        else if(key<p->data)
            p = p->left;
        else
            p = p->right;
    }

    struct Node*t = (struct Node*)malloc(sizeof(struct Node));
    t->data = key;
    t->left = t->right = NULL;
    if(t->data<r->data)
        r->left = t;
    else
        r->right = t;
}

void inorder(struct Node*p)
{
    if(p)
    {
        inorder(p->left);
        printf("%d ", p->data);
        inorder(p->right);
    }
}

int main()
{
    

    insert(30);
    insert(20);
    insert(25);
    insert(10);
    insert(40);
    insert(35);
    insert(50);

    inorder(root);


    return 0;
}
