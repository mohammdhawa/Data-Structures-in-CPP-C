#include <iostream>

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
	void pop() {
		if (top == -1) {
			std::cout << "Stack is underflow" << std::endl;
			return;
		}
		top--;
	}
};

bool isBalance(std::string exp) {
	Stack st(exp.length()+1);

	for (int i = 0; exp[i] != '\0'; i++) {
		if (exp[i] == '(')
			st.push(exp[i]);
		else if (exp[i] == ')') {
			if (st.isEmpty())
				return false;
			else
				st.pop();
		}
	}
	if (st.isEmpty())
		return true;
	else
		return false;
}

int main() {
	std::string str = "((a+b)*(c-d))";

	if (isBalance(str))
		std::cout << "This expression is balanced" << std::endl;
	else
		std::cout << "This expression is not balanced" << std::endl;


	
	
	return 0;

}

