#include <iostream>

class Queue {
	int* Q;
	int rear;
	int front;
	int size;
public:
	Queue(int n) {
		size = n;
		Q = new int[size];
		rear = front = -1;
	}
	~Queue() {
		delete[] Q;
	}
	bool isFull() {
		return (rear + 1) % size == front;
	}
	bool isEmpty() {
		return front == -1;
	}
	void enQueue(int x) {
		if (isFull()) {
			std::cout << "Queue is full" << std::endl;
			return;
		}
		else if (isEmpty())
			front = rear = 0;
		else
			rear = (rear + 1) % size;
		Q[rear] = x;
	}
	void display() {
		for (int i = front; i <= rear; i++)
			std::cout << Q[i] << ' ';
		std::cout << std::endl;
	}
	int Rear() {
		if (!isEmpty())
			return Q[rear];
		return -1;
	}
	int Front() {
		if (front != -1)
			return Q[front];
		return -1;
	}
	int deQueue() {
		int x = -1;
		if (isEmpty())
			std::cout << "Queue is empty" << std::endl;
		else if (rear == front) {
			x = Q[rear];
			rear = front = -1;
		}
		else {
			x = Q[front];
			front = (front + 1) % size;
		}
		return x;
	}
};

int main() {
	Queue k(5);

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
