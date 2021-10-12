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

int max(Node* p) {
	int m = INT_MIN;
	while (p) {
		if (p->data > m)
			m = p->data;
		p = p->next;
	}
	return m;
}

int max_r(Node* p) {
	int x = 0;
	if (p == nullptr)
		return INT_MIN;

	x = max(p->next);
	return x > p->data ? x : p->data;
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

	std::cout << "The maximum number of list: " << max(head) << std::endl;
	std::cout << "The maximum number of list: " << max_r(head) << std::endl;
	


	return 0;

}
