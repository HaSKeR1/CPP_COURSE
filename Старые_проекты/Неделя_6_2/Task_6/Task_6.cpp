#include <iostream>

int main()
{
    setlocale(LC_ALL, "rus");

    int num;

    std::cout << "Введите число: ";
    std::cin >> num;

    for (int i = 1; i < num; i++)
    {
        if (num % i == 0)
        {
            std::cout << i << " ";
        }
    }

    return 0;
}