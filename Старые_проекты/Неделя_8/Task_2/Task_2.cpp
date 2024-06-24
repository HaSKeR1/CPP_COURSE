#include <iostream>
#include <random>
#include <time.h>

int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(NULL));

    int range, value, summa = 0, arr[10];

    std::cout << "Введите диапазон случайных чисел в массиве: ";
    std::cin >> range;
    std::cout << "Введите значение для элементов: ";
    std::cin >> value;

    for (int i = 0; i < 10; i++)
    {
        arr[i] = rand() % range;

        if (arr[i] <= value)
        {
            summa += arr[i];
            std::cout << summa << " ";
        }
    }
    std::cout << std::endl;
    for (int i = 0; i < 10; i++)
    {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl << "Сумма: " << summa;

    return 0;
}