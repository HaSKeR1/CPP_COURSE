#include <iostream>
#include <time.h>

void fillArrayWithRandomNumbers(int arr[][5], int rows, int cols)
{
    srand(time(0));
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            arr[i][j] = rand() % 10;
        }
    }
}

void printArray(int arr[][5], int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void shiftArray(int arr[][5], int rows, int cols, int shifts, char direction)
{
    shifts %= (direction == 'l' || direction == 'r') ? cols : rows;
    if (shifts == 0)
    {
        return;
    }

    for (int shift = 0; shift < shifts; ++shift)
    {
        switch(direction)
        {
        case 'l':
            for (int i = 0; i < rows; ++i)
            {
                int temp = arr[i][0];
                for (int j = 0; j < cols - 1; ++j)
                {
                    arr[i][j] = arr[i][j + 1];
                }
                arr[i][cols - 1] = temp;
            }
            break;
        case 'r':
            for (int i = 0; i < rows; ++i)
            {
                int temp = arr[i][cols - 1];
                for (int j = cols - 1; j > 0; --j)
                {
                    arr[i][j] = arr[i][j - 1];
                }
                arr[i][0] = temp;
            }
            break;
        case 'u':
            for (int j = 0; j < cols; ++j)
            {
                int temp = arr[0][j];
                for (int i = 0; i < rows - 1; ++i)
                {
                    arr[i][j] = arr[i + 1][j];
                }
                arr[rows - 1][j] = temp;
            }
            break;
        case 'd':
            for (int j = 0; j < cols; ++j)
            {
                int temp = arr[rows - 1][j];
                for (int i = rows - 1; i > 0; --i)
                {
                    arr[i][j] = arr[i - 1][j];
                }
                arr[0][j] = temp;
            }
            break;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "rus");

    const int rows = 5;
    const int cols = 5;
    int array[rows][cols], shifts;
    char direction;

    fillArrayWithRandomNumbers(array, rows, cols);

    std::cout << "Исходный массив:\n";
    printArray(array, rows, cols);

    std::cout << "Введите количество сдвигов: ";
    std::cin >> shifts;
    std::cout << "Введите направление сдвига (l - влево, r - вправо, u - вверх, d - вниз): ";
    std::cin >> direction;

    shiftArray(array, rows, cols, shifts, direction);

    std::cout << "Массив после сдвига:\n";
    printArray(array, rows, cols);

    return 0;
}
