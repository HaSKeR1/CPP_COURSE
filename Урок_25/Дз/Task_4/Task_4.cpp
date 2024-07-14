#include <iostream>
#include <fstream>
#include <string>

int main()
{
    setlocale(LC_ALL, "rus");
    std::ifstream inputFile("example.txt");
    std::string replacementWord, wordToReplace, fileContent, line;
    size_t pos = 0;

    if (!inputFile.is_open())
    {
        std::cerr << "Не удалось открыть файл." << std::endl;
        return 1;
    }

    std::cout << "Введите, какое слово заменить: ";
    std::cin >> replacementWord;

    std::cout << "Введите слово для замены: ";
    std::cin >> wordToReplace;

    while (std::getline(inputFile, line))
    {
        fileContent += line + "\n";
    }

    while ((pos = fileContent.find(replacementWord, pos)) != std::string::npos)
    {
        fileContent.replace(pos, replacementWord.length(), wordToReplace);
        pos += wordToReplace.length();
    }

    std::ofstream outputFile("result.txt");

    if (!outputFile.is_open())
    {
        std::cerr << "Не удалось открыть файл." << std::endl;
        return 1;
    }

    outputFile << fileContent;


    std::cout << "Слово \"" << replacementWord << "\" Было заменено словом \"" << wordToReplace << "\" в файле." << std::endl;

    inputFile.close();
    outputFile.close();

    return 0;
}
