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
  
  int Height(Node* p) {
		int x, y;
		if (p == nullptr)
			return 0;
		x = Height(p->left);
		y = Height(p->right);

		if (x > y)
			return x + 1;
		else
			return y + 1;
	}
	int Height() { return Height(root); }
	Node* inPre(Node* p) {
		while (p && p->right != nullptr)
			p = p->right;
		return p;
	}
	Node* inSuc(Node* p) {
		while (p && p->left!=nullptr)
			p = p->left;
		return p;
	}
  Node* Delete(Node* p, int key) {
		Node* q;

		if (p == nullptr)
			return nullptr;

		if (p->left == nullptr && p->right == nullptr) {
			if (p == root)
				root = nullptr;
			delete p;
			return nullptr;
		}

		if (key < p->data)
			p->left = Delete(p->left, key);
		else if (key > p->data)
			p->right = Delete(p->right, key);
		else {
			if (Height(p->left) > Height(p->right)) {
				q = inPre(p->left);
				p->data = q->data;
				p->left = Delete(p->left, q->data);
			}
			else {
				q = inSuc(p->right);
				p->data = q->data;
				p->right = Delete(p->right, q->data);
			}
		}
		return p;
	}

	
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
  
  bst.Delete(bst.getRoot(), 40);

	bst.inorder();

  
	return 0;
}
