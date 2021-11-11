#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node*left;
    int data;
    struct Node*right;
}*root = NULL;

void inorder(struct Node*p)
{
    if(p)
    {
        inorder(p->left);
        printf("%d ", p->data);
        inorder(p->right);
    }
}

int Height(struct Node*p)
{
    int x, y;
    if(p==NULL)
        return 0;

    x = Height(p->left);
    y = Height(p->right);
    if(x>y)
        return x+1;
    else
        return y+1;
}

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

////////////////////////////////////////////////////////////////////

struct Node* inPre(struct Node*p)
{
    while(p&&p->right!=NULL)
        p = p->right;
    return p;
};

struct Node* inSucc(struct Node*p)
{
    while(p&&p->left!=NULL)
        p = p->left;
    return p;
};

struct Node* Delete(struct Node*p, int key)
{
    struct Node*q;

    if(p==NULL)
        return NULL;

    if(p->left==NULL&&p->right==NULL)
    {
        if(p==root)
            root = NULL;
        free(p);
        return NULL;
    }

    if(key<p->data)
        p->left = Delete(p->left, key);
    else if(key>p->data)
        p->right = Delete(p->right, key);
    else
    {
        if(Height(p->left)>Height(p->right))
        {
            q = inPre(p->left);
            p->data = q->data;
            p->left = Delete(p->left, q->data);
        }
        else
        {
            q = inSucc(p->right);
            p->data = q->data;
            p->right = Delete(p->right, key);
        }
    }
    return p;
};

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
    printf("\n");

    Delete(root, 40);

    inorder(root);



    return 0;
}
