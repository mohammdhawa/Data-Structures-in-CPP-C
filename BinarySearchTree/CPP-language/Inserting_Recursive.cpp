#include <iostream>

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
	Node* insert(Node* p, int key) {
		// if the tree is empty, return a new node
		if (p == nullptr) {
			Node* t = new Node;
			t->data = key;
			t->left = t->right = nullptr;
			return t;
		}

		// otherwise, down the tree
		if (key < p->data)
			p->left = insert(p->left, key);
		else if (key > p->data)
			p->right = insert(p->right, key);

		return p;
	}
	void insert(int key) {
		root = insert(root, key);
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

	
};

int main() {
	BinaryTree bst;
	
	bst.insert(30);
	bst.insert(20);
	bst.insert(25);
	bst.insert(10);
	bst.insert(40);
	bst.insert( 35);
	bst.insert(50);
  
	bst.inorder();

  
	return 0;
}
