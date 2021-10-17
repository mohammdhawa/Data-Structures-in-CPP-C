#include <iostream>

struct Node {
	int data;
	Node* next;
};

class circularLinkedList {
	Node* head;
public:
	circularLinkedList(int A[], int n);
	~circularLinkedList() {
		Node* p = head;
		while (p->next != head) {
			p = p->next;
		}

		while (p != head) {
			p->next = head->next;
			delete head;
			head = p->next;
		}

		if (p == head) {
			delete head;
			head = nullptr;
		}
	}
	void display();


};



int main() {
	
	int A[] = { 10, 20, 30, 40, 50 };
	int n = sizeof(A) / sizeof(A[0]);

	circularLinkedList clk(A, n);

	clk.display();
	

	
	return 0;

}

circularLinkedList::circularLinkedList(int A[], int n) {
	Node* temp, * last;

	head = new Node;
	head->data = A[0];
	head->next = head;
	last = head;

	for (int i = 1; i < n; i++) {
		temp = new Node;
		temp->data = A[i];
		temp->next = last->next;
		last->next = temp;
		last = temp;
	}
}

void circularLinkedList::display() {
	Node* p = head;

	do {
		std::cout << p->data << ' ';
		p = p->next;
	} while (p != head);

	std::cout << std::endl;
}
