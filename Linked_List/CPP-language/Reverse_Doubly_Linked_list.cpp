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
	
	void deleteFirst() {
		Node* p = first;
		first = first->next;
		int x = p->data;
		delete p;
		if (first)
			first->prev = nullptr;

		std::cout << x << " has been deleted" << std::endl;
	}
	void deleteFrom(int pos) {
		if (pos<1 || pos>length()) {
			std::cout << "Error: you can not delete from empty list" << std::endl;
			return;
		}

		Node* p = first;
		if (pos == 1) {
			first = first->next;
			int x = p->data;
			delete p;
			if (first)
				first->prev = nullptr;
			std::cout << x << " has been deleted" << std::endl;
		}
		else {
			for (int i = 0; i < pos - 1; i++)
				p = p->next;

			int x = p->data;
			p->prev->next = p->next;
			if (p->next)
				p->next->prev = p->prev;
			delete p;

			std::cout << x << " has been deleted" << std::endl;
		}
	}
	void deleteEnd() {
		if (first == nullptr) {
			std::cout << "you can not delete from empty list" << std::endl;
			return;
		}
		Node* p = first;
		while (p->next)
			p = p->next;

		int x = p->data;
		p->prev->next = nullptr;
		delete p;

		std::cout << x << " has been deleted" << std::endl;
	}

	void reverseDispay() {
		Node* p = first;
		while (p->next) {
			p = p->next;
		}

		while (p) {
			std::cout << p->data << ' ';
			p = p->prev;
		}
	}

	void reverse() {
		Node* p = first;
		Node* temp = nullptr;

		while (p) {
			temp = p->prev;
			p->prev = p->next;
			p->next = temp;
			p = p->prev;
		}

		if (temp)
			first = temp->prev;
	}
};

int main() {
	int A[] = { 11, 22, 33, 44, 55 };
	int n = sizeof(A) / sizeof(A[0]);

	douplyLinkedList dll(A, n);

	dll.display();

	dll.reverse();
	
	dll.display();
	
	
	return 0;

}

