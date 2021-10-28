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
	int length() {
		Node* p = head;
		int c = 0;
		
		do {
			c++;
			p = p->next;
		} while (p != head);

		return c;
	}
	void display();
	void insertFirst(int val) {
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
	void insertAt(int pos, int val) {
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
	void insertEnd(int x) {
        Node* t = new Node;
        t->data = x;

        if (head == nullptr) {
            head = t;
            head->next = head;
        }
        else {
            Node* last = head;
            while (last->next != head)
                last = last->next;

            t->next = head;
            last->next = t;
        }
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

	std::cout << clk.length() << std::endl;
	
	
	
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
