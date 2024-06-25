#include <iostream>
#include <string>
#include <windows.h>

std::string removeCharacter(const std::string& str, char ch)
{
    std::string result;
    for (char c : str)
    {
        if (c != ch)
        {
            result += c;
        }
    }
    return result;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string input;
    char ch;

    std::cout << "Введите строку: ";
    getline(std::cin, input);

    std::cout << "Введите символ для удаления: ";
    std::cin >> ch;

    std::cout << "Результат: " << removeCharacter(input, ch);

    return 0;
}
