#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

int main()
{
    setlocale(LC_ALL, "rus");
    std::ifstream inputFile("input.txt");
    std::string word, wordToFind;
    int count = 0;

    if (!inputFile.is_open())
    {
        std::cout << "Не удалось открыть файл." << std::endl;
        return 1;
    }

    std::cout << "Введите слово для поиска: ";
    std::cin >> wordToFind;

    while (inputFile >> word)
    {
        word.erase(std::remove_if(word.begin(), word.end(), ::ispunct), word.end());

        if (word == wordToFind)
        {
            ++count;
        }
    }

    inputFile.close();

    std::cout << "Слово \"" << wordToFind << "\" встречается " << count << " раз в файле." << std::endl;

    return 0;
}
