#include <stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node*next;
}*top=NULL;

void push(int val)
{
    struct Node*t = (struct Node*)malloc(sizeof(struct Node));

    if(t==NULL)
        printf("Stack is Overflow\n");
    else
    {
        t->data = val;
        t->next = top;
        top = t;
    }
}

int pop()
{
    struct Node*t;
    int x = -1;

    if(top == NULL)
        printf("Stack is Underflow\n");
    else
    {
        t = top;
        top = top->next;
        x = t->data;
        free(t);
    }
    return x;
}

int Top()
{
    if(top==NULL)
    {
        printf("Stack is Underflow\n");
        return -1;
    }
    return top->data;
}

int peek(int pos)
{
    struct Node *p = top;
    for(int i = 0; p!=NULL, i<pos-1; i++)
        p = p->next;

    if(p!=NULL)
        return p->data;
    else
        return -1;
}

void display()
{
    struct Node*p = top;
    while(p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int isBalance(char*exp)
{
    for(int i = 0; exp[i]!='\0'; i++)
    {
        if(exp[i]=='(')
            push(exp[i]);
        else if(exp[i]==')')
        {
            if(top==NULL)
                return 0;
            else
                pop();
        }
    }
    if(top==NULL)
        return 1;
    else
        return 0;
}

int main()
{
    char* exp = "(((a+b)*(c-d))";

    printf("%d ", isBalance(exp));



    return 0;
}
