#include <iostream>

int main()
{
    setlocale(LC_ALL, "rus");

    const int size = 12;
    int firstMonth, secondMonth, array[size];

    std::cout << "Введите прибыль фирмы за год:\n";

    for (int i = 0; i < size; i++)
    {
        std::cout << "Прибыль за " << i + 1 << " месяц:";
        std::cin >> array[i];
    }

    std::cout << "\nВведите диапазон(например, 3 и 6 - поиск между 3-м и 6-м месяцем)\n\n";
    std::cout << "Первый месяц:";
    std::cin >> firstMonth;
    std::cout << "Второй месяц:";
    std::cin >> secondMonth;

    firstMonth -= 1;
    secondMonth -= 1;

    int maxIncome = array[firstMonth], minIncome = array[firstMonth];

    for (int i = firstMonth; i <= secondMonth; i++)
    {
        if (array[i] > maxIncome)
        {
            maxIncome = array[i];
        }
        if (array[i] < minIncome)
        {
            minIncome = array[i];
        }
    }
    std::cout << "Максимальная прибыль - " << maxIncome << std::endl;
    std::cout << "Минимальная прибыль - " << minIncome;

    return 0;
}