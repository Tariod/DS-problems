#include "sortAlgorithm.h"
#include <iostream>
#include <iomanip>

sortAlgorithm::sortAlgorithm(int *array, int size) {
    sortAlgorithm::array = array;
    sortAlgorithm::size = size;
};

sortAlgorithm::~sortAlgorithm() {
    delete []sortAlgorithm::array;
};

void sortAlgorithm::swap(int &element1, int &element2) {
	int temp = element1;
	element1 = element2;
	element2 = temp;
};

int *sortAlgorithm::copyArray() {
	int *copy = new int[sortAlgorithm::size];
	for (int i = 0; i < sortAlgorithm::size; i++)
		copy[i] = sortAlgorithm::array[i];
	return copy;
}

int *sortAlgorithm::QuickSort(int begin, int end) {
    int *copy = copyArray();
    QuickSort(copy, begin, end);
    return copy;
};

void sortAlgorithm::QuickSort(int *arrayToSort, int begin, int end) {
    if (begin < end) {
		int partition = PartitionLomuto(arrayToSort, begin, end);
		QuickSort(arrayToSort, begin, partition - 1);
		QuickSort(arrayToSort, partition + 1, end);
	}
};

int sortAlgorithm::PartitionLomuto(int *arrayToSort, int begin, int end) {
	int lastElement = arrayToSort[end];
	int partition = begin - 1;
	for (int j = begin; j < end; j++)
		if (arrayToSort[j] >= lastElement)
			swap(arrayToSort[++partition], arrayToSort[j]);
	swap(arrayToSort[++partition], arrayToSort[end]);
	return partition;
};

int *sortAlgorithm::ShellSort() {
    int *copy = copyArray();
    ShellSort(copy, sortAlgorithm::size);
    return copy;
};

void sortAlgorithm::ShellSort(int *arrayToSort, int size) {
    int i,j,k;
    int temp;
    for(k = size / 2; k > 0; k /= 2)
        for(i = k; i < size; i++) {
            temp = arrayToSort[i];
            for(j = i; j >= k; j -= k) {
                if(temp > arrayToSort[j - k])
                    arrayToSort[j] = arrayToSort[j - k];
                else
                    break;
            }
            arrayToSort[j] = temp;
        }
};
