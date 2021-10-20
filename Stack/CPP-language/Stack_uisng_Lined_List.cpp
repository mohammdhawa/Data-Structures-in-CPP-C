#include <iostream>

struct Node {
	int data;
	Node* next;
};

class Stack {
	Node* top;
public:
	Stack() {
		top = nullptr;
	}
	~Stack() {
		Node* temp = top;
		while (top) {
			top = top->next;
			delete temp;
			temp = top;
		}
	}
	bool isEmpty() {
		return top ? 0: 1;
	}
	int isFull() {
		Node* t = new Node;
		int r = t ? 1 : 0;
		delete t;
		return r;
	}
	void push(int val) {
		Node* t = new Node;
		if (t == nullptr) {
			std::cout << "Stack Overflow!" << std::endl;
		}
		else {
			t->data = val;
			t->next = top;
			top = t;
		}
	}
	int pop() {
		Node* p;
		int x = -1;
		if (top == nullptr) {
			std::cout << "Stack Underflow!" << std::endl;
		}
		else {
			p = top;
			x = p->data;
			top = top->next;
			delete p;
		}
		return x;
	}
	int peek(int pos) {
		if (isEmpty()) {
			return -1;
		}
		else {
			Node* p = top;

			for (int i = 0; p != nullptr && i < pos - 1; i++) {
				p = p->next;
			}

			if (p != nullptr) {
				return p->data;
			}
			else {
				return -1;
			}
		}
	}
	int Top() {
		if (top) {
			return top->data;
		}
		return -1;
	}
	void display() {
		Node* p = top;
		while (p) {
			std::cout << p->data << ' ';
			p = p->next;
		}
		std::cout << std::endl;
	}
};

int main() {
	
	Stack st;

	st.push(11);
	st.push(22);
	st.push(33);
	st.push(44);
	st.push(55);

	std::cout << st.pop() << " has been popped" << std::endl;

	std::cout << "top is: " << st.Top() << std::endl;

	std::cout << "peek is: " << st.peek(2) << std::endl;

	st.display();
	
	return 0;

}

