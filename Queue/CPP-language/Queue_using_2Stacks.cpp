#include <iostream>
#include <stack>

class Queue {
	std::stack<int>s1;
	std::stack<int>s2;
public:
	void enQueue(int x) {
		s1.push(x);
	}
	int deQueue() {
		int x = -1;
		if (s2.empty()) {
			if (s1.empty()) {
				std::cout << "Queue is empty" << std::endl;
				return -1;
			}
			else {
				while (!s1.empty()) {
					s2.push(s1.top());
					s1.pop();
				}
			}
		}
		x = s2.top();
		s2.pop();

		return x;
	}
};

int main() {
	Queue q;
	q.enQueue(1);
	q.enQueue(2);
	q.enQueue(3);

	std::cout << q.deQueue() << '\n';
	std::cout << q.deQueue() << '\n';
	std::cout << q.deQueue() << '\n';
	
	
	return 0;

}
