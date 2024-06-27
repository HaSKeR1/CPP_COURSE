#include <iostream>
#include <sstream>
#include <windows.h>
#include <map>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::map<std::string, double> fromEUR, fromUSD, fromCNY, fromRUB, fromTRY;

    // Курс валют
    fromEUR["toUSD"] = 1.07, fromEUR["toCNY"] = 7.78, fromEUR["toRUB"] = 94.11, fromEUR["toTRY"] = 35.17;
    fromUSD["toEUR"] = 0.93413, fromUSD["toCNY"] = 7.27, fromUSD["toRUB"] = 87.81, fromUSD["toTRY"] = 32.85;
    fromCNY["toEUR"] = 0.12856, fromCNY["toUSD"] = 0.137625, fromCNY["toRUB"] = 11.87, fromCNY["toTRY"] = 4.52;
    fromRUB["toEUR"] = 0.010625, fromRUB["toUSD"] = 0.010625, fromRUB["toCNY"] = 0.084212, fromRUB["toTRY"] = 0.375043;
    fromTRY["toEUR"] = 0.028435, fromTRY["toUSD"] = 0.03044, fromTRY["toCNY"] = 0.22118, fromTRY["toRUB"] = 2.67;

    enum class Currencies { Euro, Dollar, Yuan, Ruble, Lira };

    double amount, convertedValue;
    int choice = 0;
    std::string input, fromCurrencyStr;
    Currencies fromCurrency, toCurrency;

    // Вывод курса валют
    std::cout << "1 рубль = " << fromRUB["toEUR"] << " евро, " << fromRUB["toUSD"] << " доллар, " << fromRUB["toCNY"] << " юаней, " << fromRUB["toTRY"] << " лир\n";
    std::cout << "1 евро = " << fromEUR["toRUB"] << " рублей, " << fromEUR["toUSD"] << " доллар, " << fromEUR["toCNY"] << " юаней, " << fromEUR["toTRY"] << " лир\n";
    std::cout << "1 доллар = " << fromUSD["toRUB"] << " рублей, " << fromUSD["toEUR"] << " евро, " << fromUSD["toCNY"] << " юаней, " << fromUSD["toTRY"] << " лир\n";
    std::cout << "1 юань = " << fromCNY["toRUB"] << " рублей, " << fromCNY["toEUR"] << " евро, " << fromCNY["toUSD"] << " доллар, " << fromCNY["toTRY"] << " лир\n";
    std::cout << "1 турецкая лира = " << fromTRY["toRUB"] << " рублей, " << fromTRY["toEUR"] << " евро, " << fromTRY["toUSD"] << " доллар, " << fromTRY["toCNY"] << " юаней\n\n";

    while (choice != 6)
    {
        // Выбор, в какую валюту перевести
        std::cout << "В какую валюту хотите перевести: 1 – евро, 2 – доллар, 3 – юани, 4 – рубли, 5 – лира, 6 – выход.\n";
        std::cin >> choice;

        switch (choice)
        {
        case 1: toCurrency = Currencies::Euro; break;
        case 2: toCurrency = Currencies::Dollar; break;
        case 3: toCurrency = Currencies::Yuan; break;
        case 4: toCurrency = Currencies::Ruble; break;
        case 5: toCurrency = Currencies::Lira; break;
        case 6: std::cout << "До свидания!\n"; break;
        default: std::cout << "Ошибка!\n\n"; continue;
        }
        // Ввод суммы и валюты, которую необходимо перевести
        std::cout << "Введите сумму и валюту, которую необходимо перевести, например 100 рублей:\n";
        std::cin.ignore();
        getline(std::cin, input);

        std::stringstream ss(input);
        ss >> amount >> fromCurrencyStr;

        if (fromCurrencyStr == "евро") fromCurrency = Currencies::Euro;
        else if (fromCurrencyStr == "доллар" || fromCurrencyStr == "доллара" || fromCurrencyStr == "долларов") fromCurrency = Currencies::Dollar;
        else if (fromCurrencyStr == "юань" || fromCurrencyStr == "юаня" || fromCurrencyStr == "юаней") fromCurrency = Currencies::Yuan;
        else if (fromCurrencyStr == "рубль" || fromCurrencyStr == "рубля" || fromCurrencyStr == "рублей") fromCurrency = Currencies::Ruble;
        else if (fromCurrencyStr == "лира" || fromCurrencyStr == "лиры" || fromCurrencyStr == "лир") fromCurrency = Currencies::Lira;
        else
        {
            std::cout << "Ошибка!\n";
            continue;
        }

        // Расчёт и вывод
        switch (fromCurrency)
        {
        case Currencies::Euro:
            switch (toCurrency)
            {
            case Currencies::Dollar: convertedValue = amount * fromEUR["toUSD"]; std::cout << amount << " евро = " << convertedValue << " долларов\n\n"; break;
            case Currencies::Yuan: convertedValue = amount * fromEUR["toCNY"]; std::cout << amount << " евро = " << convertedValue << " юаней\n\n"; break;
            case Currencies::Ruble: convertedValue = amount * fromEUR["toRUB"]; std::cout << amount << " евро = " << convertedValue << " рублей\n\n"; break;
            case Currencies::Lira: convertedValue = amount * fromEUR["toTRY"]; std::cout << amount << " евро = " << convertedValue << " лир\n\n"; break;
            }
            break;
        case Currencies::Dollar:
            switch (toCurrency)
            {
            case Currencies::Euro: convertedValue = amount * fromUSD["toEUR"]; std::cout << amount << " долларов = " << convertedValue << " евро\n\n"; break;
            case Currencies::Yuan: convertedValue = amount * fromUSD["toCNY"]; std::cout << amount << " долларов = " << convertedValue << " юаней\n\n"; break;
            case Currencies::Ruble: convertedValue = amount * fromUSD["toRUB"]; std::cout << amount << " долларов = " << convertedValue << " рублей\n\n"; break;
            case Currencies::Lira: convertedValue = amount * fromUSD["toTRY"]; std::cout << amount << " долларов = " << convertedValue << " лир\n\n"; break;
            }
            break;
        case Currencies::Yuan:
            switch (toCurrency)
            {
            case Currencies::Euro: convertedValue = amount * fromCNY["toEUR"]; std::cout << amount << " юаней = " << convertedValue << " евро\n\n"; break;
            case Currencies::Dollar: convertedValue = amount * fromCNY["toUSD"]; std::cout << amount << " юаней = " << convertedValue << " долларов\n\n"; break;
            case Currencies::Ruble: convertedValue = amount * fromCNY["toRUB"]; std::cout << amount << " юаней = " << convertedValue << " рублей\n\n"; break;
            case Currencies::Lira: convertedValue = amount * fromCNY["toTRY"]; std::cout << amount << " юаней = " << convertedValue << " лир\n\n"; break;
            }
            break;
        case Currencies::Ruble:
            switch (toCurrency)
            {
            case Currencies::Euro: convertedValue = amount * fromRUB["toEUR"]; std::cout << amount << " рублей = " << convertedValue << " евро\n\n"; break;
            case Currencies::Dollar: convertedValue = amount * fromRUB["toUSD"]; std::cout << amount << " рублей = " << convertedValue << " долларов\n\n"; break;
            case Currencies::Yuan: convertedValue = amount * fromRUB["toCNY"]; std::cout << amount << " рублей = " << convertedValue << " юаней\n\n"; break;
            case Currencies::Lira: convertedValue = amount * fromRUB["toTRY"]; std::cout << amount << " рублей = " << convertedValue << " лир\n\n"; break;
            }
            break;
        case Currencies::Lira:
            switch (toCurrency)
            {
            case Currencies::Euro: convertedValue = amount * fromTRY["toEUR"]; std::cout << amount << " лир = " << convertedValue << " евро\n\n"; break;
            case Currencies::Dollar: convertedValue = amount * fromTRY["toUSD"]; std::cout << amount << " лир = " << convertedValue << " долларов\n\n"; break;
            case Currencies::Yuan: convertedValue = amount * fromTRY["toCNY"]; std::cout << amount << " лир = " << convertedValue << " юаней\n\n"; break;
            case Currencies::Ruble: convertedValue = amount * fromTRY["toRUB"]; std::cout << amount << " лир = " << convertedValue << " рублей\n\n"; break;
            }
            break;
        }
    }
    return 0;
}
