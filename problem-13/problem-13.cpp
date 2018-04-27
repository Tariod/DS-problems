#include <iostream>
#include <string>
#include <ctime>
#include "../sort-agorithm/sortAlgorithm.h"
using namespace std;

int main() {
    srand(time(NULL));
    string value;
    int size;
    int *array;

    cout << "Enter the size of the array:" << endl;
	getline(cin, value);
    if(!value.empty())
	    size = stoi(value);
	else
        return 0;

    array = new int[size];
    for(int i = 0; i < size; i++) {
        array[i] = -99 + rand() % 199;
        cout << array[i] << " ";
    }
    std::cout << std::endl;

    sortAlgorithm *test = new sortAlgorithm(array, size);

    int *ShellSort = test->ShellSort();
    cout << "ShellSort:" << endl;
    for(int i = 0; i < size; i++)
        std::cout << ShellSort[i] << " ";
    std::cout << std::endl;

    int *QuickSort = test->QuickSort(0, size - 1);
    cout << "QuickSort:" << endl;
    for(int i = 0; i < size; i++)
        std::cout << QuickSort[i] << " ";
    std::cout << std::endl;

    delete test;
    delete []QuickSort;
    delete []ShellSort;

    return 0;
}
