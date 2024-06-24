#include <iostream>

int main()
{
    setlocale(LC_ALL, "rus");
    int a[100], i, size, sumOfNegative = 0, min = 0, max = 0, mult = 1, mult1 = 1;

    std::cout << "Введите кол-во элементов массива: ";
    std::cin >> size;

    for (i = 0; i < size; i++)
    {
        std::cout << "A[" << i << "] = ";
        std::cin >> a[i];
    }

    std::cout << std::endl;

    for (i = 0; i < size; i++)
    {
        if (a[i] < 0)
        {
            sumOfNegative = sumOfNegative + a[i];
        }
    }

    std::cout << "\nCумма отрицательных элементов = " << sumOfNegative << std::endl;

    int min2 = a[0];

    for (i = 0; i < size; i++)
    {
        if (a[i] < min2)
        {
            min2 = a[i];
            min = i;
        }
    }

    std::cout << "Минимальное значение массива : " << min2 << std::endl;
    std::cout << "Минимальный элемент массива :" << min << std::endl;

    int max2 = 0;

    for (i = 0; i < size; i++)
    {
        if (a[i] > max2)
        {
            max2 = a[i];
            max = i;
        }
    }

    std::cout << "Максимальное значение массива : " << max2 << std::endl;
    std::cout << "Максимальный элемент массива : " << max << std::endl;

    if (max > min)
    {
        for (i = min; i <= max; i++)
        {
            mult = mult * a[i];
        }
    }
    else
    {
        for (i = max; i <= min; i++)
        {
            mult = mult * a[i];
        }
    }

    std::cout << "Произведение между минимальным и максимальным элементами массива = " << mult << std::endl;

    for (i = 0; i < size; i++)
    {
        if (i % 2 == 0)
        {
            mult1 = mult1 * a[i];
        }
    }

    std::cout << "Произведение элементов с нечетными номерами: " << mult1 << std::endl;

    int firstNum = 0;
    int lastNum = 0;

    for (i = 0; i < size; i++)
    {
        if (a[i] < 0)
        {
            firstNum = a[i];
            lastNum = i; 
            break;
        }
    }

    int secondNum = 0;
    int secondNum2 = 0;

    for (i = size - 1; i >= 0; i--)
    {
        if (a[size - 1] < 0)
        {
            secondNum = a[size - 1];
            secondNum2 = size - 1;
            break;
        }
    }

    int sumOfNegative2 = 0;

    if (lastNum > secondNum2)
    {
        for (i = secondNum2; i < size; i++)
        {
            sumOfNegative2 = sumOfNegative2 + a[i];
        }
    }
    else
    {
        for (i = lastNum; i < size; i++)
        {
            sumOfNegative2 = sumOfNegative2 + a[i];
        }
    }

    std::cout << "Сумма элементов между первым и последним отрицательным числом: " << sumOfNegative2;

    return 0;
}