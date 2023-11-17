#include <iostream>
#include <vector>

using namespace std;

class Matrix {
private:
    vector<vector<int>> matrix;
    int rows, cols;

public:
    Matrix(int rows, int cols) : rows(rows), cols(cols) {
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

    Matrix addMatrix(const Matrix& B) const {
        if (rows != B.rows || cols != B.cols) {
            throw "Matrix dimensions are not compatible for addition.";
        }

        Matrix result(rows, cols);

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.matrix[i][j] = matrix[i][j] + B.matrix[i][j];
            }
        }

        return result;
    }

    Matrix subtractMatrix(const Matrix& B) const {
        if (rows != B.rows || cols != B.cols) {
            throw "Matrix dimensions are not compatible for subtraction.";
        }

        Matrix result(rows, cols);

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.matrix[i][j] = matrix[i][j] - B.matrix[i][j];
            }
        }

        return result;
    }

    Matrix multiplyMatrix(const Matrix& B) const {
        if (cols != B.rows) {
            throw "Matrix dimensions are not compatible for multiplication.";
        }

        Matrix result(rows, B.cols);

        // Initialize result matrix elements to zero
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < B.cols; j++) {
                result.matrix[i][j] = 0;
            }
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < B.cols; j++) {
                for (int k = 0; k < cols; k++) {
                    result.matrix[i][j] += matrix[i][k] * B.matrix[k][j];
                }
            }
        }

        return result;
    }

    void displayMatrix() const {
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
        int r1, c1, r2, c2;

        cout << "Enter the rows and cols for matrix1" << endl;
        cin >> r1 >> c1;

        Matrix A(r1, c1);
        A.readMatrix();
        cout << "Matrix A:\n";
        A.displayMatrix();

        cout << "Enter the rows and cols for matrix2" << endl;
        cin >> r2 >> c2;

        Matrix B(r2, c2);
        B.readMatrix();
        cout << "Matrix B:\n";
        B.displayMatrix();

        cout << "Addition of Matrices A and B:\n";
        Matrix additionResult = A.addMatrix(B);
        additionResult.displayMatrix();

        cout << "Subtraction of Matrices A and B:\n";
        Matrix subtractionResult = A.subtractMatrix(B);
        subtractionResult.displayMatrix();

        cout << "Multiplication of Matrices A and B:\n";
        Matrix multiplicationResult = A.multiplyMatrix(B);
        multiplicationResult.displayMatrix();
    }
    catch (const char* msg) {
        cerr << msg << "\n";
    }

    return 0;
}
