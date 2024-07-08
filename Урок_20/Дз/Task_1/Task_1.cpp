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

//4 функции

complexNumber Sum(complexNumber const& c1, complexNumber const& c2)
{
    complexNumber result;



    return result;
}

int main()
{
    std::cout << "Hello World!\n";

}