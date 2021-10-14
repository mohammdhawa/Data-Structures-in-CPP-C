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

void insertFirst(Node** head, int val) {
	Node* newNode = new Node;
	newNode->data = val;
	
	newNode->next = *(head);
	*(head) = newNode;
}

int count(Node* p) {
	int c = 0;
	while (p) {
		c++;
		p = p->next;
	}
	return c;
}

void insertAt(Node** head, int pos, int val) {
	if (pos<0 || pos>count(*(head))) {
		std::cout << "Error: pos out of range" << std::endl;
		return;
	}

	Node* newNode = new Node;
	newNode->data = val;

	if (*(head) == nullptr) {
		newNode->next = *(head);
		*(head) = newNode;
		return;
	}

	if (pos == 0) {
		insertFirst(*(&head), val);
		return;
	}

	Node* curr = *(head);
	for (int i = 1; i < pos - 1; i++)
		curr = curr->next;
	 
	newNode->next = curr->next;
	curr->next = newNode;
}

void insertAtEnd(Node** head, int val) {
	Node* newNode = new Node;
	newNode->data = val;
	newNode->next = nullptr;

	if (*head == nullptr) {
		newNode->next = nullptr;
		*(head) = newNode;
	}

	Node* curr = *head;
	while (curr->next != nullptr)
		curr = curr->next;

	curr->next = newNode;
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


	display(head);
	std::cout << std::endl;

	insertFirst(&head, 11);

	display(head);
	std::cout << std::endl;

	insertAt(&head, 3, 101);
	display(head);
	std::cout << std::endl;

	insertAtEnd(&head, 51);

	display(head);
	std::cout << std::endl;



	return 0;

}
