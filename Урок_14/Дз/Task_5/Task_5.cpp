#include <iostream>
#include <string>
#include <windows.h>

int countCharacterOccurrences(const std::string& str, char ch)
{
    int count = 0;
    for (char c : str)
    {
        if (c == ch)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string input;
    char searchChar;

    std::cout << "Введите строку: ";
    getline(std::cin, input);

    std::cout << "Введите искомый символ: ";
    std::cin >> searchChar;

    std::cout << "Символ '" << searchChar << "' встречается " << countCharacterOccurrences(input, searchChar) << " раз(а)";

    return 0;
}
