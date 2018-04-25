#include <iostream>
#include <string>
#include <ctime>
#include "BinaryTree.h"
using namespace std;

int randNumber();

int main() {
    srand(time(NULL));
    BinaryTree *tree;
    int counter = 0;
    string value;
    cout << "Enter the value of the root:" << endl;
	getline(cin, value);
    if(!value.empty())
        tree = new BinaryTree(stoi(value));
    else
        tree = new BinaryTree(randNumber());
    counter++;

    while (true) {
		cout << "Q to stop" << endl;
		getline(cin, value);
		if("q" == value || value.empty())
            break;
        counter++;
		tree->insert(stoi(value));
	}

    for(;counter < 14; counter++)
        tree->insert(randNumber());

	cout << "tree" << endl;
	tree->printTree();

    for(int i = -95; i < 99; i += 5)
        tree->findAddRemove(i);

    cout << "tree" << endl;
    tree->printTree();

    delete tree;
    return 0;
}

int randNumber() {
    return -99 + rand() % 199;
};