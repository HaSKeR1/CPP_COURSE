#include <iostream>

int main()
{
    setlocale(LC_ALL, "rus");
    int choice, desiredIncome, income = 0, delays, linesOfCode = 0;

    std::cout << "1: Узнать нужное кол-во строк кода\n";
    std::cout << "2: Узнать возможное кол-во опозданий\n";
    std::cout << "3: Узнать, сколько заплатят\n";
    
    std::cout << "Введите номер: ";
    std::cin >> choice;

    switch (choice)
    {
    // Строки кода
    case 1:
        std::cout << "\nВведите желаемый доход: ";
        std::cin >> income;
        std::cout << "Введите кол-во опозданий: ";
        std::cin >> delays;

        // Нужный доход вместе с опозданиями
        for (int i = delays; i >= 3; i -= 3)
        {
            income += 20;
        }
        // Нужное кол-во строк кода для нужного дохода
        for (int i = 0; i <= income; linesOfCode += 100)
        {
            i += 50;
        }

        std::cout << "\nНужно написать " << linesOfCode << " строк кода";
        break;

    case 2:
        std::cout << "\nВведите количество написанных строк кода: ";
        std::cin >> linesOfCode;
        std::cout << "Введите желаемую зарплату: ";
        std::cin >> desiredIncome;
        delays = 2;

        // Полученный доход
        for (int i = linesOfCode; i >= 100; i -= 100)
        {
            income += 50;
        }

        // Конец программы, если полученная зарплата меньше желаемой
        if (income < desiredIncome)
        {
            std::cout << "\nОшибка! Полученная зарплата меньше желаемой";
            break;
        }

        // Кол-во опозданий
        for (int i = income - desiredIncome; i >= 20; i -= 20)
        {
            delays += 3;
        }

        std::cout << "\nМожно опоздать " << delays << " раз(а)";
        break;

    case 3:
        std::cout << "\nВведите кол-во написанных строк кода: ";
        std::cin >> linesOfCode;
        std::cout << "Введите кол-во опозданий: ";
        std::cin >> delays;

        // Полученный доход
        for (int i = linesOfCode; i >= 100; i -= 100)
        {
            income += 50;
        }
        // Полученный доход с опозданиями
        for (int i = delays; i >= 3; i -= 3)
        {
            income -= 20;
        }

        if (income > 0) {
            std::cout << "\nЗаплатят " << income << "$";
        }
        else
        {
            std::cout << "\nНе заплатят";
        }
        break;

    default:
        std::cout << "Ошибка!";
    }
}