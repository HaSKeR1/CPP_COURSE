#include <iostream>

// Функция для транспонирования матрицы
void transposeMatrix(int** matrix, int rows, int cols, int** transposedMatrix) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            transposedMatrix[j][i] = matrix[i][j];
        }
    }
}

// Функция для вывода матрицы на экран
void printMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    int rows = 3, cols = 4;

    // Создание и инициализация исходной матрицы
    int** matrix = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
    }

    int count = 1;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = count++;
        }
    }

    std::cout << "Исходная матрица:" << std::endl;
    printMatrix(matrix, rows, cols);

    // Создание матрицы для хранения транспонированной матрицы
    int** transposedMatrix = new int* [cols];
    for (int i = 0; i < cols; ++i) {
        transposedMatrix[i] = new int[rows];
    }

    // Транспонирование матрицы
    transposeMatrix(matrix, rows, cols, transposedMatrix);

    std::cout << "Транспонированная матрица:" << std::endl;
    printMatrix(transposedMatrix, cols, rows);

    // Освобождение памяти
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    for (int i = 0; i < cols; ++i) {
        delete[] transposedMatrix[i];
    }
    delete[] transposedMatrix;

    return 0;
}
