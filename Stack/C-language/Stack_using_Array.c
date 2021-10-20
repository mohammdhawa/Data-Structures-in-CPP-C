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
    printf("Enter size: ");
    scanf("%d", &st->size);
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

int main()
{
    struct Stack st;
    create(&st);

    push(&st, 10);
    push(&st, 20);
    push(&st, 30);
    push(&st, 40);
    push(&st, 50);

    display(st);

    printf("%d had been popped \n", pop(&st));

    printf("top is: %d \n", Top(st));

    printf("%d \n",peek(st,2));


    return 0;
}
