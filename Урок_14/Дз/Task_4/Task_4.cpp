#include <iostream>
#include <string>
#include <windows.h>

void replaceDots(std::string& str)
{
    for (char& c : str)
    {
        if (c == '.')
        {
            c = '!';
        }
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string input;

    std::cout << "Введите строку: ";
    getline(std::cin, input);

    replaceDots(input);

    std::cout << "Результат: " << input;

    return 0;
}
