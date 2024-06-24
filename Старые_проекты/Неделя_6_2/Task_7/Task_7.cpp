#include <iostream>

int main()
{
    setlocale(LC_ALL, "rus");

    int num1, num2, a;

    std::cout << "Введите первое число: ";
    std::cin >> num1;
    std::cout << "Введите второе число: ";
    std::cin >> num2;

    if (num1 > num2)
    {
        a = num1;
    }
    else
    {
        a = num2;
    }

    for (int i = 1; i <= a; i++)
    {
        if (num1 % i == 0 && num2 % i == 0)
        {
            std::cout << i << " ";
        }
    }

    return 0;
}
