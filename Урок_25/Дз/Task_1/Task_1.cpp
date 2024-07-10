#include <iostream>
#include <fstream>
#include <vector>
#include <string>

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
    std::ofstream outputFile("result.txt");

    for (int i = 0; i < fileRows.size() - 1; i++)
    {
        outputFile << fileRows[i] << std::endl;
    }

    inputFile.close();
    outputFile.close();
    return 0;
}