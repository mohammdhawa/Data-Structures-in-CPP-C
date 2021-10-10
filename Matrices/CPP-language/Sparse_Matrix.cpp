#include <iostream>

struct Element {
	int i;
	int j;
	int x;
};

class sparse {
	int m;
	int n; 
	int num;
	Element* e;
public:
	sparse(int m, int n, int num) {
		this->m = m;
		this->n = n;
		this->num = num;
		e = new Element[this->num];
	}
	~sparse() {
		delete[]e;
	}
	sparse operator+(sparse& s) {
		int i, j, k;
		if (m != s.m || n != s.n)
			return sparse(0, 0, 0);
		sparse* sum = new sparse(m, n, num + s.num);

		i = j = k = 0;
		while (i < num && j < s.num) {
			if (e[i].i < s.e[j].i)
				sum->e[k++] = e[i++];
			else if (e[i].i > s.e[j].i)
				sum->e[k++] = s.e[j++];
			else {
				if (e[i].j < s.e[j].j)
					sum->e[k++] = e[i++];
				else if (e[i].j > s.e[j].j)
					sum->e[k++] = s.e[j++];
				else {
					sum->e[k] = e[i];
					sum->e[k++].x = e[i++].x + s.e[j++].x;
				}
			}
		}

		for (; i < num; i++)
			sum->e[k++] = e[i];
		for (; j < s.num; j++)
			sum->e[k++] = s.e[j];
		sum->num = k;

		return *sum;
	}
	friend std::istream& operator >>(std::istream&, sparse&);
	friend std::ostream& operator <<(std::ostream&, sparse&);
};

std::istream& operator >>(std::istream& in, sparse& s) {
	std::cout << "Enter non-zero elemnts: ";
	for (int i = 0; i < s.num; i++)
		std::cin >> s.e[i].i >> s.e[i].j >> s.e[i].x;
	return in;
}

std::ostream& operator <<(std::ostream& op, sparse& s) {
	int k = 0; 
	for (int i = 0; i < s.m; i++) {
		for (int j = 0; j < s.n; j++) {
			if (s.e[k].i == i && s.e[k].j == j)
				std::cout << s.e[k++].x << ' ';
			else
				std::cout << "0 ";
		}
		std::cout << std::endl;
	}
	return op;
}

int main() {
	sparse s1(5, 5, 5);
	sparse s2(5, 5, 5);

	std::cin >> s1;
	std::cin >> s2;

	sparse sum = s1 + s2;

	std::cout << "First Matrix " << std::endl << s1;
	std::cout << "Second Matrix " << std::endl << s2;
	std::cout << "Sum Matrix " << std::endl << sum;

	
	

	return 0;
}
