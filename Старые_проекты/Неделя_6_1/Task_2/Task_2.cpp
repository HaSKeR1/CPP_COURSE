#include <iostream>

int main()
{
    setlocale(LC_ALL, "rus");

    int x, y;

    std::cout << "Введите x: ";
    std::cin >> x;
    std::cout << "Введите y: ";
    std::cin >> y;

    std::cout << pow(x, y);

    return 0;
}