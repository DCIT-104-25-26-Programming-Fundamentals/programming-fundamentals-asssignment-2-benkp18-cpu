// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
#include <iostream>
#include <vector>
using namespace std;

// Function to transpose a matrix
vector<vector<int>> transposeMatrix(vector<vector<int>> matrix, int rows, int cols)
{
    vector<vector<int>> result(cols, vector<int>(rows));

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[j][i] = matrix[i][j];
        }
    }

    return result;
}

// Function to add two matrices
vector<vector<int>> addMatrices(vector<vector<int>> a, vector<vector<int>> b, int rows, int cols)
{
    vector<vector<int>> result(rows, vector<int>(cols));

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = a[i][j] + b[i][j];
        }
    }

    return result;
}

// Function to multiply two matrices
vector<vector<int>> multiplyMatrices(vector<vector<int>> a, vector<vector<int>> b, int m, int n, int p)
{
    vector<vector<int>> result(m, vector<int>(p, 0));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < p; j++)
        {
            for (int k = 0; k < n; k++)
            {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    return result;
}

// Function to read a matrix
vector<vector<int>> readMatrix(int rows, int cols)
{
    vector<vector<int>> matrix(rows, vector<int>(cols));

    for (int i = 0; i < rows; i++)
    {
        cout << "Enter row " << i + 1 << ": ";
        for (int j = 0; j < cols; j++)
        {
            cin >> matrix[i][j];
        }
    }

    return matrix;
}

// Function to print a matrix
void printMatrix(vector<vector<int>> matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

int main()
{
    int choice;

    cout << "Matrix Operations Menu:" << endl;
    cout << "1. Transpose a Matrix" << endl;
    cout << "2. Add Two Matrices" << endl;
    cout << "3. Multiply Two Matrices" << endl;
    cout << "Enter choice: ";
    cin >> choice;

    if (choice == 1)
    {
        int rows, cols;

        cout << "Enter number of rows: ";
        cin >> rows;
        cout << "Enter number of columns: ";
        cin >> cols;

        vector<vector<int>> matrix = readMatrix(rows, cols);
        vector<vector<int>> result = transposeMatrix(matrix, rows, cols);

        cout << "\nOriginal Matrix:\n";
        printMatrix(matrix);

        cout << "\nTransposed Matrix:\n";
        printMatrix(result);
    }
    else if (choice == 2)
    {
        int rows, cols;

        cout << "Enter number of rows: ";
        cin >> rows;
        cout << "Enter number of columns: ";
        cin >> cols;

        cout << "\nEnter values for Matrix A:\n";
        vector<vector<int>> a = readMatrix(rows, cols);

        cout << "\nEnter values for Matrix B:\n";
        vector<vector<int>> b = readMatrix(rows, cols);

        vector<vector<int>> result = addMatrices(a, b, rows, cols);

        cout << "\nSum Matrix:\n";
        printMatrix(result);
    }
    else if (choice == 3)
    {
        int m, n, n2, p;

        cout << "Enter rows of Matrix A (M): ";
        cin >> m;

        cout << "Enter columns of Matrix A (N): ";
        cin >> n;

        cout << "Enter rows of Matrix B (must equal N): ";
        cin >> n2;

        cout << "Enter columns of Matrix B (P): ";
        cin >> p;

        if (n != n2)
        {
            cout << "Error: Columns of A must equal rows of B." << endl;
        }
        else
        {
            cout << "\nEnter values for Matrix A:\n";
            vector<vector<int>> a = readMatrix(m, n);

            cout << "\nEnter values for Matrix B:\n";
            vector<vector<int>> b = readMatrix(n, p);

            vector<vector<int>> result = multiplyMatrices(a, b, m, n, p);

            cout << "\nProduct Matrix:\n";
            printMatrix(result);
        }
    }
    else
    {
        cout << "Invalid choice." << endl;
    }

    return 0;
}
