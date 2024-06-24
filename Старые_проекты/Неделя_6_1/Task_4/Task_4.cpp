#include <iostream>

int main()
{
    int result = 1, a;

    std::cout << "Введите число от 1 до 20: ";
    std::cin >> a;

    for (int i = a; i <= 20; i++)
    {
        result *= i;
    }

    std::cout << result;

    return 0;
}