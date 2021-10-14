#include <iostream>

struct Node {
	int data;
	Node* next;
};

int count(Node* p) {
	int c = 0;
	while (p) {
		c++;
		p = p->next;
	}
	return c;
}

void display(Node* p) {
	while (p != nullptr) {
		std::cout << p->data << ' ';
		p = p->next;
	}
}

int deleteFirst(Node** head) {
	if (head == nullptr) {
		std::cout << "This list is empty";
		exit(1);
	}

	Node* temp = *head;
	int x = (*head)->data;

	(*head) = (*head)->next;
	delete temp;

	return x;
}

int deleteEnd(Node** head) {
	Node* temp = (*head);

	while (temp->next->next != nullptr) {
		temp = temp->next;
	}
	int x = temp->next->data;
	delete temp->next;
	temp->next = nullptr;

	return x;
}

int deleteFrom(Node** head, int pos) {
	if (pos<1 || pos>count((*head))) {
		std::cout << "Error: position is out of range" << std::endl;
		exit(1);
	}
	if (pos == 1) {
		Node* temp = (*head);
		int x = (*head)->data;

		(*head) = (*head)->next;
		delete temp;

		return x;
	}

	else {
		Node* curr = (*head);
		Node* prev = nullptr;

		for (int i = 0; i < pos - 1; i++) {
			prev = curr;
			curr = curr->next;
		}

		int x = curr->data;
		prev->next = curr->next;
		delete curr;

		return x;
	}
}

int main() {
	
	int A[] = { 8, 3, 9, 7, 6, 13, 29, 34};

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

	std::cout << deleteFirst(&head) << " has been deleted from list" << std::endl;

	display(head);
	std::cout << std::endl;

	std::cout << deleteEnd(&head) << " has been deleted from list" << std::endl;

	display(head);
	std::cout << std::endl;

	std::cout << deleteFrom(&head, 3) << " has been deleted from list" << std::endl;

	display(head);
	std::cout << std::endl;

	
	return 0;

}
