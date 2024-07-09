#include <iostream>
#include <cmath>
#include <string>

struct complexNumber
{
    double real;
    double img;
};

void printComplexNumber(complexNumber const& complexNumber)
{
    std::cout << std::noshowpos << complexNumber.real;
    std::cout << std::showpos << complexNumber.img << "i" << std::endl;
}

// Функция сложения
complexNumber Sum(complexNumber const& c1, complexNumber const& c2)
{
    complexNumber result;
    result.real = c1.real + c2.real;
    result.img = c1.img + c2.img;
    return result;
}

// Функция вычитания
complexNumber Subtract(complexNumber const& c1, complexNumber const& c2)
{
    complexNumber result;
    result.real = c1.real - c2.real;
    result.img = c1.img - c2.img;
    return result;
}

// Функция умножения
complexNumber Multiply(complexNumber const& c1, complexNumber const& c2)
{
    complexNumber result;
    result.real = c1.real * c2.real - c1.img * c2.img;
    result.img = c1.real * c2.img + c1.img * c2.real;
    return result;
}

// Функция деления
complexNumber Divide(complexNumber const& c1, complexNumber const& c2)
{
    complexNumber result;
    double denom = c2.real * c2.real + c2.img * c2.img;
    result.real = (c1.real * c2.real + c1.img * c2.img) / denom;
    result.img = (c1.img * c2.real - c1.real * c2.img) / denom;
    return result;
}

int main()
{
    setlocale(LC_ALL, "rus");

    complexNumber c1 = { 3.0, 4.0 };
    complexNumber c2 = { 1.0, 2.0 };

    complexNumber sum = Sum(c1, c2);
    complexNumber difference = Subtract(c1, c2);
    complexNumber product = Multiply(c1, c2);
    complexNumber quotient;

    if (c2.real != 0 || c2.img != 0)
    {
        quotient = Divide(c1, c2);
    }
    else
    {
        std::cerr << "Ошибка: деление на ноль." << std::endl;
    }

    std::cout << "c1: ";
    printComplexNumber(c1);
    std::cout << "c2: ";
    printComplexNumber(c2);

    std::cout << "\nСумма: ";
    printComplexNumber(sum);
    std::cout << "Разность: ";
    printComplexNumber(difference);
    std::cout << "Умножение: ";
    printComplexNumber(product);
    if (c2.real != 0 || c2.img != 0)
    {
        std::cout << "Деление: ";
        printComplexNumber(quotient);
    }

    return 0;
}
