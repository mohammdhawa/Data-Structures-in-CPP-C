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

int Add(Node* p) {
	int sum = 0;
	while (p) {
		sum += p->data;
		p = p->next;
	}
	return sum;
}

int Add_r(Node* p) {
	if (p == nullptr)
		return 0;
	else
		return Add_r(p->next) + p->data;
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

	std::cout << "Sum of all elements in list: " << Add(head) << std::endl;
	std::cout << "Sum of all elements in list: " << Add_r(head) << std::endl;
	


	return 0;

}
