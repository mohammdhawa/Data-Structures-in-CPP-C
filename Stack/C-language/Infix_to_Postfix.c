#include <stdio.h>
#include<stdlib.h>

struct Stack
{
    char data;
    struct Stack*next;
}*top=NULL;

void push(char x)
{
    struct Stack *t;
    t = (struct Stack*)malloc(sizeof(struct Stack));

    if(t==NULL)
        printf("Stack is full\n");
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

char pop()
{
    struct Stack*t;
    char x= -1;

    if(top==NULL)
        printf("Stack is empty\n");

    else
    {
        t = top;
        top = top->next;
        x = t->data;
        free(t);
    }
    return x;
}

int pre(char x) {
	if (x == '+' || x == '-')
		return 1;
	else if (x == '*' || x == '/')
		return 2;
	else
		return 0;
}

int isOperand(char x) {
	if (x == '+' || x == '-' || x == '*' || x == '/')
		return 0;
	else
		return 1;
}

char* infixToPostfix(char* infix)
{
    int i = 0;
    int j = 0;
    char*postfix;
    int len = strlen(infix);
    postfix = (char*)malloc((len+2)*sizeof(char));

    while(infix[i]!='\0')
    {
        if(isOperand(infix[i]))
            postfix[j++] = infix[i++];
        else
        {
            if(pre(infix[i])>pre(top->data))
                push(infix[i++]);
            else
                postfix[j++] = pop();
        }
    }
    while(top!=NULL)
        postfix[j++] = pop();

    postfix[j] = '\0';

    return postfix;
}

int main()
{

    char *infix="a+b*c-d/e";
    push(' ');
    char *postfix=infixToPostfix(infix);
    printf("%s ",postfix);



    return 0;
}
