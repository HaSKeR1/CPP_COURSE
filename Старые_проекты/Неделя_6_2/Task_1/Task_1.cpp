#include <iostream>

int main()
{
    setlocale(LC_ALL, "rus");

    int count = 0;
    int num1, num2, num3;

    for (int i = 100; i <= 999; i++)
    {
        num1 = i / 100;
        num2 = i % 10;
        num3 = (i % 100) / 10;

        if (num1 == num2 || num2 == num3 || num3 == num1)
        {
            count++;
        }
    }

    std::cout << "Кол-во чисел: " << count;

    return 0;
}
