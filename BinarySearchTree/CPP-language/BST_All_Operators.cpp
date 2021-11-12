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
	/*
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
	*/
	void inorder(Node* p) {
		if (p) {
			inorder(p->left);
			std::cout << p->data << ' ';
			inorder(p->right);
		}
	}
	void inorder() { inorder(root); std::cout << std::endl; }

	Node* search(Node* p, int key) {
		if (p == nullptr)
			return nullptr;

		if (key == p->data)
			return p;
		else if (key < p->data)
			return search(p->left, key);
		else
			return search(p->right, key);
	}
	void search(int key) {
		Node* t = search(root, key);
		if (t)
			std::cout << t->data << " found in tree" << std::endl;
		else
			std::cout << key << " not found in tree" << std::endl;
	}
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
};



int main() {
	BinaryTree bst;
	
	/*
	bst.insert(30);
	bst.insert(20);
	bst.insert(25);
	bst.insert(10);
	bst.insert(40);
	bst.insert( 35);
	bst.insert(50);
	*/

	int pre[8] = { 30, 20, 10, 15, 25, 40, 50, 45 };
	bst.create(pre, 8);
	bst.inorder();

	bst.search(20);

	bst.Delete(bst.getRoot(), 40);

	bst.inorder();


	return 0;
}
