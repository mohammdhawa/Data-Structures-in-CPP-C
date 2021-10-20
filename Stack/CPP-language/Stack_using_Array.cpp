#include <iostream>

class Stack {
	int* s;
	int size;
	int top;
public:
	Stack(int n) {
		size = n;
		s = new int[size];
		top = -1;
	}
	bool isEmpty() {
		return top == -1;
	}
	bool isFull() {
		return top == size - 1;
	}
	void push(int val) {
		if (top == size - 1)
			std::cout << "Stack is Overflow" << std::endl;
		else
			s[++top] = val;
	}
	int pop() {
		if (top == -1) {
			std::cout << "Stack is Underflow" << std::endl;
			exit(1);
		}
		return s[top--];
	}
	int peek(int index) {
		if (top - index + 1 < 0) {
			std::cout << "Invalid index" << std::endl;
			exit(1);
		}
		return s[top - index + 1];
	}
	int Top() {
		if (isEmpty()) {
			std::cout << "Stack is empty" << std::endl;
			exit(1);
		}
		return s[top];
	}
};

int main() {
	int n;
	char ch;
	std::cout << "Enter size of Stack: ";
	std::cin >> n;
	
	Stack st(n);

	st.push(5);
	st.push(15);
	st.push(25);
	st.push(50);
	st.push(100);

	std::cout << "top is: " << st.Top() << std::endl;
	
	std::cout << st.pop() << " has poped" << std::endl;
	
	std::cout << "top is: " << st.Top() << std::endl;

	std::cout << "peek is: " << st.peek(1) << std::endl;
	
	return 0;

}

