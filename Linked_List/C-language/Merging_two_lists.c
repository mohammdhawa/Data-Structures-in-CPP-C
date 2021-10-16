#include <stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void display(struct Node*p)
{
    while(p!=NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

void insert(struct Node**head, int val)
{
    struct Node*newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;

    newNode->next = (*head);
    (*head) = newNode;
}

struct Node* merge(struct Node*first, struct Node*second)
{
    struct Node*third;
    struct Node*last;

    if (first->data < second->data) {
		third = last = first;
		first = first->next;
		last->next = NULL;
	}
	else {
		third = last = second;
		second = second->next;
		last->next = NULL;
	}

	while (first && second) {
		if (first->data < second->data) {
			last->next = first;
			last = first;
			first = first->next;
			last->next = NULL;
		}
		else {
			last->next = second;
			last = second;
			second = second->next;
			last->next = NULL;
		}
	}
	if (first)
		last->next = first;
	else
		last->next = second;

	return third;

    return third;
};

int main()
{
    struct Node* first = NULL;
    insert(&first, 2);
    insert(&first, 8);
    insert(&first, 10);
    insert(&first, 15);

    struct Node*second = NULL;
    insert(&second, 4);
    insert(&second, 7);
    insert(&second, 12);
    insert(&second, 14);

    display(first);
    printf("\n");
    display(second);
    printf("\n");

    struct Node*third = NULL;

    third = merge(first, second);
    display(third);
    printf("\n");


	return 0;
}
