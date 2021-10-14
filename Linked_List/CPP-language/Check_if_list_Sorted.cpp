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



bool check_if_list_sorted(Node* head) {
	int x = INT_MIN;
	Node* p = head;
	while (p) {
		if (p->data < x)
			return false;
		x = p->data;
		p = p->next;
	}
	return true;
}

int main() {
	
	int A[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9};

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

	if (check_if_list_sorted(head))
		std::cout << "The list is sosrted" << std::endl;
	else
		std::cout << "The list is not sorted" << std::endl;
	

	
	return 0;

}
