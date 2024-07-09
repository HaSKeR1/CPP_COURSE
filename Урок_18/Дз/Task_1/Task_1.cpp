#include <iostream>

void transposeMatrix(int** matrix, int rows, int cols, int** transposedMatrix)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            transposedMatrix[j][i] = matrix[i][j];
        }
    }
}

void printMatrix(int** matrix, int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    int rows = 3, cols = 4;

    int** matrix = new int* [rows];
    for (int i = 0; i < rows; ++i)
    {
        matrix[i] = new int[cols];
    }

    int count = 1;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            matrix[i][j] = count++;
        }
    }

    std::cout << "Исходная матрица:" << std::endl;
    printMatrix(matrix, rows, cols);

    int** transposedMatrix = new int* [cols];
    for (int i = 0; i < cols; ++i)
    {
        transposedMatrix[i] = new int[rows];
    }

    transposeMatrix(matrix, rows, cols, transposedMatrix);

    std::cout << "Транспонированная матрица:" << std::endl;
    printMatrix(transposedMatrix, cols, rows);

    for (int i = 0; i < rows; ++i)
    {
        delete[] matrix[i];
    }
    delete[] matrix;

    for (int i = 0; i < cols; ++i)
    {
        delete[] transposedMatrix[i];
    }
    delete[] transposedMatrix;

    return 0;
}
