#include <iostream>
#include <ctime>
#include "../sort-agorithm/sortAlgorithm.h"

int main() {
    srand(time(NULL));
	int size = 15;
	int *array = new int[size];
    for(int i = 0; i < size; i++)
        array[i] = -99 + rand() % 199;
    for(int i = 0; i < size; i++)
        std::cout << array[i] << " ";
    std::cout << std::endl;
    sortAlgorithm test = sortAlgorithm(array, size);
    int *arr = test.QuickSort(0, size - 1);
    for(int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}
