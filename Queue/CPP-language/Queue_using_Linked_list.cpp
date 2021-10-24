#include <iostream>

struct Node {
	int data;
	Node* next;
};

class Queue {
	Node* front;
	Node* rear;
public:
	Queue() {
		rear = new Node;
		front = rear = nullptr;
	}
	bool isEmpty() {
		return front == nullptr;
	}
	bool isFull() {
		Node* t = new Node;
		return t == nullptr;
	}
	void enQueue(int x) {
		if (isFull()) {
			std::cout << "Queue is full" << std::endl;
			return;
		}

		Node* t = new Node;
		t->data = x;
		t->next = nullptr;
		if (isEmpty()) {
			rear = front = t;
		}
		else {
			rear->next = t;
			rear = t;
		}
	}
	int deQueue() {
		int x = -1;
		if (isEmpty())
			std::cout << "Queue is empty" << std::endl;
		
		Node* p = front;
		front = front->next;
		x = p->data;

		if (front == nullptr)
			rear = nullptr;
		delete p;

		return x;
		
	}
	int Front() {
		if (!isEmpty())
			return front->data;
		return -1;
	}
	int Rear() {
		if (!isEmpty())
			return rear->data;
		return -1;
	}
	void display() {
		Node* p = front;
		while (p) {
			std::cout << p->data << " ";
			p = p->next;
		}
		std::cout << std::endl;
	}
};

int main() {
	
	Queue k;

	k.enQueue(8);
	k.enQueue(12);
	k.enQueue(14);
	k.enQueue(15);

	k.display();

	std::cout << "front: " << k.Front() << std::endl;
	std::cout << "rear: " << k.Rear() << std::endl;
	
	std::cout << k.deQueue() << " has been deleted" << std::endl;
	k.enQueue(17);
	k.display();
	std::cout << "front: " << k.Front() << std::endl;
	std::cout << "rear: " << k.Rear() << std::endl;
	

	
	
	return 0;

}
