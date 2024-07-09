#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

struct Car
{
    double length;
    double clearance;
    double engineVolume;
    int enginePower;
    double wheelDiameter;
    std::string color;
    std::string transmissionType;
};

void setCarValues(Car& car, double length, double clearance, double engineVolume, int enginePower,
    double wheelDiameter, const std::string& color, const std::string& transmissionType)
{
    car.length = length;
    car.clearance = clearance;
    car.engineVolume = engineVolume;
    car.enginePower = enginePower;
    car.wheelDiameter = wheelDiameter;
    car.color = color;
    car.transmissionType = transmissionType;
}

void displayCarValues(const Car& car)
{
    std::cout << "Характеристики автомобиля:" << std::endl;
    std::cout << "Длина: " << car.length << " м" << std::endl;
    std::cout << "Клиренс: " << car.clearance << " м" << std::endl;
    std::cout << "Объем двигателя: " << car.engineVolume << " л" << std::endl;
    std::cout << "Мощность двигателя: " << car.enginePower << " л.с." << std::endl;
    std::cout << "Диаметр колес: " << car.wheelDiameter << "\"" << std::endl;
    std::cout << "Цвет: " << car.color << std::endl;
    std::cout << "Тип коробки передач: " << car.transmissionType << std::endl;
}

void inputString(std::string& str)
{
    std::getline(std::cin, str);
}

void findCarByParameters(const std::vector<Car>& cars, double length, double clearance, double engineVolume,
    int enginePower, double wheelDiameter, const std::string& color, const std::string& transmissionType)
{
    bool found = false;
    for (const auto& car : cars)
    {
        if (car.length == length && car.clearance == clearance && car.engineVolume == engineVolume &&
            car.enginePower == enginePower && car.wheelDiameter == wheelDiameter &&
            car.color == color && car.transmissionType == transmissionType)
        {
            displayCarValues(car);
            found = true;
            break;
        }
    }
    if (!found)
    {
        std::cout << "Автомобиль с указанными параметрами не найден." << std::endl;
    }
}

void displayAllCars(const std::vector<Car>& cars)
{
    if (cars.empty())
    {
        std::cout << "Нет автомобилей для отображения." << std::endl;
    }
    else
    {
        for (const auto& car : cars)
        {
            displayCarValues(car);
            std::cout << "---------------------" << std::endl;
        }
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::vector<Car> cars;
    int choice;

    do
    {
        std::cout << "Меню:\n";
        std::cout << "1. Добавить автомобиль\n";
        std::cout << "2. Найти автомобиль по параметрам\n";
        std::cout << "3. Вывести все автомобили\n";
        std::cout << "4. Выйти\n";
        std::cout << "Выберите опцию: ";
        std::cin >> choice;
        std::cin.ignore();

        if (choice == 1)
        {
            Car car;
            double length, clearance, engineVolume, wheelDiameter;
            int enginePower;
            std::string color, transmissionType;

            std::cout << "Введите параметры автомобиля:\n";
            std::cout << "Длина (в метрах): ";
            std::cin >> length;
            std::cout << "Клиренс (в метрах): ";
            std::cin >> clearance;
            std::cout << "Объем двигателя (в литрах): ";
            std::cin >> engineVolume;
            std::cout << "Мощность двигателя (в л.с.): ";
            std::cin >> enginePower;
            std::cout << "Диаметр колес (в дюймах): ";
            std::cin >> wheelDiameter;
            std::cin.ignore();
            std::cout << "Цвет: ";
            inputString(color);
            std::cout << "Тип коробки передач: ";
            inputString(transmissionType);

            setCarValues(car, length, clearance, engineVolume, enginePower, wheelDiameter, color, transmissionType);
            cars.push_back(car);
        }
        else if (choice == 2)
        {
            double length, clearance, engineVolume, wheelDiameter;
            int enginePower;
            std::string color, transmissionType;

            std::cout << "Введите параметры для поиска автомобиля:\n";
            std::cout << "Длина (в метрах): ";
            std::cin >> length;
            std::cout << "Клиренс (в метрах): ";
            std::cin >> clearance;
            std::cout << "Объем двигателя (в литрах): ";
            std::cin >> engineVolume;
            std::cout << "Мощность двигателя (в л.с.): ";
            std::cin >> enginePower;
            std::cout << "Диаметр колес (в дюймах): ";
            std::cin >> wheelDiameter;
            std::cin.ignore();
            std::cout << "Цвет: ";
            inputString(color);
            std::cout << "Тип коробки передач: ";
            inputString(transmissionType);

            findCarByParameters(cars, length, clearance, engineVolume, enginePower, wheelDiameter, color, transmissionType);
        }
        else if (choice == 3)
        {
            displayAllCars(cars);
        }
    } while (choice != 4);

    return 0;
}
