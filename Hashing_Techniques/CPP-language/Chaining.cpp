#include <iostream>

struct Node {
	int data;
	Node* next;
};

// hash table
class HashTable {
public:
	Node** HT;
	HashTable() {
		HT = new Node * [10];
		for (int i = 0; i < 10; i++)
			HT[i] = nullptr;
	}
	~HashTable() {
		for (int i = 0; i < 10; i++) {
			Node* p = HT[i];
			while (HT[i]) {
				HT[i] = HT[i]->next;
				delete p;
				p = HT[i];
			}
		}
		delete[] HT;
	}
	int hash(int key) {
		return key % 10;
	}
	void insert(int key) {
		int hIdx = hash(key);
		Node* t = new Node;
		t->data = key;
		t->next = nullptr;
		// case: no nodes in the linked list
		if (HT[hIdx] == nullptr)
			HT[hIdx] = t;
		else {
			Node* p = HT[hIdx];
			Node* q = HT[hIdx];
			// Traverse to find insert position
			while (p && p->data < key) {
				q = p;
				p = p->next;
			}
			// case: insert position is first
			if (q == HT[hIdx]) {
				t->next = HT[hIdx];
				HT[hIdx] = t;
			}
			else {
				t->next = q->next;
				q->next = t;
			}
		}
	}
	int search(int key) {
		int hIdx = hash(key);
		Node* p = HT[hIdx];
		while (p) {
			if (p->data == key)
				return p->data;
			p = p->next;
		}
		return -1;
	}
};

int main() {
	int A[] = { 16, 12, 25, 39, 6, 122, 5, 68, 75 };
	int n = sizeof(A) / sizeof(A[0]);
	HashTable H;

	for (int i = 0; i < n; i++)
		H.insert(A[i]);

	std::cout << "Successful search" << std::endl;
	int key = 6;
	int value = H.search(key);
	std::cout << "key: " << key << ", value: " << value << std::endl;
	std::cout << "Unsuccessful search" << std::endl;
	key = 95;
	value = H.search(key);
	std::cout << "key: " << key << ", velue: " << value << std::endl;


	return 0;
}
