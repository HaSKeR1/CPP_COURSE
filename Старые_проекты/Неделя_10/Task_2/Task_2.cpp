#include <iostream>

int main()
{
    setlocale(LC_ALL, "rus");

    const int rows = 5;
    const int cols = 5;
    int initialNumber, array[rows][cols];

    std::cout << "Введите начальное число: ";
    std::cin >> initialNumber;

    int currentNumber = initialNumber;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            array[i][j] = currentNumber;
            currentNumber += 1;
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
