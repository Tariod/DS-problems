#ifndef sortAlgorithmH
#define sortAlgorithmH
#include <iostream>

class sortAlgorithm {
public:
	sortAlgorithm(int *array, int size);

	~sortAlgorithm();

    void swap(int &element1, int &element2);

    int *copyArray();

    int *QuickSort(int begin, int end);

    int *ShellSort();

    int size;

    int *array;

private:
    void QuickSort(int *arrayToSort, int begin, int end);

    int PartitionLomuto(int *array, int begin, int end);

    void ShellSort(int *arrayToSort, int size);
};
#endif
