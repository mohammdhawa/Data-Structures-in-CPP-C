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
		if (front == 0 && rear == size - 1) {
			return true;
		}
		return false;
	}
	bool isEmpty() {
		if (front == -1)
			return true;
		else
			return false;
	}
	void enQueue(int x) {
		if (rear == size - 1) {
			std::cout << "queue is full" << std::endl;
			return;
		}
		if (front == -1)
			front++;
		Q[++rear] = x;
	}
	void display() {
		for (int i = front; i <= rear; i++)
			std::cout << Q[i] << ' ';
		std::cout << std::endl;
	}
	int Rear() {
		if (rear != -1 && rear != size - 1)
			return Q[rear];
		return -1;
	}
	int Front() {
		if (front != -1)
			return Q[front];
		return -1;
	}
	int deQueue() {
		if (rear != -1)
			return Q[front++];
		return -1;
	}
};
