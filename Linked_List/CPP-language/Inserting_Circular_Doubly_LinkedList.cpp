#include <iostream>

struct Node {
	Node* prev;
	int data;
	Node* next;
};

class circularDoublyLinkedList {
	Node* head;
public:
	circularDoublyLinkedList() {
		head = nullptr;
	}
	int length() {
		int count = 0;
		Node* p = head;
		do {
			count++;
			p = p->next;
		} while (p != head);
		return count;
	}
	void insertFirst(int x) {
		Node* t = new Node;
		t->data = x;

		if (head == nullptr) {
			head = t;
			head->next = head;
			head->prev = head;
		}
		else {
			Node* last = head;
			while (last->next != head)
				last = last->next;

			last->next = t;
			t->prev = last;
			t->next = head;
			head->prev = t;
			head = t;
		}
	}
	void insertAt(int pos, int x) {
		if (pos<0 || pos>length()) {
			std::cout << "position is out of range" << std::endl;
			return;
		}

		Node* t = new Node;
		t->data = x;

		if (pos == 0) {
			if (head == nullptr) {
				head = t;
				head->next = head;
				head->prev = head;
			}
			else {
				Node* last = head;
				while (last->next != head)
					last = last->next;

				last->next = t;
				t->prev = last;
				t->next = head;
				head->prev = t;
				head = t;
			}
		}
		else {
			Node* p = head;
			for (int i = 0; i < pos-1; i++)
				p = p->next;

			t->next = p->next;
			p->next->prev = t;

			p->next = t;
			t->prev = p;
		}
	}
	void insertEnd(int x) {
		Node* t = new Node;
		t->data = x;

		if (head == nullptr) {
			head = t;
			head->prev = head;
			head->next = head;
		}
		else {
			Node* last = head;
			while (last->next != head)
				last = last->next;

			t->next = last->next;
			last->next->prev = t;
			last->next = t;
			t->prev = last;
		}
	}
	void display() {
		Node* p = head;
		do {
			std::cout << p->data << ' ';
			p = p->next;
		} while (p != head);
		std::cout << std::endl;
	}
};

int main() {
	circularDoublyLinkedList cdll;

	cdll.insertFirst(10);
	cdll.insertFirst(20);
	cdll.insertFirst(30);
	cdll.insertFirst(40);
	cdll.insertFirst(50);

	cdll.display();

	cdll.insertAt(0, 44);

	cdll.display();
	
	

	return 0;

}
