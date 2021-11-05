// Recursive Traversals
void preOrder(Node* p) {
		if (p) {
			std::cout << p->data << " ";
			preOrder(p->left);
			preOrder(p->right);
		}
	}

void inOrder(Node* p) {
		if (p) {
			inOrder(p->left);
			std::cout << p->data << " ";
			inOrder(p->right);
		}
	}

void postOrder(Node* p) {
		if (p) {
			postOrder(p->left);
			postOrder(p->right);
			std::cout << p->data << " ";
		}
	}


// Iterative Traversals
void Preorder(Node* p) {
		std::stack<Node*>st;

		while (p != nullptr || !st.empty()) {
			if (p != nullptr) {
				std::cout << p->data << ' ';
				st.push(p);
				p = p->left;
			}
			else {
				p = st.top();
				st.pop();
				p = p->right;
			}
		}
	}

void Inorder(Node* p) {
		std::stack<Node*>st;

		while (p != nullptr || !st.empty()) {
			if (p != nullptr) {
				st.push(p);
				p = p->left;
			}
			else {
				p = st.top();
				st.pop();
				std::cout << p->data << ' ';
				p = p->right;
			}
		}
	}

void Postorder(Node* p) {
		std::stack<long int>st;
		long int temp;

		while (p != nullptr || !st.empty()) {
			if (p != nullptr) {
				st.emplace((long int)p);
				p = p->left;
			}
			else {
				temp = st.top();
				st.pop();
				if (temp > 0) {
					st.emplace(-temp);
					p = ((Node*)temp)->right;
				}
				else {
					std::cout << ((Node*)(-1 * temp))->data << " ";
					p = nullptr;
				}
			}
		}
	}

