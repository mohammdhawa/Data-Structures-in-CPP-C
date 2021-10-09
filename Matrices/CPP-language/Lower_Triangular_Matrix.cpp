#include <iostream>

class lowerTriangularMatrix {
	int n; 
	int* A;
public:
	lowerTriangularMatrix(int n) {
		this->n = n;
		A = new int[n*(n+1)/2];
	}
	~lowerTriangularMatrix() {
		delete[]A;
	}
	void set_row_major(int i, int j, int x) {
		if (i >= j)
			A[((i * (i - 1) / 2)) + j - 1] = x;
	}
	void set_column_major(int i, int j, int x) {
		if (i >= j) {
			A[(n * (j - 1) - (((j - 2) * (j - 1)) / 2)) + (i - j)] = x;
		}
	}
	int get_row_major(int i, int j) {
		if (i >= j)
			return A[((i * (i - 1) / 2)) + j - 1];
		return 0;
	}
	int get_column_major(int i, int j) {
		if (i >= j)
			return A[(n * (j - 1) - (((j - 2) * (j - 1)) / 2)) + (i - j)];
		return 0;
	}
	void display() const {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i >= j)
					std::cout << A[((i * (i - 1) / 2)) + j - 1] << ' ';
				else
					std::cout << "0 ";
			}
			std::cout << std::endl;
		}
	}
};

int main() {
	int n, x;
	std::cout << "Enter Dimension: ";
	std::cin >> n;

	lowerTriangularMatrix ltm(n);

	std::cout << "Enter all elements: ";
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			std::cin >> x;
			ltm.set_column_major(i, j, x);
		}
	}

	std::cout << "\n\n";

	ltm.display();

	
	

	return 0;
}
