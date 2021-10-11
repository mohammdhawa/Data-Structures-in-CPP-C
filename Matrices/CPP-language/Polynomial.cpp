#include <iostream>

struct Term {
	int coef;
	int exp;
};

class poly {
	int n;
	Term* terms;
public:
	void create() {
		std::cout << "Number of terms: ";
		std::cin >> n;

		terms = new Term[n];

		std::cout << "Enter terms\n";
		for (int i = 0; i < n; i++)
			std::cin >> terms[i].coef >> terms[i].exp;
	}
	poly* operator +(poly p) {
		poly* sum = new poly;
		sum->terms = new Term[n + p.n];

		int i, j, k;
		i = j = k = 0;
		while (i < n && j < p.n) {
			if (terms[i].exp > p.terms[j].exp)
				sum->terms[k++] = terms[i++];
			else if (p.terms[j].exp > terms[i].exp)
				sum->terms[k++] = p.terms[j++];
			else {
				sum->terms[k].exp = terms[i].exp;
				sum->terms[k++].coef = terms[i++].coef + p.terms[j++].coef;
			}
		}
		for (; i < n; i++)
			sum->terms[k++] = terms[i];
		for (; j < p.n; j++)
			sum->terms[k++] = terms[j];
		sum->n = k;

		return sum;
	}
	void display() {
		for (int i = 0; i < n; i++)
			std::cout << " " << terms[i].coef << 'x' <<  terms[i].exp;
	}
};

int main() {
	poly p1, p2, * p3;

	p1.create();
	p2.create();

	p3 = p1 + p2;

	p1.display();
	std::cout << std::endl;
	p2.display();
	std::cout << std::endl;
	p3->display();
	std::cout << std::endl;
}
