#include <iostream>
#include <string>
#include <ctime>
#include "../binary-tree/BinaryTree.h"
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
		if("Q" == value || value.empty())
            break;
        counter++;
		tree->insert(stoi(value));
	}

    for(;counter < 14; counter++)
        tree->insert(randNumber());

	cout << "tree" << endl;
	tree->printTree();
    
    cout << "Remove composite numbers:" << endl;
    int compositeNumbers[] = {
        2, 3, 5, 7, 11,
        13, 17, 19, 23,
        29, 31, 37, 41,
        43, 47, 53, 59,
        61, 67, 71, 73,
        79, 83, 89, 97
    };
    for(int i = 0; i < 25; i++)
        tree->findAddRemove(compositeNumbers[i]);

    cout << "tree" << endl;
    tree->printTree();

    delete tree;
    return 0;
}

int randNumber() {
    return -99 + rand() % 199;
};