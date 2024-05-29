#include <iostream>

std::string DeleteCharFromStringByIndex(std::string const& str, size_t index)
{
    std::string result;

    for (size_t i = 0; i < str.size(); i++)
    {
        if (i != index)
        {
            result.push_back(str[i]);
        }
    }

    return result;
}

int main()
{
    setlocale(LC_ALL, "rus");
    std::string str;
    size_t index;
    std::cout << "Введите строку: ";
    std::cin >> str;
    std::cout << "\nВведите номер символа: ";
    std::cin >> index;
    std::cout << DeleteCharFromStringByIndex(str, index);
}