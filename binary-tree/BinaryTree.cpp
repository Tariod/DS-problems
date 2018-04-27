#include "BinaryTree.h"
#include <iostream>
#include <iomanip>


BinaryTree::BinaryTree(int value) {
	Node* newRoot = new Node(value);
	root = newRoot;
};

BinaryTree::~BinaryTree() {
	destroyTree(root);
};

void BinaryTree::insert(int value) {
	Node* temp = root;
	bool position = false;
	while (!position) {
		if (value == temp->data) break;
		if (value < temp->data) {
			if (!temp->left) {
				Node* leaf = new Node(value);
				leaf->parent = temp;
				temp->left = leaf;
				position = true;
			}
			temp = temp->left;
		} else {
			if (!temp->right) {
				Node* leaf = new Node(value);
				leaf->parent = temp;
				temp->right = leaf;
				position = true;
			}
			temp = temp->right;
		}
	}
};

void BinaryTree::remove(int value) {
	Node *toRemove = find(value);
	if(toRemove) remove(toRemove);
};

void BinaryTree::findAddRemove(int value) {
	Node* toRemove = find(value);

	if(!toRemove) {
		insert(value);
		toRemove = find(value);
	}

	remove(value);
}

void BinaryTree::printTree() {
	printTree(root, 0);
};

BinaryTree::Node *BinaryTree::find(int value) {
	Node* temp = root;
	while (true) {
		if (value == temp->data) return temp;

		if (value < temp->data) {
			if (!temp->left)
				return NULL;

			temp = temp->left;
		} else {
			if (!temp->right)
				return NULL;

			temp = temp->right;
		}
	}
}

void BinaryTree::remove(Node* root) {
//Root without children;
	if(!root->left && !root->right) {
		if(root->parent->left == root)
			root->parent->left = NULL;
		else
			root->parent->right = NULL;
		delete root; 
		return;
	}
//Root with one child;
	Node *temp;
	if(
		(!root->left && !!root->right) ||
    	(!!root->left && !root->right)
	) {
		temp = root->left ? root->left : root->right;
		temp->parent = root->parent;
		if(root->parent)
			if(root->parent->left == root)
				root->parent->left = temp;
			else
				root->parent->right = temp;
		else
			BinaryTree::root = temp;

		delete root; 
		return;
	}

	temp = findReplacement(root);

//Change child of the temp->parent;
	if(root->right != temp && root->left != temp)
		if(temp->parent->left == temp) {
			if(temp->right) {
				temp->right->parent = temp->parent;
				temp->parent->left = temp->right;
			} else
				temp->parent->left = NULL;
		} else {
			if(temp->left) {
				temp->left->parent = temp->parent;
				temp->parent->right = temp->left;
			} else
				temp->parent->right = NULL;
		}

//Change child of the root->parent on the temp;
	temp->parent = root->parent;
	if(root->parent)
		if(root->parent->left == root)
				root->parent->left = temp;
			else
				root->parent->right = temp;


//Change temp's children on the children of the root;
	if(root->left != temp) {
		temp->left = root->left;
		root->left->parent = temp;
	}
	if(root->right != temp) {
		temp->right = root->right;
		root->right->parent = temp;
	}

	if(root == BinaryTree::root)
		BinaryTree::root = temp;

	delete root;
};

BinaryTree::Node *BinaryTree::findReplacement(Node *root) {
	root = root->right;
	while(root->left)
		root = root->left;
	return root;
};

void BinaryTree::printTree(Node *temp, int indent) {
	if (temp != NULL) {
		if (temp->right) {
			printTree(temp->right, indent + 4);
		}
		if (indent) {
			std::cout << std::setw(indent) << ' ';
		}
		if (temp->right) std::cout << " /\n" << std::setw(indent) << ' ';
		std::cout << temp->data << "\n ";
		if (temp->left) {
			std::cout << std::setw(indent) << ' ' << " \\\n";
			printTree(temp->left, indent + 4);
		}
	}
};


void BinaryTree::destroyTree(Node *root) {
	if (root->left != NULL)
		destroyTree(root->left);
	if (root->right != NULL)
		destroyTree(root->right);
	delete root;
}
