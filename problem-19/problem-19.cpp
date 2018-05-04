#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

struct Person {
    string name;
    long int telephone;
};

Person *parseCSV(string fileName);

void QuickSort(Person *arrayToSort, int begin, int end);

int PartitionLomuto(Person *arrayToSort, int begin, int end);

void ShellSort(Person *arrayToSort, int size);

Person *copyDirecory(Person *direcory, int size);

void swap(int &element1, int &element2);

int size = 0;

int main() {
    string file;

    cout << "Enter a file name:" << endl;
	getline(cin, file);
    Person *directory = parseCSV(file);

    Person *Shell = copyDirecory(directory, size);
    ShellSort(Shell, size);

    cout << "Shell Sort:" << endl;
    for(int i = 0; i < size; i++)
        cout << Shell[i].telephone << " " << Shell[i].name << endl;

    Person *Quick = copyDirecory(directory, size);
    QuickSort(Quick, 0, size - 1);

    cout << "Quick Sort:" << endl;
    for(int i = 0; i < size; i++)
        cout << Quick[i].telephone << " " << Quick[i].name << endl;

    delete []directory;

    return 0;
}

Person *parseCSV(string fileName) {
	ifstream fromFile(fileName);

	if (fromFile.is_open()) {
		string cell, line;

		getline(fromFile, line);
		stringstream lineString(line);

		lineString >> size;

		Person *data = new Person[size];
		for (int i = 0; i < size; i++) {
			getline(fromFile, line);
			stringstream lineString(line);

			getline(lineString, cell, ',');
			data[i].name = cell;

			getline(lineString, cell);
            data[i].telephone = strtol(cell.c_str(), NULL, 10);
		}

		fromFile.close();
		return data;
	} else {
		cout << "No such file." << endl;
		return NULL;
	}
};

void QuickSort(Person *arrayToSort, int begin, int end) {
    if (begin < end) {
		int partition = PartitionLomuto(arrayToSort, begin, end);
		QuickSort(arrayToSort, begin, partition - 1);
		QuickSort(arrayToSort, partition + 1, end);
	}
};

int PartitionLomuto(Person *arrayToSort, int begin, int end) {
	long int lastElement = arrayToSort[end].telephone;
	int partition = begin - 1;
	for (int j = begin; j < end; j++)
		if (arrayToSort[j].telephone >= lastElement)
			swap(arrayToSort[++partition], arrayToSort[j]);
	swap(arrayToSort[++partition], arrayToSort[end]);
	return partition;
};

void ShellSort(Person *arrayToSort, int size) {
    int i,j,k;
    Person temp;
    for(k = size / 2; k > 0; k /= 2)
        for(i = k; i < size; i++) {
            temp = arrayToSort[i];
            for(j = i; j >= k; j -= k) {
                if(temp.telephone > arrayToSort[j - k].telephone)
                    arrayToSort[j] = arrayToSort[j - k];
                else
                    break;
            }
            arrayToSort[j] = temp;
        }
};

Person *copyDirecory(Person *directory, int size) {
	Person *copy = new Person[size];
	for (int i = 0; i < size; i++)
		copy[i] = directory[i];
	return copy;
}

void swap(int &element1, int &element2) {
	int temp = element1;
	element1 = element2;
	element2 = temp;
};
