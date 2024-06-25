#include <iostream>

int main()
{
    setlocale(LC_ALL, "rus");

    const int rows = 5, cols = 5;
    int initialNumber, array[rows][cols];

    std::cout << "Введите начальное число: ";
    std::cin >> initialNumber;

    array[0][0] = initialNumber;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (i == 0 && j == 0)
            {
            }
            else if (j == 0)
            {
                array[i][j] = array[i - 1][cols - 1] * 2;
            }
            else
            {
                array[i][j] = array[i][j - 1] * 2;
            }
        }
    }

    std::cout << "Созданный массив:\n";
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            std::cout << array[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

