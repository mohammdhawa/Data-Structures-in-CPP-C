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
	int length() {
		int c = 0; 
		Node* p = first;
		while (p) {
			p = p->next;
			c++;
		}

		return c;
	}
	void display() {
		Node* p = first;

		while (p) {
			std::cout << p->data << ' ';
			p = p->next;
		}

		std::cout << std::endl;
	}
	void insertFirst(int val) {
		Node* t = new Node;

		t->data = val;
		t->prev = nullptr;
		t->next = first;
		first->prev = t;
		first = t;
	}
	void insertAt(int pos, int val) {
		if (pos<0 || pos>length()) {
			std::cout << "Error: position out of range" << std::endl;
			return;
		}

		Node* t = new Node;
		Node* p = first;

		t->data = val;
		for (int i = 0; i < pos - 1; i++)
			p = p->next;

		t->next = p->next;
		t->prev = p;
		if (p->next != nullptr)
			p->next->prev = t;
		p->next = t;
	}
	void insertEnd(int val) {
		Node* t = new Node;
		t->data = val;
		t->next = nullptr;

		if (first == nullptr) {
			t->prev = nullptr;
			first = t;
			return;
		}

		Node* last = first;
		while (last->next)
			last = last->next;

		last->next = t;
		t->prev = last;
	}
};

int main() {
	int A[] = { 11, 22, 33, 44, 55 };
	int n = sizeof(A) / sizeof(A[0]);

	douplyLinkedList dll(A, n);

	dll.display();

	dll.insertFirst(5);
	dll.display();

	dll.insertAt(4, 37);
	dll.display();
	
	
	dll.insertEnd(99);
	dll.display();
	
	return 0;

}

