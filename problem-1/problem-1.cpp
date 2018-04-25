#include <iostream>
#include <ctime>
#include "BinaryTree.h"
using namespace std;

int randNumber();

int main() {
    srand(time(NULL));
    BinaryTree *tree1 = new BinaryTree(randNumber());

    for(int i = 0; i < 14; i++)
        tree1->insert(randNumber());

	cout << "tree1" << endl;
	tree1->printTree();

    for(int i = -95; i < 99; i += 5)
        tree1->findAddRemove(i);

    cout << "tree1" << endl;
    tree1->printTree();
    return 0;
}

int randNumber() {
    return -99 + rand() % 199;
};