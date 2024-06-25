#include <iostream>

int main()
{
    int pastHour, pastSecond, hourLeft;

    std::cout << "Введите время в секундах, прошедшее с начала рабочего дня:\n";
    std::cin >> pastSecond;

    pastHour = pastSecond / 60 / 60;
    hourLeft = 8 - pastHour;

    std::cout << "Осталось работать " << hourLeft << " часов";
    return 0;
}
