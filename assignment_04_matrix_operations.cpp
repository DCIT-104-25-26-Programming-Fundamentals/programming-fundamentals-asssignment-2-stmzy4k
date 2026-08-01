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

const int SIZE = 10;

void displayMatrix(int matrix[SIZE][SIZE], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

void transposeMatrix(int matrix[SIZE][SIZE], int rows, int cols)
{
    int transpose[SIZE][SIZE];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            transpose[j][i] = matrix[i][j];
        }
    }

    cout << "Transposed Matrix:" << endl;
    displayMatrix(transpose, cols, rows);
}

void addMatrices(int A[SIZE][SIZE], int B[SIZE][SIZE], int rows, int cols)
{
    int result[SIZE][SIZE];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = A[i][j] + B[i][j];
        }
    }

    cout << "Matrix Addition:" << endl;
    displayMatrix(result, rows, cols);
}

void multiplyMatrices(int A[SIZE][SIZE], int B[SIZE][SIZE],
                      int rowsA, int colsA, int rowsB, int colsB)
{
    if (colsA != rowsB)
    {
        cout << "Matrix multiplication not possible." << endl;
        return;
    }

    int result[SIZE][SIZE] = {0};

    for (int i = 0; i < rowsA; i++)
    {
        for (int j = 0; j < colsB; j++)
        {
            for (int k = 0; k < colsA; k++)
            {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    cout << "Matrix Multiplication:" << endl;
    displayMatrix(result, rowsA, colsB);
}


int main()
{
    int matrix[SIZE][SIZE];
    int A[SIZE][SIZE];
    int B[SIZE][SIZE];

    int rows, cols;

    cout << "Enter number of rows: ";
    cin >> rows;

    cout << "Enter number of columns: ";
    cin >> cols;


    // Read first matrix
    cout << "Enter Matrix:" << endl;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }


    cout << "\nOriginal Matrix:" << endl;
    displayMatrix(matrix, rows, cols);

    transposeMatrix(matrix, rows, cols);


    // Read matrices for addition
    cout << "\nMatrix Addition" << endl;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "Enter A[" << i << "][" << j << "]: ";
            cin >> A[i][j];
        }
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "Enter B[" << i << "][" << j << "]: ";
            cin >> B[i][j];
        }
    }

    addMatrices(A, B, rows, cols);


    // Matrix multiplication
    int rowsB, colsB;

    cout << "\nFor multiplication enter B size:" << endl;

    cout << "Rows of B: ";
    cin >> rowsB;

    cout << "Columns of B: ";
    cin >> colsB;


    multiplyMatrices(A, B, rows, cols, rowsB, colsB);


    return 0;
}