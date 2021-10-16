#include <iostream>

struct Node {
	int data;
	Node* next;
};

void display(Node* p) {
	while (p != nullptr) {
		std::cout << p->data << ' ';
		p = p->next;
	}
}

void concatenate(struct Node* a, struct Node* b)
{
	if (a->next == NULL)
		a->next = b;
	else
		concatenate(a->next, b);
}


int main() {
	
	int A[] = { 2, 9, 6, 8};
	int B[] = { 10, 4, 7 };

	Node* head = new Node;
	Node* temp;
	Node* last;

	head->data = A[0];
	head->next = nullptr;
	last = head;

	for (int i = 1; i < sizeof(A) / sizeof(A[0]); i++) {
		temp = new Node;
		temp->data = A[i];
		temp->next = nullptr;
		last->next = temp;
		last = temp;
	}

	Node* head2 = new Node;
	Node* temp2;
	head2->data = B[0];
	head2->next = nullptr;
	Node* last2 = head2;
	for (int i = 1; i < sizeof(B) / sizeof(B[0]); i++) {
		temp2 = new Node;
		temp2->data = B[i];
		temp2->next = nullptr;
		last2->next = temp2;
		last2 = temp2;
	}

	display(head);
	std::cout << std::endl;

	display(head2);
	std::cout << std::endl;


	Node* third = new Node;
	concatenate(head, head2);

	display(head);
	std::cout << std::endl;

	
	return 0;

}

