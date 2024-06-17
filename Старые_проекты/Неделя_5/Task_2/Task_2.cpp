#include <iostream>

int main()
{
    setlocale(LC_ALL, "rus");
    int input, duration;

    std::cout << "С какого на какой оператор вы звоните?\n";
    std::cout << "1: Beeline - Beeline\n";
    std::cout << "2: Beeline - Tele2\n";
    std::cout << "3: Beeline - MTS\n";
    std::cout << "4: Tele2 - Tele2\n";
    std::cout << "5: Tele2 - Beeline\n";
    std::cout << "6: Tele2 - MTS\n";
    std::cout << "7: MTS - MTS\n";
    std::cout << "8: MTS - Beeline\n";
    std::cout << "9: MTS - Tele2\n";

    std::cout << "Введите номер: ";
    std::cin >> input;

    std::cout << "Введите длительность разговора в минутах: ";
    std::cin >> duration;

    switch (input)
    {
    // Beeline - Beeline
    case 1:
        std::cout << "Стоимость разговора - " << duration * 0.8 << " руб";
        break;
    // Beeline - Tele2
    case 2:
        std::cout << "Стоимость разговора - " << duration * 1.5 << " руб";
        break;
    // Beeline - MTS
    case 3:
        std::cout << "Стоимость разговора - " << duration * 1.5 << " руб";
        break;
    // Tele2 - Tele2
    case 4:
        std::cout << "Стоимость разговора - " << duration * 3 << " руб";
        break;
    // Tele2 - Beeline
    case 5:
        std::cout << "Стоимость разговора - " << duration * 9 << " руб";
        break;
    // Tele2 - MTS
    case 6:
        std::cout << "Стоимость разговора - " << duration * 9 << " руб";
        break;
    // MTS - MTS
    case 7:
        std::cout << "Стоимость разговора - " << duration * 2.5 << " руб";
        break;
    // MTS - Beeline
    case 8:
        std::cout << "Стоимость разговора - " << duration * 4 << " руб";
        break;
    // MTS - Tele2
    case 9:
        std::cout << "Стоимость разговора - " << duration * 4 << " руб";
        break;
    default:
        std::cout << "Ошибка!";
        break;
    }
}