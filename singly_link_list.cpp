#include<iostream>

struct Node {
public:
	Node() : key(0), data(0) {}
	Node(int key, int data) : key(key), data(data) {}

public:
	int key;
	int data;
	Node* next = nullptr;
};

struct Linked_List {
public:
	Linked_List() : head(nullptr) {}
	Linked_List(Node* ptr) : head(ptr) {}
	~Linked_List() {
		Node* tmp = head;
		while (head) {
			tmp = head;
			head = head->next;
			delete tmp;
		}
	}

public:
	Node* head;

public:
	Node* ifExist(int _key) const {
		Node* ptr = head;
		while (ptr) {
			if (ptr->key == _key)
				return ptr;
			ptr = ptr->next;
		}
		return nullptr;
	}
	void append(Node* node) {
		if (ifExist(node->key))
			std::cerr << "\nCannot append. There is a key duplication.";
		else {
			if (head == nullptr)
				head = node;
			else
			{
				Node* ptr = head;
				while (ptr->next)
					ptr = ptr->next;
				ptr->next = node;
			}
		}
	}

	void prepend(Node* node) {
		if (ifExist(node->key))
			std::cerr << "\nCannot prepend. There is a key duplication.";
		else {
			node->next = head;
			head = node;
		}
	}

	void insert(int prevKey, Node* node) {
		Node* temp = ifExist(prevKey);
		if (!temp)
			std::cerr << "\nCannot insert. There is a key duplication";
		else {
			if (ifExist(node->key))
				std::cerr << "\nCannot insert. There is a key duplication";
			else {
				node->next = temp->next;
				temp->next = node;
			}
		}
	}

	void deleteNode(int _key) {
		if (!head)
			std::cout << "\nList is empty. Cannot delete.";
		else {
			if (head->key == _key)
				head = head->next;
			else {
				Node* temp = nullptr;
				Node* prev = head;
				Node* curr = head->next;
				while (curr) {
					if (curr->key == _key) {
						temp = curr;
						curr = nullptr;
						break;
					}

					prev = prev->next;
					curr = curr->next;

				}
				if (temp) {
					prev->next = temp->next;
					delete temp;
				}
				else
					std::cerr << "\nNo element found";
			}
		}
	}

	void updateNode(int _key, int newData) {
		Node* temp = ifExist(_key);
		if (temp)
			temp->data = newData;
		else std::cerr << "\nCannot find this node";
	}

	void print()const {
		if (head) {
			Node* temp = head;
			while (temp) {
				std::cout << " (" << temp->key << ", " << temp->data << ") ";
				temp = temp->next;
			}
		}
	}
};




int main() {


	return 0;
}
