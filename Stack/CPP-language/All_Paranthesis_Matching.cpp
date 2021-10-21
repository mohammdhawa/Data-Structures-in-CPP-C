#include <iostream>
#include <stack>

class Stack {
	int* S;
	int size;
	int top;
public:
	Stack(int n) {
		size = n;
		S = new int[size];
		top = -1;
	}
	~Stack() {
		delete[] S;
	}
	bool isEmpty() {
		return top == -1;
	}
	void push(int val) {
		if (top == size - 1) {
			std::cout << "Stack is overflow" << std::endl;
			return;
		}
		S[++top] = val;
	}
	int pop() {
		if (top == -1) {
			std::cout << "Stack is underflow" << std::endl;
			exit(1);
		}
		return S[top--];
	}
	int Top() {
		if (top == - 1) {
			std::cout << "Stack is underflow" << std::endl;
			exit(1);
		}
		if (top == size - 1) {
			std::cout << "Stack is overflow" << std::endl;
			exit(1);
		}

		return S[top];

	}
};

bool isBalance(std::string expr) {
	Stack s(expr.length());
	char x;

	for (int i = 0; i < expr.length(); i++)
	{
		if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{')
			s.push(expr[i]);

		if (expr[i] == ')' || expr[i] == '}' || expr[i] == ']') {
			if (s.isEmpty())
				return false;
			switch (expr[i]) {
			case ')':
				x = s.Top();
				s.pop();
				if (x == '{' || x == '[')
					return false;
				break;

			case '}':
				x = s.Top();
				s.pop();
				if (x == '(' || x == '[')
					return false;
				break;

			case ']':
				x = s.Top();
				s.pop();
				if (x == '(' || x == '{')
					return false;
				break;
			}
		}

		
	}

	return (s.isEmpty());
}

int main() {
	std::string str = "{()}[]";

	if (isBalance(str))
		std::cout << "This expression is balanced" << std::endl;
	else
		std::cout << "This expression is not balanced" << std::endl;


	
	
	return 0;

}

