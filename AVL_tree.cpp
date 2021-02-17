#include<iostream>

const int SPACE = 5;

struct Node {
public:
	Node() : data(0) {}
	Node(int data) : data(data){}
	int data = 0;
	Node* left = nullptr;
	Node* right = nullptr;
};


class Tree {
public:
	Tree(Node* root): root(root){}
	Tree(){}
	~Tree() { del(root); }
private:
	Node* root = nullptr;

private:
	int height(Node* node) {
		if (!node) return 0;
		return 1 + std::max(height(node->left), height(node->right));
	}

	int getBalanceFactor(Node* node) {
		if (!node) return -1;
		return height(node->left) - height(node->right);
	}

	Node* rightRotate(Node* y) {
		Node* x = y->left;
		Node* T2 = x->right;
		x->right = y;
		y->left = T2;
		return x;
	}

	Node* leftRotate(Node* x) {
		Node* y = x->right;
		Node* T2 = y->left;
		y->left = x;
		x->right = T2;
		return y;
	}

	Node* getMin(Node* root) {
		Node* curr = root;
		while (curr->left) {
			curr = curr->left;
		}
		return curr;
	}

	Node* insert(Node* root, Node* newNode) {
		if (!root) {
			root = newNode;
			return root;
		}
		if (newNode->data < root->data) root->left = insert(root->left, newNode);
		else if (newNode->data > root->data) root->right = insert(root->right, newNode);
		else return root;
		int bf = getBalanceFactor(root);
		if (bf > 1 && newNode->data < root->left->data) return rightRotate(root);
		if (bf < -1 && newNode->data > root->right->data) return leftRotate(root);
		if (bf > 1 && newNode->data > root->left->data) {
			root->left = leftRotate(root->left);
			return rightRotate(root);
		}
		if (bf < -1 && newNode->data < root->right->data) {
			root->right = rightRotate(root->right);
			return leftRotate(root);
		}
		return root;
	}

	Node* deleteNode(Node* root, int data) {
		if (!root) return nullptr;
		else if (data < root->data) root->left = deleteNode(root->left, data);
		else if (data > root->data) root->right = deleteNode(root->right, data);
		else {
			if (!root->left) {
				Node* temp = root->right;
				delete root;
				return temp;
			}
			else if (!root->right) {
				Node* temp = root->left;
				delete root;
				return temp;
			}
			else {
				Node* temp = getMin(root->right);
				root->data = temp->data;
				root->right = deleteNode(root->right, temp->data);
			}
		}
		int bf = getBalanceFactor(root);
		if (bf == 2 && getBalanceFactor(root->left) >= 0) return rightRotate(root);
		else if (bf == 2 && getBalanceFactor(root->right) == -1) {
			root->left = leftRotate(root->left);
			return rightRotate(root);
		}
		else if (bf == -2 && getBalanceFactor(root->right) <= 0) {
			return leftRotate(root);
		}
		else if (bf == -2 && getBalanceFactor(root->right) == 1) {
			root->right = rightRotate(root->right);
			return leftRotate(root);
		}
		return root;
	}

	Node* search(Node* root, int data)const {
		if (!root || root->data == data) return root;
		if (data < root->data) search(root->left, data);
		else search(root->right, data);
	}

	void draw(Node* root, int space)const {
		if (!root) return;
		space += SPACE;
		draw(root->right, space);
		std::cout << "\n";
		for (int i = SPACE; i < space; ++i) {
			std::cout << " ";
		}
		std::cout << root->data << "\n";
		draw(root->left, space);
	}

	void del(Node* root) {
		if (root) {
			if (root->left) del(root->left);
			if (root->right) del(root->right);
			delete root;

		}
	}


public:
	bool isEmpty()const {
		return root == nullptr;
	}

	void insert(int data) {
		Node* newNode = new Node(data);
		root = insert(root, newNode);
	}

	void deleteNode(int data) {
		root = deleteNode(root, data);
	}

	Node* search(int data) const{
		return search(root, data);
	}

	void draw()const {
		int space = 5;
		draw(root, space);
	}
};

int main() {


	return 0;
}