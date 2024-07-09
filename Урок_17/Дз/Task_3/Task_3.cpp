#include <iostream>
#include <vector>

void fillMatrix(std::vector<std::vector<int>>& matrix, int rows, int cols)
{
    int value = 1;
    for (int i = 0; i < rows; ++i)
    {
        std::vector<int> row;
        for (int j = 0; j < cols; ++j)
        {
            row.push_back(value++);
        }
        matrix.push_back(row);
    }
}

void printMatrix(const std::vector<std::vector<int>>& matrix)
{
    for (const auto& row : matrix)
    {
        for (const auto& elem : row)
        {
            std::cout << elem << "\t";
        }
        std::cout << std::endl;
    }
}

void shiftRow(std::vector<std::vector<int>>& matrix, int rowIndex, int shift, bool direction)
{
    int cols = matrix[0].size();
    shift = shift % cols;
    std::vector<int> newRow(cols);

    for (int j = 0; j < cols; ++j)
    {
        int newIndex = direction ? (j + shift) % cols : (j - shift + cols) % cols;
        newRow[newIndex] = matrix[rowIndex][j];
    }

    matrix[rowIndex] = newRow;
}

void shiftColumn(std::vector<std::vector<int>>& matrix, int colIndex, int shift, bool direction) 
{
    int rows = matrix.size();
    shift = shift % rows;
    std::vector<int> newCol(rows);

    for (int i = 0; i < rows; ++i)
    {
        int newIndex = direction ? (i + shift) % rows : (i - shift + rows) % rows;
        newCol[newIndex] = matrix[i][colIndex];
    }

    for (int i = 0; i < rows; ++i)
    {
        matrix[i][colIndex] = newCol[i];
    }
}

void shiftMatrix(std::vector<std::vector<int>>& matrix, int shifts, bool direction, bool isRow)
{
    int limit = isRow ? matrix.size() : matrix[0].size();

    for (int i = 0; i < limit; ++i)
    {
        if (isRow)
        {
            shiftRow(matrix, i, shifts, direction);
        }
        else
        {
            shiftColumn(matrix, i, shifts, direction);
        }
    }
}

int main()
{
    setlocale(LC_ALL, "rus");
    int rows = 4, cols = 5;
    std::vector<std::vector<int>> matrix;

    fillMatrix(matrix, rows, cols);

    std::cout << "Исходная матрица:" << std::endl;
    printMatrix(matrix);

    int shifts;
    bool direction, isRow;

    std::cout << "Введите количество сдвигов: ";
    std::cin >> shifts;
    std::cout << "Введите направление сдвига (0 - влево/вверх, 1 - вправо/вниз): ";
    std::cin >> direction;
    std::cout << "Введите тип сдвига (0 - столбцы, 1 - строки): ";
    std::cin >> isRow;

    shiftMatrix(matrix, shifts, direction, isRow);

    std::cout << "Матрица после сдвига:" << std::endl;
    printMatrix(matrix);

    return 0;
}
