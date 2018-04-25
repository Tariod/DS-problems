#ifndef BinaryTreeH
#define BinaryTreeH
#include <iostream>

class BinaryTree {
public:
	BinaryTree(int value);

	~BinaryTree();

	void insert(int value);

	void remove(int value);

	void findAddRemove(int value);

	void printTree();

private:
	struct Node {
		Node(int value) {
			data = value;
			parent = NULL;
			left = NULL;
			right = NULL;
		};

		int data;
		Node *left;
		Node *right;
		Node *parent;
	};

	Node *root;

	Node *find(int value);

	void remove(Node *root);

	Node *findReplacement(Node *root);

	void printTree(Node *temp, int indent);

	void destroyTree(Node *root);
};
#endif
