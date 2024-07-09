#include <iostream>
#include <vector>

void removeColumn(std::vector<std::vector<int>>& matrix, int column)
{
    if (column < 0 || column >= matrix[0].size())
    {
        std::cout << "Некорректный номер столбца." << std::endl;
        return;
    }

    for (size_t i = 0; i < matrix.size(); ++i)
    {
        matrix[i].erase(matrix[i].begin() + column);
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

    std::cout << "Исходная матрица:" << std::endl;
    printMatrix(matrix);

    int position = 0;
    std::cout << "Введите номер позиции: ";
    std::cin >> position;
    removeColumn(matrix, position);

    std::cout << "Матрица после удаления столбца:" << std::endl;
    printMatrix(matrix);

    return 0;
}
