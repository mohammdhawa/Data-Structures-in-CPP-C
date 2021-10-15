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

int count(Node* p) {
	int c = 0;
	while (p) {
		c++;
		p = p->next;
	}
	return c;
}

void reverse_Arr(Node* head) {
	int n = count(head);
	int* A = new int[n];
	int i = -1;

	Node* p = head;
	while (p) {
		A[++i] = p->data;
		p = p->next;
	}

	p = head;
	while (p) {
		p->data = A[i--];
		p = p->next;
	}

}

void reverse_sliding_pointer(Node** head) {
	Node* p = (*head);
	Node* q = nullptr;
	Node* r = nullptr;

	while (p) {
		r = q;
		q = p;
		p = p->next;
		q->next = r;
	}

	(*head) = q;
}


int main() {
	
	int A[] = { 2, 4, 6, 8, 10};

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


	display(head);
	std::cout << std::endl;

	
	//reverse_Arr(head);

	reverse_sliding_pointer(&head);

	display(head);
	std::cout << std::endl;

	
	return 0;

}

