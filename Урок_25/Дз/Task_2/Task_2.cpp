#include <iostream>
#include <fstream>
#include <string>

int main()
{
    setlocale(LC_ALL, "rus");
    std::ifstream inputFile("input.txt");
    std::string line;
    size_t maxLength = 0;

    if (!inputFile.is_open())
    {
        std::cout << "Не удалось открыть файл." << std::endl;
        return 1;
    }

    while (std::getline(inputFile, line))
    {
        if (line.length() > maxLength)
        {
            maxLength = line.length();
        }
    }

    inputFile.close();

    std::cout << "Длина самой длинной строки: " << maxLength << std::endl;

    return 0;
}
