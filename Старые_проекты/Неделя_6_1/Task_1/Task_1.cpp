#include <iostream>

int main()
{
    setlocale(LC_ALL, "rus");

    int a, result;

    std::cout << "Введите целое число до 500: ";
    std::cin >> a;

    result = a;

    for (int i = 500 - a; i > 0; i--)
    {
        a += 1;
        result += a;
    }

    std::cout << "Сумма: " << result;

    return 0;
}
