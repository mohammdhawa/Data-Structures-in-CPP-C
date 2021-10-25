#include <stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

void push(struct Node** top_ref, int new_data)
{
	struct Node* t = (struct Node*)malloc(sizeof(struct Node));
	if (t == NULL) {
		printf("Stack overflow \n");
		exit(0);
	}

	t->data = new_data;
	t->next = (*top_ref);
	(*top_ref) = t;
}

int pop(struct Node** top)
{
	int res;
	struct Node* temp;

	if (*top == NULL) {
		printf("Stack underflow \n");
		exit(0);
	}
	else {
		temp = *top;
		res = temp->data;
		*top = temp->next;
		free(temp);
		return res;
	}
}

struct queue {
	struct Node* stack1;
	struct Node* stack2;
};

void enQueue(struct queue* q, int x)
{
	push(&q->stack1, x);
}

int deQueue(struct queue* q)
{
	int x;

	if (q->stack1 == NULL && q->stack2 == NULL) {
		printf("Q is empty");
		exit(0);
	}

	/* Move elements from stack1 to stack 2 only if
	   stack2 is empty */
	if (q->stack2 == NULL) {
		while (q->stack1 != NULL) {
			x = pop(&q->stack1);
			push(&q->stack2, x);
		}
	}

	x = pop(&q->stack2);
	return x;
}

int main()
{
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    q->stack1 = NULL;
    q->stack2 = NULL;
    enQueue(q, 1);
    enQueue(q, 2);
    enQueue(q, 3);

    /* Dequeue items */
    printf("%d ", deQueue(q));
    printf("%d ", deQueue(q));
    printf("%d ", deQueue(q));


    return 0;
}
