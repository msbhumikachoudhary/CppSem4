// Write a C++ program to create a class which contains two dimensional integer array of size m*n
// Write a member function to display transpose of entered matrix.(Use Dynamic Constructor for
// allocating memory and Destructor to free memory of an object).
#include <iostream>
using namespace std;

class Matrix {
private:
    int** matrix;
    int m, n;

public:
    Matrix(int m, int n) {
        this->m = m;
        this->n = n;

        matrix = new int*[m];
        for (int i = 0; i < m; i++) {
            matrix[i] = new int[n];
        }
    }

    ~Matrix() {
        for (int i = 0; i < m; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }

    void input() {
        cout << "Enter the elements of the matrix:" << endl;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }
    }

    void display() {
        cout << "The original matrix is:" << endl;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void transpose() {
        cout << "The transpose of the matrix is:" << endl;
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m; i++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int m, n;

    cout << "Enter the number of rows and columns of the matrix: ";
    cin >> m >> n;

    Matrix mat(m, n);

    mat.input();
    mat.display();
    mat.transpose();

    return 0;
}
