#include <iostream>

int main()
{
    setlocale(LC_ALL, "rus");
    char input;

    std::cout << "Введите символ: ";
    std::cin >> input;

    if (input >= '1' && input <= '9')
    {
        std::cout << "Введённый символ является числом";
    }
    else if (input >= 'a' && input <= 'z' || input >= 'A' && input <= 'Z')
    {
        std::cout << "Введённый символ является буквой";
    }
    else if (input == '.' || input == ',' || input == ';' || input == ':' || input == '"')
    {
        std::cout << "Введённый символ является знаком препинания";
    }
    else
    {
        std::cout << "Введённый символ является другим";
    }
}
