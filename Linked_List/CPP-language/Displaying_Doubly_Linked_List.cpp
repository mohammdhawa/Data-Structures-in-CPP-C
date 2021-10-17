#include <iostream>

struct Node {
	Node* prev;
	int data;
	Node* next;
};

class douplyLinkedList {
	Node* first;
public:
	douplyLinkedList(int A[], int n) {
		first = new Node;
		Node* t, * last;

		first->data = A[0];
		first->next = first->prev = nullptr;
		last = first;

		for (int i = 1; i < n; i++) {
			t = new Node;
			t->data = A[i];
			t->next = last->next;
			t->prev = last;
			last->next = t;
			last = t;
		}
	}
	void display() {
		Node* p = first;

		while (p) {
			std::cout << p->data << ' ';
			p = p->next;
		}

		std::cout << std::endl;
	}
};

int main() {
	int A[] = { 11, 22, 33, 44, 55 };
	int n = sizeof(A) / sizeof(A[0]);

	douplyLinkedList dll(A, n);

	dll.display();
	
	
	
	return 0;

}

