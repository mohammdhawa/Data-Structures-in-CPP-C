int c(Node* p) {
		int x, y;
		if (p) {
			x = c(p->left);
			y = c(p->right);

			return x + y+1;
		}
		return 0;
	}
	// or
	int count(Node*p) {
		if (p == nullptr)
			return 0;
		return count(p->left) + count(p->right) + 1;
	}

/////////////////////////////////////////////////////////////////////

int height(Node* p) {
		int x, y;
		x = y = 0;

		if (p == nullptr)
			return 0;

		x = height(p->left);
		y = height(p->right);

		if (x > y)
			return x + 1;
		else
			return y + 1;
	}
