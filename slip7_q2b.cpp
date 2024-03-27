// Create a class Matrix and Write a C++ program to perform following functions:
// a. To accept a Matrix
// b. To display a Matrix
// c. Overload unary minus ‘–‘ operator to calculate transpose of a Matrix
// d. Overload binary multiplication '*’ operator to calculate multiplication of two matrices
#include <iostream>
using namespace std;

class Matrix {
    int row, col;
    int **matrix;

public:
    Matrix(int row, int col) {
        this->row = row;
        this->col = col;
        matrix = new int*[row];
        for(int i=0; i<row; i++) {
            matrix[i] = new int[col];
        }
    }

    void accept() {
        cout << "Enter elements of the matrix:\n";
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                cin >> matrix[i][j];
            }
        }
    }

    void display() {
        cout << "Matrix:\n";
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                cout << matrix[i][j] << "\t";
            }
            cout << endl;
        }
    }

    Matrix operator-() {
        Matrix traMatrix(col, row);
        for(int i=0; i<col; i++) {
            for(int j=0; j<row; j++) {
                traMatrix.matrix[i][j] = matrix[j][i];
            }
        }
        return traMatrix;
    }

    Matrix operator*(Matrix &m2) {
        if(col != m2.row) {
            cout << "Matrix multiplication not possible!\n";
            exit(0);
        }
        Matrix result(row, m2.col);
        for(int i=0; i<row; i++) {
            for(int j=0; j<m2.col; j++) {
                result.matrix[i][j] = 0;
                for(int k=0; k<col; k++) {
                    result.matrix[i][j] += matrix[i][k] * m2.matrix[k][j];
                }
            }
        }
        return result;
    }
};

int main() {
    int r1, c1, r2, c2;
    cout << "Enter the dimensions of the first matrix (row x col): ";
    cin >> r1 >> c1;
    Matrix m1(r1, c1);
    m1.accept();

    cout << "Enter the dimensions of the second matrix (row x col): ";
    cin >> r2 >> c2;
    Matrix m2(r2, c2);
    m2.accept();

    cout << "First ";
    m1.display();
    cout << "Second ";
    m2.display();

    Matrix m3 = -m1;
    cout << "Transpose of first ";
    m3.display();

    Matrix m4 = m1 * m2;
    cout << "Multiplication of first and second ";
    m4.display();
}
