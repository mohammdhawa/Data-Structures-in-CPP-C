#include <iostream>

struct Node {
	int data;
	Node* next;
}*first = nullptr, * second = nullptr;

void display(Node* p) {
	while (p != nullptr) {
		std::cout << p->data << ' ';
		p = p->next;
	}
}

void create(int A[], int n) {
	Node* temp, *last;

	first = new Node;
	first->data = A[0];
	first->next = nullptr;
	last = first;

	for (int i = 1; i < n; i++) {
		temp = new Node;
		temp->data = A[i];
		temp->next = nullptr;
		last->next = temp;
		last = temp;
	}
}

bool isLoop(Node* first) {
	Node* p, * q;
	p = q = first;

	do {
		p = p->next;
		q = q->next;
		q = q != nullptr ? q->next : nullptr;
	} while (q && p && q != p);

	if (p == q)
		return true;
	else
		return false;
}

int main() {
	
	Node* t1, * t2;

	int A[] = { 10, 20, 30, 40, 50 };
	int n = sizeof(A) / sizeof(A[0]);

	create(A, n);

	t1 = first->next->next;
	t2 = first->next->next->next->next;
	//t2->next = t1;

	std::cout << isLoop(first) << std::endl;
	

	
	return 0;

}

