#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int side = 0;
int isOriented = 0;

int **parseFile(string fileName);
int **matrixMultiplication(int **arr1, int **arr2, int side);
int **transitiveClosure(int **array, int side);
int **FloydWarshall(int **array, int side);

int main() {
    string file;

    cout << "Enter a file name:" << endl;
	getline(cin, file);
    int **array = parseFile(file);

    cout << "Adjacency matrix:" << endl;
    for(int i = 0; i < side; i++) {
        for(int j = 0; j < side; j++)
            cout << array[i][j] << " ";
        cout << endl;
    };

    cout << "Transitive Closure:" << endl;
    int **res1 = transitiveClosure(array, side);
    for(int i = 0; i < side; i++) {
        for(int j = 0; j < side; j++)
            cout << res1[i][j] << " ";
        cout << endl;
    };
    if(isOriented) {
        cout << "Floyd Warshall:" << endl;
        int **res2 = FloydWarshall(array, side);
        for(int i = 0; i < side; i++) {
            for(int j = 0; j < side; j++)
                cout << res2[i][j] << " ";
            cout << endl;
        };

        for(int row = 0; row < side; row++)
            delete []res2[row];
        delete []res2;
    }

    for(int row = 0; row < side; row++)
        delete []array[row];
    delete []array;

    for(int row = 0; row < side; row++)
        delete []res1[row];
    delete []res1;

    return 0;
};

int **parseFile(string fileName) {
	ifstream fromFile(fileName);

	if (fromFile.is_open()) {
		fromFile >> side;
        fromFile >> isOriented;

        int **data = new int *[side];
        for(int i = 0; i < side; i++) {
            data[i] = new int[side];
            for(int j = 0; j < side; j++)
                fromFile >> data[i][j];
        }

		fromFile.close();
		return data;
	} else {
		cout << "No such file." << endl;
		return NULL;
	}
};

int **matrixMultiplication(int **arr1, int **arr2, int side) {
  int** result = new int *[side];
  for(int row = 0; row < side; ++row) {
    result[row] = new int[side];
    for (int column = 0; column < side; column++) {
      result[row][column] = 0;
      for (int i = 0; i < side; i++)
        result[row][column] += arr1[row][i] * arr2[i][column];
    }
  }
  return result;
};

int **transitiveClosure(int **array, int side) {
    int** result = new int *[side];
    int** temp = new int *[side];
    for(int row = 0; row < side; row++) {
        result[row] = new int[side];
        temp[row] = new int[side];
        for(int column = 0; column < side; column++)
            result[row][column] = temp[row][column] = array[row][column];
    }

    for(int i = 1; i < side; i++) {
        temp = matrixMultiplication(array, temp, side);
        for(int row = 0; row < side; ++row)
            for (int column = 0; column < side; column++)
                result[row][column] = result[row][column] || temp[row][column];
    }

    for(int row = 0; row < side; row++)
        delete []temp[row];
    delete []temp;

    return result;
};

int **FloydWarshall(int **array, int side) {
    int** result = new int *[side];
    for(int row = 0; row < side; row++) {
        result[row] = new int[side];
        for(int column = 0; column < side; column++)
            result[row][column] = array[row][column];
    }

    for(int k = 0; k < side; k++)
        for(int i = 0; i < side; i++)
            for(int j = 0; j < side; j++)
                result[i][j] = result[i][j] || (result[i][k] && result[k][j]);

    return result;
};