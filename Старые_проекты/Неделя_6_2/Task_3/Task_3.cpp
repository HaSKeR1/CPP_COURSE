#include <iostream>

int main()
{
    setlocale(LC_ALL, "rus");

    int num, i = 0, a = 0;

    std::cout << "Введите число: ";
    std::cin >> num;
    std::cout << std::endl;

    while (num > 0)
    {
        if (num % 10 != 3 && num % 10 != 6)
        {
            a *= 10;
            a += num % 10;
        }
        num /= 10;
    }

    std::cout << "Полученное число: ";

    while (a > 0)
    {
        std::cout << a % 10;
        a /= 10;
    }

    std::cout << std::endl << std::endl;

    return 0;
}
