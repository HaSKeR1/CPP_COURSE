#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>

void initializeBoard(std::vector<std::vector<char>>& board, std::vector<char>& values)
{
    std::random_shuffle(values.begin(), values.end());
    int index = 0;
    for (int i = 0; i < board.size(); ++i)
    {
        for (int j = 0; j < board[i].size(); ++j)
        {
            board[i][j] = values[index++];
        }
    }
}

void displayBoard(const std::vector<std::vector<char>>& board, const std::vector<std::vector<bool>>& revealed)
{
    std::cout << "  ";
    for (int j = 0; j < board[0].size(); ++j)
    {
        std::cout << j << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < board.size(); ++i)
    {
        std::cout << i << " ";
        for (int j = 0; j < board[i].size(); ++j)
        {
            if (revealed[i][j])
            {
                std::cout << board[i][j] << " ";
            }
            else
            {
                std::cout << "* ";
            }
        }
        std::cout << std::endl;
    }
}

bool isGameFinished(const std::vector<std::vector<bool>>& revealed)
{
    for (const auto& row : revealed)
    {
        for (bool cell : row)
        {
            if (!cell)
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    setlocale(LC_ALL, "rus");
    int rows, cols;
    std::cout << "Введите кол-во строк: ";
    std::cin >> rows;
    std::cout << "Введите кол-во столбцов: ";
    std::cin >> cols;

    if ((rows * cols) % 2 != 0)
    {
        std::cout << "Общее кол-во клеток нечётное. Перезапустите игру с корректными значениями." << std::endl;
        return 1;
    }

    std::vector<std::vector<char>> board(rows, std::vector<char>(cols));
    std::vector<std::vector<bool>> revealed(rows, std::vector<bool>(cols, false));
    std::vector<char> values;

    // Генерация значений для доски
    char currentChar = 'A';
    for (int i = 0; i < (rows * cols) / 2; ++i)
    {
        values.push_back(currentChar);
        values.push_back(currentChar);
        ++currentChar;
    }

    initializeBoard(board, values);
    int moves = 0;
    clock_t startTime = clock();

    while (!isGameFinished(revealed))
    {
        displayBoard(board, revealed);
        int x1, y1, x2, y2;

        std::cout << "Введите координаты первой карты (строка и столбец): ";
        std::cin >> x1 >> y1;
        std::cout << "Введите координаты второй карты (строка и столбец): ";
        std::cin >> x2 >> y2;

        if (x1 < 0 || x1 >= rows || y1 < 0 || y1 >= cols || x2 < 0 || x2 >= rows || y2 < 0 || y2 >= cols)
        {
            std::cout << "Некорректные координаты. Попробуйте снова" << std::endl;
            continue;
        }

        if ((x1 == x2 && y1 == y2) || revealed[x1][y1] || revealed[x2][y2])
        {
            std::cout << "Некорректный ход. Попробуйте снова." << std::endl;
            continue;
        }

        revealed[x1][y1] = true;
        revealed[x2][y2] = true;
        displayBoard(board, revealed);

        if (board[x1][y1] == board[x2][y2])
        {
            std::cout << "Пара найдена!" << std::endl;
        }
        else
        {
            std::cout << "Пары нет. Попробуйте снова." << std::endl;
            revealed[x1][y1] = false;
            revealed[x2][y2] = false;
        }

        moves++;
    }

    clock_t endTime = clock();
    double elapsedTime = static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC;

    std::cout << "Победа! Вы выиграли за " << moves << " ход(а)." << std::endl;
    std::cout << "Время: " << elapsedTime << "s" << std::endl;

    return 0;
}
