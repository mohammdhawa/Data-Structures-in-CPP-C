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
	void insert(int key) {
		Node* t = root;
		Node* p = nullptr;
		Node* r = nullptr;

		if (root == nullptr) {
			p = new Node;
			p->data = key;
			p->left = p->right = nullptr;
			root = p;
			return;
		}

		while (t != nullptr) {
			r = t;
			if (key < t->data)
				t = t->left;
			else if (key > t->data)
				t = t->right;
			else
				return;
		}

		p = new Node;
		p->data = key;
		p->left = p->right = nullptr;

		if (key < r->data)
			r->left = p;
		else
			r->right = p;
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

  
	return 0;
}
