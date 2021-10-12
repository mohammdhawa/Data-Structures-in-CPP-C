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

Node* search(Node* p, int key) {
	while (p) {
		if (key == p->data)
			return p;
		p = p->next;
	}
	return nullptr;
}

Node* search_r(Node* p, int key) {
	if (p == nullptr)
		return nullptr;
	if (key == p->data)
		return p;
	return search_r(p->next, key);
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

	
	std::cout << search(head, 10) << std::endl;
	std::cout << search_r(head, 10) << std::endl;
	std::cout << search(head, 101) << std::endl;
	std::cout << search_r(head, 101) << std::endl;

	if (search(head, 3))
		std::cout << "Node is found" << std::endl;
	else
		std::cout << "Node not found" << std::endl;



	return 0;

}
