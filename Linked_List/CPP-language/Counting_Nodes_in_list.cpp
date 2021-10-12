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

int count(Node* p) {
	int c = 0;

	while (p != nullptr) {
		c++;
		p = p->next;
	}

	return c;
}

int count_r(Node* p) {
	if (p == nullptr)
		return 0;
	else
		return count_r(p->next)+1;
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


	std::cout << "Number of nodes in this list is: " << count(head) << std::endl;
	std::cout << "Number of nodes in this list is: " << count_r(head) << std::endl;



	return 0;

}
