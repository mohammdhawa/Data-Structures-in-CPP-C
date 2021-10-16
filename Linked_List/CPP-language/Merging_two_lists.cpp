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

Node* merge(Node* first, Node* second) {
	Node* third;
	Node* last;

	if (first->data < second->data) {
		third = last = first;
		first = first->next;
		last->next = nullptr;
	}
	else {
		third = last = second;
		second = second->next;
		last->next = nullptr;
	}

	while (first && second) {
		if (first->data < second->data) {
			last->next = first;
			last = first;
			first = first->next;
			last->next = nullptr;
		}
		else {
			last->next = second;
			last = second;
			second = second->next;
			last->next = nullptr;
		}
	}
	if (first)
		last->next = first;
	else
		last->next = second;

	return third;
}


int main() {
	
	int A[] = { 2, 8, 10, 15};
	int B[] = { 4, 7, 12, 14 };

	Node* first = new Node;
	Node* temp;
	Node* last;

	first->data = A[0];
	first->next = nullptr;
	last = first;

	for (int i = 1; i < sizeof(A) / sizeof(A[0]); i++) {
		temp = new Node;
		temp->data = A[i];
		temp->next = nullptr;
		last->next = temp;
		last = temp;
	}

	Node* second = new Node;
	Node* temp2;
	second->data = B[0];
	second->next = nullptr;
	Node* last2 = second;
	for (int i = 1; i < sizeof(B) / sizeof(B[0]); i++) {
		temp2 = new Node;
		temp2->data = B[i];
		temp2->next = nullptr;
		last2->next = temp2;
		last2 = temp2;
	}

	display(first);
	std::cout << std::endl;

	display(second);
	std::cout << std::endl;

	Node* third = new Node;
	third = merge(first, second);

	display(third);
	std::cout << std::endl;
	

	
	return 0;

}

