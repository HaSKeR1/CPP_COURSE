#include <iostream>
#include <vector>

void addColumn(std::vector<std::vector<int>>& matrix, int position, const std::vector<int>& newColumn)
{
    if (position < 0 || position > matrix[0].size())
    {
        std::cout << "Некорректная позиция для добавления столбца." << std::endl;
        return;
    }

    if (newColumn.size() != matrix.size())
    {
        std::cout << "Размер нового столбца не совпадает с количеством строк в матрице." << std::endl;
        return;
    }

    for (size_t i = 0; i < matrix.size(); ++i)
    {
        matrix[i].insert(matrix[i].begin() + position, newColumn[i]);
    }
}

void printMatrix(const std::vector<std::vector<int>>& matrix)
{
    for (const auto& row : matrix)
    {
        for (const auto& elem : row)
        {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    setlocale(LC_ALL, "rus");
    std::vector<std::vector<int>> matrix =
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    std::vector<int> newColumn = { 10, 11, 12 };

    std::cout << "Исходная матрица:" << std::endl;
    printMatrix(matrix);

    int position = 0;
    std::cout << "Введите номер позиции: ";
    std::cin >> position;
    addColumn(matrix, position, newColumn);

    std::cout << "Матрица после добавления столбца:" << std::endl;
    printMatrix(matrix);

    return 0;
}
