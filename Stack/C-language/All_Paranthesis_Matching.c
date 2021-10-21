#include <stdio.h>
#include<stdlib.h>

struct Stack
{
    int size;
    int top;
    int*s;
};

void create(struct Stack *st)
{
    st->top = -1;
    st->s = (int*)malloc(st->size*sizeof(int));
}

int isEmpty(struct Stack st)
{
    if(st.top==-1)
        return 1;
    return 0;
}

int siFull(struct Stack st)
{
    if(st.top==st.size-1)
        return 1;
    return 0;
}

void push(struct Stack *st, int val)
{
    if(st->top==st->size-1)
        printf("Stack is Overflow\n");
    else
    {
        st->top++;
        st->s[st->top] = val;
    }
}

int pop(struct Stack *st)
{
    if(st->top==-1)
    {
        printf("Stack is Underflow\n");
        exit(1);
    }
    return st->s[st->top--];
}

int peek(struct Stack st, int index)
{
    if(st.top-index<0)
    {
        printf("Invalid index\n");
        exit(1);
    }
    return st.s[st.top-index+1];
}

int Top(struct Stack st)
{
    if(st.top==-1)
    {
        printf("Stack is Underflow\n");
        exit(1);
    }
    return st.s[st.top];
}

void display(struct Stack st)
{
    for(int i = st.top; i>=0; i--)
        printf("%d ", st.s[i]);
    printf("\n");
}

int isBalance(char*exp)
{
    struct Stack st;
    st.size = strlen(exp);
    st.s = (int*)malloc(st.size*sizeof(int));
    st.top = -1;
    int x;

    for(int i = 0; exp[i]!='\0'; i++)
    {
        if(exp[i]=='(' || exp[i]=='[' || exp[i]=='{')
            push(&st, exp[i]);

        else if(exp[i]==')' || exp[i]==']'||exp[i]=='}')
        {
            if(isEmpty(st))
                return 0;

            switch(exp[i])
            {
            case ')':
                x = Top(st);
                pop(&st);
                if(x=='[' || x=='{')
                    return 0;
                break;
            case ']':
                x = Top(st);
                pop(&st);
                if(x=='(' || x=='{')
                    return 0;
                break;
            case '}':
                x = Top(st);
                pop(&st);
                if(x=='(' || x=='[')
                    return 0;
                break;
            }
        }
    }
    return isEmpty(st);
}

int main()
{
    char* exp = "{()}[]";

    printf("%d ", isBalance(exp));



    return 0;
}
