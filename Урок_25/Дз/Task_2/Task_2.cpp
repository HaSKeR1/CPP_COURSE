#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main()
{
    setlocale(LC_ALL, "rus");
    std::ifstream inputFile("example.txt");
    std::string currentRow;
    std::vector<std::string> fileRows;

    if (!inputFile.is_open())
    {
        std::cout << "Не удалось открыть файл." << std::endl;
        return 1;
    }

    while (std::getline(inputFile, currentRow))
    {
        fileRows.push_back(currentRow);
    }

    inputFile.close();
    return 0;
}