void createTree() {
	Node* p;
	Node* t;
	int x;
	Queue q(10);

	std::cout << "Enter root value: ";
	std::cin >> x;
	root->data = x;
	root->left = root->right = nullptr;
	q.enQueue(root);

	while (!q.isEmpty()) {
		p = q.deQueue();

		std::cout << "Enter left child of " << p->data << ": ";
		std::cin >> x;
		if (x != -1) {
			t = new Node;
			t->data = x;
			t->left = t->right = nullptr;
			p->left = t;
			q.enQueue(t);
		}

		std::cout << "Enter right child of " << p->data << ": ";
		std::cin >> x;
		if (x != -1) {
			t = new Node;
			t->data = x;
			t->left = t->right = nullptr;
			p->left = t;
			q.enQueue(t);
		}
	}
}
