#include <iostream>
#include <queue>
#include <stack>

struct Node {
	Node* left;
	int data;
	Node* right;
	Node() {
		data = 0;
		right = nullptr;
		left = nullptr;
	}
};

template <class T>
class Queue {
	int front;
	int rear;
	int size;
	T* Q;
public:
	Queue() {
		front = rear = -1;
		size = 10;
		Q = new T[size];
	}
	Queue(int size) {
		front = rear = -1;
		this->size = size;
		Q = new T[this->size];
	}
	bool isEmpty() {
		return front == rear;
	}
	void enQueue(T x) {
		if (rear == size-1) {
			std::cout << "Queue is full";
			return;
		}
		rear++;
		Q[rear] = x;
	}
	T deQueue() {
		T x = NULL;
		if (front == rear)
			std::cout << "Queue is empty" << std::endl;
		else {
			x = Q[front + 1];
			front++;
		}
		return x;
	}
	void display() {
		for (int i = front + 1; i <= rear; i++)
			std::cout << Q[i] << ' ';
		std::cout << std::endl;
	}
};

class binaryTree {
	Node* root;
public:
	binaryTree() {
		root = nullptr;
	}
	~binaryTree() {
		destroyRecursive(root);
	}
	void create() {
		Node* p;
		Node* t;
		int x;
		Queue<Node*>q;

		std::cout << "Enter root value: ";
		std::cin >> x;
		
		root = new Node;
		root->data = x;
		q.enQueue(root);

		while (!q.isEmpty()) {
			p = q.deQueue();

			std::cout << "Enter left child of " << p->data << ": ";
			std::cin >> x;
			if (x != -1) {
				t = new Node;
				t->data = x;
				p->left = t;
				q.enQueue(t);
			}

			std::cout << "Enter right child of " << p->data << ": ";
			std::cin >> x;
			if (x != -1) {
				t = new Node;
				t->data = x;
				p->right = t;
				q.enQueue(t);
			}
		}
	}
	void destroyRecursive(Node* p) {
		if (p) {
			destroyRecursive(p->left);
			destroyRecursive(p->right);
			delete p;
		}
	}
	void preOrder(Node* p) {
		if (p) {
			std::cout << p->data << " ";
			preOrder(p->left);
			preOrder(p->right);
		}
	}
	void preOrder() {
		preOrder(root);
		std::cout << std::endl;
	}
	void postOrder(Node* p) {
		if (p) {
			postOrder(p->left);
			postOrder(p->right);
			std::cout << p->data << " ";
		}
	}
	void postOrder() {
		postOrder(root);
		std::cout << std::endl;
	}
	void inOrder(Node* p) {
		if (p) {
			inOrder(p->left);
			std::cout << p->data << " ";
			inOrder(p->right);
		}
	}
	void inOrder() {
		inOrder(root);
		std::cout << std::endl;
	}
	int count(Node* p) {
		if (p)
			return count(p->left) + count(p->right) + 1;
		else
			return 0;
	}
	int count() {
		return count(root);
	}
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
	int height() {
		return height(root);
	}

	/////////////// Iteration Taraversals /////////////////////
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
	void Preorder() {
		Preorder(root);
		std::cout << std::endl;
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
	void Inorder() {
		Inorder(root);
		std::cout << std::endl;
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
	void Postorder() {
		Postorder(root);
		std::cout << std::endl;
	}
	int c(Node* p) {
		int x, y;
		if (p) {
			x = c(p->left);
			y = c(p->right);

			return x + y+1;
		}
		return 0;
	}
	int c() { return c(root); }
	int countLeaves(Node* p) {
		int x, y;

		if (p) {
			x = countLeaves(p->left);
			y = countLeaves(p->right);

			if (p->left == nullptr && p->right == nullptr)
				return x + y + 1;
			else
				return x + y;
		}
		return 0;
	}
	int countLeaves() { return countLeaves(root); }
	int countNodesWithDegree2(Node* p) {	// which have two children
		int x, y;
		
		if (p) {
			x = countNodesWithDegree2(p->left);
			y = countNodesWithDegree2(p->right);

			if (p->left != nullptr && p->right != nullptr)
				return x + y + 1;
			else
				return x + y;
		}

		return 0;
	}
	int countNodesWithDegree2() { return countNodesWithDegree2(root); }

	int countNodesWithDegree1(Node* p) {	// node which has only one child
		if (p == nullptr)
			return 0;

		if ((p->left != nullptr && p->right == nullptr) || (p->left == nullptr && p->right != nullptr))
			return countNodesWithDegree1(p->left) + countNodesWithDegree1(p->right) + 1;
		else
			return countNodesWithDegree1(p->left) + countNodesWithDegree1(p->right);
	}
	int countNodesWithDegree1() { return countNodesWithDegree1(root); }
	
	int countNodesDegreeNotZero(Node* p) {	// which have one or two child
		int x, y;

		if (p) {
			x = countNodesDegreeNotZero(p->left);
			y = countNodesDegreeNotZero(p->right);

			if (p->left != nullptr || p->right != nullptr)
				return x + y + 1;
			else
				return x + y;
		}

		return 0;
	}
	int countNodesDegreeNotZero() { return countNodesDegreeNotZero(root); }
};

int main() {
	binaryTree bt;
	bt.create();

	bt.preOrder();
	bt.Preorder();
	std::cout << std::endl;

	bt.inOrder();
	bt.Inorder();
	std::cout << std::endl;

	bt.postOrder();
	bt.postOrder();
	std::cout << std::endl;

	std::cout << "Number of nodes: " << bt.count() << std::endl;
	std::cout << "number of nodes: " << bt.c() << std::endl;

	std::cout << "Height of tree: " << bt.height() << std::endl;

	std::cout << "Number of leaves in the tree: " << bt.countLeaves() << std::endl;
	std::cout << "Number of Nodes which has one or two child: " << bt.countNodesDegreeNotZero() << std::endl;
	std::cout << "Number of nodes which has one child: " << bt.countNodesWithDegree1() << std::endl;
	
	
	return 0;
	
}
