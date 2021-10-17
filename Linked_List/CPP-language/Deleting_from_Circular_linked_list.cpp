#include <iostream>

struct Node {
	int data;
	Node* next;
};

class circularLinkedList {
	Node* head;
public:
	circularLinkedList(int A[], int n);
	~circularLinkedList();
	int length();
	void display();
	void insertFirst(int val);
	void insertAt(int pos, int val);

	void deleteHead() {
		Node* p = head;

		while (p->next != head)
			p = p->next;

		p->next = head->next;
		int x = head->data;
		delete head;
		head = p->next;

		std::cout << x << " has been deleted from list" << std::endl;
	}

	void deleteFrom(int pos) {
		Node* p = head;
		Node* q;

		for (int i = 0; i < pos - 1; i++)
			p = p->next;

		q = p->next;
		p->next = q->next;
		int x = q->data;
		delete q;

		std::cout << x << " has been deleted from list" << std::endl;
	}


};



int main() {
	
	int A[] = { 10, 20, 30, 40, 50 };
	int n = sizeof(A) / sizeof(A[0]);

	circularLinkedList clk(A, n);

	clk.display();

	clk.insertFirst(5);

	clk.display();

	clk.insertAt(3, 29);
	clk.display();

	clk.deleteHead();
	clk.display();

	clk.deleteFrom(3);
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

circularLinkedList::~circularLinkedList() {
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

void circularLinkedList::display() {
	Node* p = head;

	do {
		std::cout << p->data << ' ';
		p = p->next;
	} while (p != head);

	std::cout << std::endl;
}

void circularLinkedList::insertFirst(int val) {
	Node* newNode = new Node;
	newNode->data = val;
	if (head == nullptr) {
		head = newNode;
		head->next = head;
	}
	else {
		Node* p = head;
		while (p->next != head) {
			p = p->next;
		}
		p->next = newNode;
		newNode->next = head;
		head = newNode;
	}
}

void circularLinkedList::insertAt(int pos, int val) {
	Node* newNode = new Node;
	Node* p;

	if (pos<0 || pos>length()) {
		std::cout << "Error: postion out of range" << std::endl;
		return;
	}

	if (pos == 0) {
		newNode->data = val;
		if (head == nullptr) {
			head = newNode;
			head->next = head;
		}
		else {
			p = head;
			while (p->next != head)
				p = p->next;
			p->next = newNode;
			newNode->next = head;
			head = newNode;
		}
	}
	else {
		p = head;
		for (int i = 0; i < pos - 1; i++)
			p = p->next;
		newNode->data = val;
		newNode->next = p->next;
		p->next = newNode;
	}
}

int circularLinkedList::length() {
	Node* p = head;
	int c = 0;

	do {
		c++;
		p = p->next;
	} while (p != head);

	return c;
}
