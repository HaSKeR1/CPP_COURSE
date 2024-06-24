#include <iostream>

int main()
{
    setlocale(LC_ALL, "rus");

    int k;

    std::cout << "Введите номер варианта для таблицы умножения: ";
    std::cin >> k;

    if (k > 0)
    {
        for (int i = 0; i < 10; i++)
        {
            std::cout << k << " x " << i << " = " << k * i << std::endl;
        }
    }
    else
    {
        std::cout << "Ошибка!";
    }
}
