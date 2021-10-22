#include <iostream>
#include <algorithm>
#include <stack>

struct Node {
	char data;
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
		return top ? 0 : 1;
	}
	int isFull() {
		Node* t = new Node;
		int r = t ? 1 : 0;
		delete t;
		return r;
	}
	void push(char val) {
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
	char pop() {
		Node* p;
		char x = 'Z';
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
	char Top() {
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

int pre(char x) {
	if (x == '+' || x == '-')
		return 1;
	else if (x == '*' || x == '/')
		return 2;
	else if (x == '^')
		return 3;
	else
		return 0;
}

std::string convert(std::string exp) {
	std::stack<char>st;
	std::string postfix = "";

	for (int i = 0; i < exp.length(); i++) {
		if (exp[i] == ' ')continue;

		if (isdigit(exp[i])||isalpha(exp[i]))
			postfix += exp[i];
		else if (exp[i] == '(')
			st.push(exp[i]);
		else if (exp[i] == ')') {
			while (st.top() != '(') {
				postfix += st.top();
				st.pop();
			}
			st.pop();	// to remove (
		}
		else {
			while (!st.empty()&&pre(exp[i]) <= pre(st.top())) {
				postfix += st.top();
				st.pop();
			}
			st.push(exp[i]);
		}
	}

	while (!st.empty()) {
		postfix += st.top();
		st.pop();
	}

	return postfix;

}





int main() {

	char str[] = "((a+b)*c-d)*e";
	
	std::string s = convert(str);
	
	std::cout << s << std::endl;
	
	return 0;

}
