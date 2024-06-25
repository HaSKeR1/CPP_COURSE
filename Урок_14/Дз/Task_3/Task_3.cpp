#include <iostream>
#include <string>
#include <windows.h>

std::string insertCharacter(const std::string& str, char ch, size_t pos)
{
    if (pos > str.length())
    {
        std::cout << "Ошибка!";
        return str;
    }
    std::string result = str;
    result.insert(pos, 1, ch);
    return result;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string input;
    char ch;
    size_t pos;

    std::cout << "Введите строку: ";
    getline(std::cin, input);

    std::cout << "Введите символ для вставки: ";
    std::cin >> ch;

    std::cout << "Введите позицию для вставки: ";
    std::cin >> pos;

    std::cout << "Результат: " << insertCharacter(input, ch, pos);

    return 0;
}
