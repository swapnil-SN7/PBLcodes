#include<iostream>
#include<vector>

using namespace std;

class Matrix {
private:
    vector<vector<int>> matrix;
    int rows, cols;

public:
    Matrix(int rows, int cols) { 
        this->rows=rows;
     this->cols=cols;
        matrix.resize(rows, vector<int>(cols));
    }

    

    void readMatrix() {
        cout << "Enter matrix elements:\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> matrix[i][j];
            }
        }
    }

    void addMatrix(Matrix& B) {
        if (rows != B.rows || cols != B.cols) {
            throw "Matrix dimensions are not compatible for addition.";
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] += B.matrix[i][j];
            }
        }
    }

    void subtractMatrix(Matrix& B) {
        if (rows != B.rows || cols != B.rows) {
            throw "Matrix dimensions are not compatible for subtraction.";
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] -= B.matrix[i][j];
            }
        }
    }

    Matrix multiplyMatrix(const Matrix& B) const {
    if (cols != B.rows) {
        throw "Matrix dimensions are not compatible for multiplication.";
    }

    Matrix result(rows, B.cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < B.cols; j++) {
            for (int k = 0; k < cols; k++) {
                result.matrix[i][j] += matrix[i][k] * B.matrix[k][j];
            }
        }
    }

    return result;
}


    void displayMatrix() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << "\n";
        }
    }
};

int main() {
    try {
             int r1,c1,r2,c2;

        cout<<"Enter the rows and cols for matrix1"<<endl;
        cin >> r1,c1;

        Matrix A(r1, c1);
        A.readMatrix();
        cout << "Matrix A:\n";
        A.displayMatrix();
        cout <<"Enter the rows and cols for the matrix2"<<endl;
        cin >> r2,c2;

        Matrix B(r2, c2);
        B.readMatrix();
        cout << "Matrix B:\n";
        B.displayMatrix();

        cout << "Addition of Matrices A and B:\n";
        A.addMatrix(B);
        A.displayMatrix();

        cout << "Subtraction of Matrices A and B:\n";
        A.subtractMatrix(B);
        A.displayMatrix();

       

        cout << "Multiplication of Matrices A and B:\n";
       Matrix result = A.multiplyMatrix(B);
        result.displayMatrix();
    }
    catch (const char* msg) {
        cerr << msg << "\n";
    }

    return 0;
}