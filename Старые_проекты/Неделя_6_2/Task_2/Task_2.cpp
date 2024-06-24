#include <iostream>

int main()
{
    setlocale(LC_ALL, "rus");

    int num1, num2, num3;
    int count = 0;

    for (int i = 100; i <= 999; i++)
    {
        num1 = i / 100;
        num2 = i % 10;
        num3 = (i % 100) / 10;

        if (num1 != num2 && num2 != num3 && num1 != num3)
        {
            count++;
        }
    }

    std::cout << count;

    return 0;
}