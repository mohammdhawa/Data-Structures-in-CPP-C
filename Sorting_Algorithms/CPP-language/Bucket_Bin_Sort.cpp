#include <iostream>

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

int findMax(int A[], int n) {
	int mx = A[0];
	for (int i = 1; i < n; i++) {
		if (mx < A[i])
			mx = A[i];
	}
	return mx;
}

struct Node {
	int data;
	Node* next;
};

void insert(Node** ptrBucket, int index) {
	Node* temp = new Node;
	temp->data = index;
	temp->next = nullptr;

	if (ptrBucket[index] == nullptr)
		ptrBucket[index] = temp;
	else {
		Node* p = ptrBucket[index];
		while (p->next != nullptr)
			p = p->next;
		p->next = temp;
	}
}

int Delete(Node** ptrBucket, int index) {
	Node* p = ptrBucket[index];
	ptrBucket[index] = ptrBucket[index]->next;
	int x = p->data;
	delete p;
	return x;
}

void bucketSort(int A[], int n) {
	int max, i, j;
	max = findMax(A, n);

	Node** Bucket = new Node * [max + 1];

	for (i = 0; i < max + 1; i++)
		Bucket[i] = nullptr;

	for (i = 0; i < n; i++)
		insert(Bucket, A[i]);

	i = 0; j = 0;
	while (i < max + 1) {
		while (Bucket[i] != nullptr)
			A[j++] = Delete(Bucket, i);
		i++;
	}

	delete[] Bucket;
}

int main()
{

	int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
	int n = sizeof(arr) / sizeof(arr[0]);

	for (int i = 0; i < n; i++)
		std::cout << arr[i] << ' ';
	std::cout << std::endl;

	bucketSort(arr, n);

	for (int i = 0; i < n; i++)
		std::cout << arr[i] << ' ';
	std::cout << std::endl;


	return 0;
}
