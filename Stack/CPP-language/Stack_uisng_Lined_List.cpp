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
		return top == nullptr;
	}
	int isFull() {
		Node* t = new Node;
		int r;
		if (t == nullptr)
			r = 1;
		else
			r = 0;
		delete t;

		return r;
	}
	void push(int val) {
		Node* t = new Node;

		if (t == nullptr) {
			std::cout << "Stack is Overflow" << std::endl;
			return;
		}

		t->data = val;
		t->next = top;
		top = t;
	}
	int pop() {
		if (top == nullptr) {
			std::cout << "Stack is Underflow" << std::endl;
			exit(1);
		}

		Node* p = top;
		int x = p->data;

		top = top->next;
		
		delete p;

		return x;
	}
	int peek(int pos) {
		Node* p = top;
		for (int i = 0; p != nullptr, i < pos - 1; i++)
			p = p->next;

		if (p != nullptr)
			return p->data;
		else
			return -1;
	}
	int Top() {
		if (top == nullptr) {
			std::cout << "Stack is Underflow" << std::endl;
			exit(1);
		}
		return top->data;
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
	st.peek(55);

	std::cout << st.pop() << " has been popped" << std::endl;

	std::cout << "top is: " << st.Top() << std::endl;

	std::cout << "peek is: " << st.peek(2) << std::endl;

	st.display();
	
	return 0;

}

