#include <iostream>
using namespace std;

// Structure to represent a sparse matrix
struct SparseMatrix {
    int row;
    int col;
    int value;
};

// Function to perform simple transpose of a sparse matrix
void simpleTranspose(SparseMatrix sparse[], int size) {
    SparseMatrix transposed[size];
    
    // Copy the first element (metadata)
    transposed[0].row = sparse[0].col;
    transposed[0].col = sparse[0].row;
    transposed[0].value = sparse[0].value;

    // Transpose remaining elements
    int k = 1; // Index for the transposed matrix
    for (int i = 0; i < sparse[0].col; i++) {
        for (int j = 1; j <= sparse[0].value; j++) {
            if (sparse[j].col == i) {
                transposed[k].row = sparse[j].col;
                transposed[k].col = sparse[j].row;
                transposed[k].value = sparse[j].value;
                k++;
            }
        }
    }

    // Output the transposed matrix
    cout << "Transposed Sparse Matrix:\n";
    for (int i = 1; i <= transposed[0].value; i++) {
        cout << transposed[i].row << " " << transposed[i].col << " " << transposed[i].value << endl;
    }
}

int main() {
    int rows, cols, nonZero;
    cout << "Enter the number of rows, columns, and non-zero elements in the sparse matrix:\n";
    cin >> rows >> cols >> nonZero;

    SparseMatrix sparse[nonZero + 1];
    sparse[0] = {rows, cols, nonZero};

    cout << "Enter the non-zero elements (row, column, value):\n";
    for (int i = 1; i <= nonZero; i++) {
        cin >> sparse[i].row >> sparse[i].col >> sparse[i].value;
    }

    cout << "Original Sparse Matrix:\n";
    for (int i = 1; i <= nonZero; i++) {
        cout << sparse[i].row << " " << sparse[i].col << " " << sparse[i].value << endl;
    }

    // Perform transpose
    simpleTranspose(sparse, nonZero + 1);

    return 0;
}
