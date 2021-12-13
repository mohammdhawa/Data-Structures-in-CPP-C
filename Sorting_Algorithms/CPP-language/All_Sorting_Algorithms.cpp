#include <iostream>

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void bubbleSort(int arr[], int n) {
	int flag;
	for (int i = 0; i < n - 1; i++) {
		flag = 0;
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
				flag = 1; 
			}
		}
		if (flag == 0)
			break;	// or return 
	}
}

void insertionSort(int arr[], int n) {
	for (int i = 1; i < n; i++) {
		int j = i - 1;
		int x = arr[i];
		while (j > -1 && arr[j] > x) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = x;
	}
}

void SelectionSort(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		int k = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[k])
				k = j;
		}
		swap(arr[k], arr[i]);
	}
}

int partition(int A[], int low, int high) {
	int pviot = A[high];
	int i = low - 1;
	for (int j = low; j <= high - 1; j++) {
		if (A[j] < pviot) {
			i++;
			swap(A[i], A[j]);
		}
	}
	swap(A[i + 1], A[high]);
	return i + 1;
}

void QuickSort(int A[], int low, int high) {
	if (low < high) {
		int pviot = partition(A, low, high);
		QuickSort(A, low, pviot-1);
		QuickSort(A, pviot + 1, high);
	}
}

void merge(int A[], int l, int mid, int h) {
	int i, j, k;
	i = l;
	j = mid + 1;
	k = l;

	int* B = new int[h + 1];
	while (i <= mid && j <= h) {
		if (A[i] < A[j])
			B[k++] = A[i++];
		else
			B[k++] = A[j++];
	}
	
	for (; i <= mid; i++)
		B[k++] = A[i];
	for (; j <= h; j++)
		B[k++] = A[j];

	for (i = l; i <= h; i++)
		A[i] = B[i];

	//delete[] B;
}

void iterative_mergeSort(int A[], int n) {
	int l, mid, h, p, i;

	for (p = 2; p <= n; p = p * 2) {
		for (i = 0; i + p - 1 < n; i = i + p) {
			l = i;
			h = i + p - 1;
			mid = (l + h) / 2;
			merge(A, l, mid, h);
		}
	}
	if (p/2<n)
		merge(A, 0, p / 2-1, n - 1);
}

void mergeSort(int A[], int l, int h) {
	if (l < h) {
		int mid = (l + h) / 2;
		mergeSort(A, l, mid);
		mergeSort(A, mid + 1, h);
		merge(A, l, mid, h);
	}
}

int findMax(int A[], int n) {
	int mx = A[0];
	for (int i = 1; i < n; i++) {
		if (mx < A[i])
			mx = A[i];
	}
	return mx;
}

void countSort(int A[], int n) {
	int max;
	int* c;
	max = findMax(A, n);
	c = new int[max + 1];

	int i, j;
	for (i = 0; i < max + 1; i++)
		c[i] = 0;

	for (i = 0; i < n; i++)
		c[A[i]]++;

	i = 0; 
	j = 0; 

	while (i < max + 1) {
		if (c[i] > 0) {
			A[j++] = i;
			c[i]--;
		}
		else
			i++;
	}
	delete[] c;
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
//////////////////////////////////////////////////////////////////////////////////////

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

void ShellSort(int A[], int n) {
	for (int gap = n / 2; gap >= 1; gap /= 2) {
		for (int j = gap; j < n; j++) {
			int temp = A[j];
			int i = j - gap;
			while (i >= 0 && A[i] > temp) {
				A[i + gap] = A[i];
				i = i - gap;
			}
			A[i + gap] = temp;
		}
	}
}

int main()
{

	int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
	int n = sizeof(arr) / sizeof(arr[0]);

	for (int i = 0; i < n; i++)
		std::cout << arr[i] << ' ';
	std::cout << std::endl;

	//bubbleSort(arr, n);

	//insertionSort(arr, n);

	//SelectionSort(arr, n);

	//QuickSort(arr, 0, n-1);

	//iterative_mergeSort(arr, n);

	//mergeSort(arr, 0, n - 1);

	//countSort(arr, n);

	//bucketSort(arr, n);

	//RadixSort(arr, n);

	//ShellSort(arr, n);

	for (int i = 0; i < n; i++)
		std::cout << arr[i] << ' ';
	std::cout << std::endl;


	return 0;
}


