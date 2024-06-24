#include <iostream>

int main()
{
    setlocale(LC_ALL, "rus");

    int A, sum = 0;

    std::cout << "Введите целое число A: ";
    std::cin >> A;

    for (int b = A; b > 0; b /= 10)
    {
        sum += b % 10;
    }

    if (sum * sum * sum == A * A)
    {
        std::cout << "Куб суммы цифр этого числа равен А*А";
    }
    else
    {
        std::cout << "Куб суммы цифр этого числа НЕ равен А*А";
    }

    return 0;
}