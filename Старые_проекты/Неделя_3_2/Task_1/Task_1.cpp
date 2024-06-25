#include <iostream>

int main()
{
    setlocale(LC_ALL, "rus");

    int pastHour, pastMinute, pastSecond, hourLeft, minuteLeft, secondLeft, secondsInDay = 86400;

    std::cout << "Введите время в секундах, прошедшее с начала дня: ";
    std::cin >> pastSecond;

    secondsInDay -= pastSecond;

    pastHour = pastSecond / 60 / 60;
    pastMinute = pastSecond / 60 - pastHour * 60;
    pastSecond = pastSecond - (pastHour * 60 * 60 + pastMinute * 60);

    hourLeft = secondsInDay / 60 / 60;
    minuteLeft = secondsInDay / 60 - hourLeft * 60;
    secondLeft = secondsInDay - (hourLeft * 60 * 60 + minuteLeft * 60);

    std::cout << "Текущее время: " << pastHour << " часов " << pastMinute << " минут " << pastSecond << " секунд\n";
    std::cout << "До полуночи осталось: " << hourLeft << " часов " << minuteLeft << " минут " << secondLeft << " секунд";

    return 0;
}