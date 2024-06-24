#include <iostream>
#include <sstream>
#include <string>
#include <windows.h>
using namespace std; // убрать

enum class Dollar {доллар, долларов, доллара};

/*
* Почитать про Enum, перенсти "доллар", "рубли" в enum
* Почитать про map для отображения ключа на значение, подумать, что у нас будет в данной программе ключом, а что значением
*/

void ExchangeToEuros(int amount, string value)
{ 
    double answer;

    if (value == "евро")
    {
        answer = amount;
        cout << amount << " " << value << " - " << answer << " евро" << endl;
    }
    else if (value == "доллар" || value == "долларов" || value == "доллара") // or == ||, and == &&
    { 
        answer = amount * 0.9406;
        cout << amount << " " << value << " - " << answer << " евро" << endl;
    }
    else if (value == "юань" || value == "юаней" || value == "юаня")
    {
        answer = amount * 0.1296;
        cout << amount << " " << value << " - " << answer << " евро" << endl;
    }
    else if (value == "рубль" || value == "рублей" || value == "рубля")
    {
        answer = amount * 0.01;
        cout << amount << " " << value << " - " << answer << " евро" << endl;
    }
    else if (value == "лир" || value == "лира")
    {
        answer = amount * 0.029;
        cout << amount << " " << value << " - " << answer << " евро" << endl;
    }
    else
    {
        cout << "Ошибка" << endl;
    }
}
void ExchangeToDollars(int amount, string value)
{
    double answer;
    if (value == "евро")
    {
        answer = amount * 1.0631;
        cout << amount << " " << value << " - " << answer << " долларов" << endl;
    }
    else if (value == "доллар" || value == "долларов" || value == "доллара")
    {
        answer = amount;
        cout << amount << " " << value << " - " << answer << " долларов" << endl;
    }
    else if (value == "юань" || value == "юаней" || value == "юаня")
    {
        answer = amount * 0.14;
        cout << amount << " " << value << " - " << answer << " долларов" << endl;
    }
    else if (value == "рубль" || value == "рублей" || value == "рубля")
    {
        answer = amount * 0.0106;
        cout << amount << " " << value << " - " << answer << " долларов" << endl;
    }
    else if (value == "лир" || value == "лира")
    {
        answer = amount * 0.0308;
        cout << amount << " " << value << " - " << answer << " долларов" << endl;
    }
    else
    {
        cout << "Ошибка" << endl;
    }
}
void ExchangeToYuans(int amount, string value)
{
    double answer;
    if (value == "евро")
    {
        answer = amount * 7.71;
        cout << amount << " " << value << " - " << answer << " юаней" << endl;
    }
    else if (value == "доллар" || value == "долларов" || value == "доллара")
    {
        answer = amount * 7.24;
        cout << amount << " " << value << " - " << answer << " юаней" << endl;
    }
    else if (value == "юань" || value == "юаней" || value == "юаня")
    {
        answer = amount;
        cout << amount << " " << value << " - " << answer << " юаней" << endl;
    }
    else if (value == "рубль" || value == "рублей" || value == "рубля")
    {
        answer = amount * 0.077;
        cout << amount << " " << value << " - " << answer << " юаней" << endl;
    }
    else if (value == "лир" || value == "лира")
    {
        answer = amount * 0, 22;
        cout << amount << " " << value << " - " << answer << " юаней" << endl;
    }
    else
    {
        cout << "Ошибка" << endl;
    }
}
void ExchangeToRubles(int amount, string value)
{
    double answer;
    if (value == "евро")
    {
        answer = amount * 100.2787;
        cout << amount << " " << value << " - " << answer << " рублей" << endl;
    }
    else if (value == "доллар" || value == "долларов" || value == "доллара")
    {
        answer = amount * 100.2787;
        cout << amount << " " << value << " - " << answer << " рублей" << endl;
    }
    else if (value == "юань" || value == "юаней" || value == "юаня")
    {
        answer = amount * 13.01;
        cout << amount << " " << value << " - " << answer << " рублей" << endl;
    }
    else if (value == "рубль" || value == "рублей" || value == "рубля")
    {
        answer = amount;
        cout << amount << " " << value << " - " << answer << " рублей" << endl;
    }
    else if (value == "лир" || value == "лира")
    {
        answer = amount * 2.9082;
        cout << amount << " " << value << " - " << answer << " рублей" << endl;
    }
    else
    {
        cout << "Ошибка" << endl;
    }
}
void ExchangeToLiras(int amount, string value)
{
    double answer;
    if (value == "евро")
    {
        answer = amount * 34.4816;
        cout << amount << " " << value << " - " << answer << " лир" << endl;
    }
    else if (value == "доллар" || value == "долларов" || value == "доллара")
    {
        answer = amount * 32.4341;
        cout << amount << " " << value << " - " << answer << " лир" << endl;
    }
    else if (value == "юань" || value == "юаней" || value == "юаня")
    {
        answer = amount * 4.49;
        cout << amount << " " << value << " - " << answer << " лир" << endl;
    }
    else if (value == "рубль" || value == "рублей" || value == "рубля")
    {
        answer = amount * 0.3439;
        cout << amount << " " << value << " - " << answer << " лир" << endl;
    }
    else if (value == "лир" || value == "лира")
    {
        answer = amount;
        cout << amount << " " << value << " - " << answer << " лир" << endl;
        cout << "------------------------------------";
    }
    else
    {
        cout << "Ошибка" << endl;
    }
}

void EnterValue(int amount, string value)
{
    string input;

    cout << "Введите сумму и валюту, которую необходимо перевести(например, 100 рублей):\n";
    cin.ignore();
    getline(cin, input);
    stringstream ss(input);
    ss >> amount;
    ss >> value;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, ".1251");

    string value;
    int amount, choice = 0;

    cout << "Курсы валют:\n";
    cout << "1 евро - 100,33 рублей.\n1 доллар - 94,15 рубля.\n1 юань - 13,28 рублей.\n1 лира - 2,9 рублей.\n\n";

    while (choice != 6)
    {
        cout << "В какую валюту хотите перевести: 1 – евро, 2 – доллар, 3 – юани, 4 – рубли, 5 – лиры, 6 – выход.\n";
        cin >> choice;
        if (choice == 1)
        {
            EnterValue(amount, value);

            ExchangeToEuros(amount, value);
        }
        else if (choice == 2)
        {
            EnterValue(amount, value);

            ExchangeToDollars(amount, value);
        }
        else if (choice == 3)
        {
            EnterValue(amount, value);

            ExchangeToYuans(amount, value);
        }
        else if (choice == 4)
        {
            EnterValue(amount, value);

            ExchangeToRubles(amount, value);
        }
        else if (choice == 5)
        {
            EnterValue(amount, value);

            ExchangeToLiras(amount, value);
        }
    }
    return 0;
}