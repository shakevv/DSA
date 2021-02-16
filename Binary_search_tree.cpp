#include<iostream>


const int SPACE = 5;

struct TreeNode {
public:
	TreeNode() : data(0) {}
	TreeNode(int _data) : data(_data) {}

public:
	int data;
	TreeNode* left = nullptr;
	TreeNode* right = nullptr;

};

class BST {
public:
	BST() {}
	~BST() { del(root); }
private:
	TreeNode* root = nullptr;

private:
	void del(TreeNode* root) {
		if (root) {
			if (root->left) del(root->left);
			if (root->right) del(root->right);
			delete root;

		}
	}

	TreeNode* insert(TreeNode* node, int _data) {
		if (!node) return new TreeNode(_data);
		if (_data <= node->data) node->left = insert(node->left, _data);
		else node->right = insert(node->right, _data);
		return node;
	}

	void print(TreeNode* root)const {
		if (!root) return;
		print(root->left);
		std::cout << root->data << " ";
		print(root->right);
	}

	int height(TreeNode* node)const
	{
		if (!node) return 0;
		return 1 + std::max(height(node->left), height(node->right));
	}

	TreeNode* deleteNode(TreeNode* root, int data) {
		if (!root) return nullptr;
		else if (root->data > data) root->left = deleteNode(root->left, data);
		else if (root->data < data) root->right = deleteNode(root->right, data);
		else {
			if (!root->left) {
				TreeNode* temp = root->right;
				delete root;
				return temp;
			}
			else if (!root->right) {
				TreeNode* temp = root->left;
				delete root;
				return temp;
			}
			else {
				TreeNode* temp = minNode(root->right);
				root->data = temp->data;
				root->right = deleteNode(root->right, temp->data);
			}
		}
		return root;
	}

	TreeNode* minNode(TreeNode* root) {
		if (!root->left) return root;
		return minNode(root->left);
	}

	void draw(TreeNode* root, int space)const {
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

	void printLevel(TreeNode* root, int lvl) const {
		if (!root) return;
		if (lvl == 0) std::cout << root->data << " ";
		else {
			printLevel(root->left, lvl - 1);
			printLevel(root->right, lvl - 1);
		}
	}

	void BFS(TreeNode* root)const {
		int h = height();
		for (int i = 0; i < h; ++i)
			printLevel(root, i);
	}

	TreeNode* search(TreeNode* root, int _data)const {
		if (!root || root->data == _data) return root;
		if (_data < root->data) search(root->left, _data);
		else search(root->right, _data);
	}

	void preorder(TreeNode* root) {
		if (!root) return;
		std::cout << root->data << " ";
		preorder(root->left);
		preorder(root->right);
	}

public:
	bool isEmpty()const {
		return root == nullptr;
	}

	int height()const {
		return height(root);
	}

	void insert(int data) {
		root = insert(root, data);
	}

	void print()const {
		print(root);
	}

	void minNode() {
		TreeNode* node = minNode(root);
		std::cout << node->data;
	}

	void deleteNode(int data) {
		deleteNode(root, data);
	}

	void draw()const {
		draw(root, 5);
	}

	void BFS_Level_print()const {
		BFS(root);
	}

	void preorder_print() {
		preorder(root);
	}

	TreeNode* search(int data)const {
		return search(root, data);
	}
};

int main() {
	
	return 0;
}