#include <iostream>

struct Node {
	int data;
	Node* next;
};

void display_by_iteration(Node* p) {
	while (p != nullptr) {
		std::cout << p->data << ' ';
		p = p->next;
	}
}

void display_by_recursion(Node* p) {
	if (p != nullptr) {
		std::cout << p->data << ' ';
		display_by_recursion(p->next);
	}
}

void reverse_display(Node* p) {
	if (p != nullptr) {
		reverse_display(p->next);
		std::cout << p->data << ' ';
	}
}

int main() {
	
	int A[] = { 3, 5, 7, 10, 15 };

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


	display_by_iteration(head);
	std::cout << std::endl;
	display_by_recursion(head);
	std::cout << std::endl;
	reverse_display(head);


	return 0;

}
