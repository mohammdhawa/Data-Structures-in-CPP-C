#include <iostream>

class Diagonal {
	int n; 
	int* A;
public:
	Diagonal(int n) {
		this->n = n;
		A = new int[n];
	}
	~Diagonal() {
		delete[] A;
	}
	void set(int i, int j, int x) {
		if (i == j)
			A[i - 1] = x;
	}
	int get(int i, int j) {
		if (i == j)
			return A[i - 1];
		return 0;
	}
	void display() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j)
					std::cout << A[i] << ' ';
				else
					std::cout << "0 ";
			}
			std::cout << std::endl;
		}
	}
};

int main() {

	Diagonal di(4);

	di.set(1, 1, 3);
	di.set(2, 2, 5);
	di.set(3, 3, 7);
	di.set(4, 4, 9);

	di.display();

	std::cout << di.get(2, 2) << std::endl;
	

	return 0;
}
