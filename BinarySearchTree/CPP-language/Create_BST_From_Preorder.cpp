#include <iostream>
#include <stack>

struct Node {
	Node* left;
	int data;
	Node* right;
};

class BinaryTree {
	Node* root;
public:
	BinaryTree() {
		root = nullptr;
	}
	void inorder(Node* p) {
		if (p) {
			inorder(p->left);
			std::cout << p->data << ' ';
			inorder(p->right);
		}
	}
	void inorder() { inorder(root); std::cout << std::endl; }

	Node* getRoot() { return root; }

	void create(int pre[], int n) {
		std::stack<Node*>st;
		int i = 0;

		root = new Node;
		root->data = pre[i++];
		root->left = root->right = nullptr;
		Node* t = nullptr;
		Node* p = root;

		while (i < n) {
			if (pre[i] < p->data) {
				t = new Node;
				t->data = pre[i++];
				t->left = t->right = nullptr;
				p->left = t;
				st.push(p);
				p = t;
			}
			else {
				if (pre[i] > p->data && pre[i] < st.empty() ? 32767 : st.top()->data) {
					t = new Node;
					t->data = pre[i++];
					t->left = t->right = nullptr;
					p->right = t;
					p = t;
				}
				else {
					p = st.top();
					st.pop();
				}
			}
		}
	}
};

int main() {
	BinaryTree bst;
	
	int pre[8] = { 30, 20, 10, 15, 25, 40, 50, 45 };
	bst.create(pre, 8);
  
	bst.inorder();

  
	return 0;
}
