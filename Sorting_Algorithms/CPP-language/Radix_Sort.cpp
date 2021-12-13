#include <iostream>

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

struct Node {
	int data;
	Node* next;
};

int Delete(Node** ptrBucket, int index) {
	Node* p = ptrBucket[index];
	ptrBucket[index] = ptrBucket[index]->next;
	int x = p->data;
	delete p;
	return x;
}

int countDigits(int x) {
	int count = 0;
	while (x != 0) {
		x = x / 10;
		count++;
	}
	return count;
}

void Insert(Node** ptrBins, int value, int idx) {
	Node* temp = new Node;
	temp->data = value;
	temp->next = nullptr;

	if (ptrBins[idx] == nullptr)
		ptrBins[idx] = temp;
	else {
		Node* p = ptrBins[idx];
		while (p->next != nullptr)
			p = p->next;
		p->next = temp;
	}
}

int getBinIndex(int x, int index) {
	return (int)(x / pow(10, index)) % 10;
}

void initializeBins(Node** p, int n) {
	for (int i = 0; i < n; i++)
		p[i] = nullptr;
}

void RadixSort(int A[], int n) {
	int max = findMax(A, n);
	int nPass = countDigits(max);

	Node** bins = new Node * [10];
	initializeBins(bins, 10);

	for (int pass = 0; pass < nPass; pass++) {
		for (int i = 0; i < n; i++) {
			int binIdx = getBinIndex(A[i], pass);
			Insert(bins, A[i], binIdx);
		}

		int i = 0; 
		int j = 0; 
		while (i < 10) {
			while (bins[i] != nullptr)
				A[j++] = Delete(bins, i);
			i++;
		}
		initializeBins(bins, 10);
	}

	delete[] bins;
}

int main()
{

	int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
	int n = sizeof(arr) / sizeof(arr[0]);

	for (int i = 0; i < n; i++)
		std::cout << arr[i] << ' ';
	std::cout << std::endl;

	//QuickSort(arr, 0, n-1);

	//iterative_mergeSort(arr, n);

	//mergeSort(arr, 0, n - 1);

	//countSort(arr, n);

	//bucketSort(arr, n);

	RadixSort(arr, n);

	for (int i = 0; i < n; i++)
		std::cout << arr[i] << ' ';
	std::cout << std::endl;


	return 0;
}
