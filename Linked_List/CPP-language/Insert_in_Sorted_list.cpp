#include <iostream>

struct Node {
	int data;
	Node* next;
};

void display(Node* p) {
	while (p) {
		std::cout << p->data << ' ';
		p = p->next;
	}
}

void insertInSorted(Node** head, int val) {
	Node* curr = *(head);
	Node* prev = nullptr;

	while (curr && curr->data < val) {
		prev = curr;
		curr = curr->next;
	}

	Node* newNode = new Node;
	newNode->data = val;

	newNode->next = prev->next;
	prev->next = newNode;
}

int main() {
	
	int A[] = { 7, 9, 15, 23};

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

	insertInSorted(&head, 18);
	display(head);
	std::cout << std::endl;



	return 0;

}
