#include <iostream>

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

int main()
{
    setlocale(LC_ALL, "rus");

    int num1, num2;

    std::cout << "Введите первое число: ";
    std::cin >> num1;
    std::cout << "Введите второе число: ";
    std::cin >> num2;

    int result = gcd(num1, num2);
    std::cout << "Наибольший общий делитель: " << result;

    return 0;
}
