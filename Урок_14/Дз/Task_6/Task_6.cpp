#include <iostream>
#include <string>
#include <windows.h>

void countCharacters(const std::string& str, int& letterCount, int& digitCount, int& otherCount)
{
    letterCount = 0;
    digitCount = 0;
    otherCount = 0;

    for (char c : str)
    {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        {
            letterCount++;
        }
        else if (c >= '0' && c <= '9')
        {
            digitCount++;
        }
        else
        {
            otherCount++;
        }
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string input;
    int letterCount, digitCount, otherCount;

    std::cout << "Введите строку: ";
    getline(std::cin, input);

    countCharacters(input, letterCount, digitCount, otherCount);

    std::cout << "Количество букв: " << letterCount;
    std::cout << "\nКоличество цифр: " << digitCount;
    std::cout << "\nКоличество остальных символов: " << otherCount;

    return 0;
}
