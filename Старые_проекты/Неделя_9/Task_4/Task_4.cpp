#include <iostream>

int main()
{
    setlocale(LC_ALL, "rus");

    const int MONTHS = 12;
    double exchangeRates[MONTHS];
    double interestRates[MONTHS];
    double depositAmount;
    int month;

    std::cout << "Введите курс доллара по отношению к евро за каждый месяц (12 значений):\n";
    for (int i = 0; i < MONTHS; ++i)
    {
        std::cin >> exchangeRates[i];
    }

    std::cout << "Введите начисленные проценты за каждый месяц на депозитном счету в евро (12 значений):\n";
    for (int i = 0; i < MONTHS; ++i)
    {
        std::cin >> interestRates[i];
    }

    std::cout << "Введите сумму на депозите в евро: ";
    std::cin >> depositAmount;

    std::cout << "Введите номер месяца (1-12): ";
    std::cin >> month;

    if (month < 1 || month > 12)
    {
        std::cout << "Некорректный номер месяца!\n";
        return 1;
    }

    int index = month - 1;
    double interestAmount = depositAmount * (interestRates[index] / 100.0);
    double amountInDollars = interestAmount * exchangeRates[index];

    if (amountInDollars >= 500)
    {
        double maxCashOut = 0.5 * amountInDollars;
        std::cout << "Вы можете обналичить до " << maxCashOut << " долларов\n";
    }
    else
    {
        std::cout << "Начисленная сумма в этом месяце составляет менее 500 долларов. Обналичивание невозможно\n";
    }

    return 0;
}
