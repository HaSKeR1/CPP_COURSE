#include <iostream>
#include <string>
#include <algorithm>
#include <windows.h>

void inputSurnames(std::string surnames[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << "Введите фамилию студента " << (i + 1) << ": ";
        std::getline(std::cin, surnames[i]);
    }
}

void printSurnames(const std::string surnames[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << surnames[i] << std::endl;
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const int size = 5;
    std::string surnames[size];

    inputSurnames(surnames, size);

    std::sort(surnames, surnames + size);

    std::cout << "\nОтсортированные фамилии студентов:" << std::endl;
    printSurnames(surnames, size);

    return 0;
}
