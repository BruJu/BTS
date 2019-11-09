#pragma once

#include <utility>
#include <stack>

template <typename T>
class NodeIterator;

template <typename T>
class Node {
private:
	T element;

	Node<T> * left{ nullptr };
	Node<T> * right{ nullptr };

public:
	T getElement() const {
		return element;
	}

	Node<T> * getLeft() const { return left; }
	Node<T> * getRight() const { return right; }

	Node(const T & element) : element(element) {
	}
	Node(const Node<T> & other) : element(other.element) {
		if (other.left) left = new Node<T>(other.left);
		else left = nullptr;

		if (other.right) right = new Node<T>(other.right);
		else right = nullptr;
	}

	Node(Node<T> && other) : element(other.element) {
		if (other.left) left = other.left;
		else left = nullptr;

		if (other.right) right = other.right;
		else right = nullptr;

		other.left = nullptr;
		other.right = nullptr;
	}

	Node<T> & operator=(const Node<T> & other) {
		delete left;
		delete right;
		if (other.left) left = new Node<T>(other.left);
		else left = nullptr;

		if (other.right) right = new Node<T>(other.right);
		else right = nullptr;

		return *this;
	}

	Node<T> & operator=(Node<T> && other) {
		delete left;
		delete right;
		if (other.left) left = other.left;
		else left = nullptr;

		if (other.right) right = other.right;
		else right = nullptr;

		other.left = nullptr;
		other.right = nullptr;

		return *this;
	}

	virtual ~Node() {
		delete left;
		delete right;
	}

	void insert(const T & element);
	/**
	  If remove returns a node, this node has to be deleted and replaced by
	  the returned node in the tree structure
	*/
	Node<T> * remove(const T & element);
	bool contains(const T & element) const;

	void print() {
		// TODO : exists only for BTS<int>
		printf("<");

		if (left != nullptr) {
			left->print();
		}
		printf("%d", element);
		if (right != nullptr) {
			right->print();
		}

		printf(">");
	}
};



template <typename T>
class BST {
private:
	Node<T> * root{nullptr};

public:
	BST() {}
	BST(const BST & other) {
		this->root = new Node<T>(other.root);
	}
	BST(BST && other) {
		this->root = other.root;
		other.root = nullptr;
	}
	virtual ~BST() {
		if (root != nullptr)
			delete root;
	}
	BST & operator=(const BST & other) {
		delete root;
		this->root = new Node<T>(other.root);

		return *this;
	}
	BST & operator=(BST && other) {
		delete root;
		this->root = other.root;
		other.root = nullptr;

		return *this;
	}
	
	void insert(const T & element);
	void remove(const T & element);
	bool contains(const T & element) const;


	class iterator {
	private:
		BST<T> * abr;
		std::stack<Node<T> *> exploredNodes{};

	public:
		iterator(BST<T> * abr) : abr(abr) {
			if (!abr)
				return;

			if (abr->root == nullptr) {
				abr = nullptr;
			} else {
				Node<T> * toInsert = abr->root;
				while (toInsert != nullptr) {
					exploredNodes.push(toInsert);
					toInsert = toInsert->getLeft();
				}
			}
		}

		iterator operator++() {
			if (exploredNodes.empty()) {
				abr = nullptr;
				return *this;
			}

			Node<T> * top = exploredNodes.top();
			exploredNodes.pop();

			top = top->getRight();

			while (top != nullptr) {
				exploredNodes.push(top);
				top = top->getLeft();
			}

			if (exploredNodes.empty()) {
				abr = nullptr;
				return *this;
			}
			return *this;
		}

		T operator*() const {
			return exploredNodes.top()->getElement();
		}

		bool operator!=(const BST<T>::iterator & it) {
			return abr != it.abr || exploredNodes != it.exploredNodes;
		}
	};

	iterator begin() {
		return iterator(this);
	}

	iterator end() {
		return iterator(nullptr);
	}

	void print() {
		if (root == nullptr) {
			printf("<Vide>");
		} else {
			root->print();
			printf("\n");
		}
	}
};

template <typename T>
void Node<T>::insert(const T & element) {
	if (this->element == element) {
		return;
	} else if (this->element > element) {
		if (this->left) {
			this->left->insert(element);
		} else {
			this->left = new Node<T>(element);
		}
	} else {
		if (this->right) {
			this->right->insert(element);
		} else {
			this->right = new Node<T>(element);
		}
	}
}


template <typename T>
Node<T> * Node<T>::remove(const T & element) {
	if (this->element > element) {
		if (!this->left)
			return nullptr;

		Node<T> * newSon = this->left->remove(element);
		if (newSon) {
			delete this->left;
			this->left = newSon;
		}

		return newSon;
	} else if (this->element < element) {
		if (!this->right)
			return nullptr;

		Node<T> * newSon = this->right->remove(element);
		if (newSon) {
			delete this->right;
			this->right = newSon;
		}

		return newSon;
	} else {
		if (this->left == nullptr) {
			Node<T> * returnValue = this->right;
			this->right = nullptr;
			return returnValue;
		} else if (this->right == nullptr) {
			Node<T> * returnValue = this->left;
			this->left = nullptr;
			return returnValue;
		} else {

			this->element = stealMax();
			// TODO

			std::swap(this->element, this->left->element);

			Node<T> * newSon = this->left->remove(element);
			if (newSon) {
				delete this->left;
				this->left = newSon;
			}

			return nullptr;
		}
	}
}


template <typename T>
bool Node<T>::contains(const T & element) const {
	if (this->element == element) {
		return true;
	} else if (this->element > element) {
		return this->left && this->left->contains(element);
	} else {
		return this->right && this->right->contains(element);
	}
}


template <typename T>
void BST<T>::insert(const T & element) {
	if (this->root) {
		this->root->insert(element);
	} else {
		this->root = new Node<T>(element);
	}
}

template <typename T>
void BST<T>::remove(const T & element) {
	if (this->root) {
		Node<T> * newRoot = this->root->remove(element);
		if (newRoot) {
			delete root;
			root = newRoot;
		}
	}
}

template <typename T>
bool BST<T>::contains(const T & element) const {
	return root && root->contains(element);
}

int main();
