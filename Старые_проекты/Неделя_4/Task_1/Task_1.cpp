#include <iostream>

int main()
{
    int pizzaChoice, drinkChoice, pizzaAmount = 0, drinkAmount = 0, pizzaPrice, drinkPrice, pizzaAmount2, totalPriceWithoutDiscount;
    double totalPrice, drinkTotalPrice;
    setlocale(LC_ALL, "rus");

    // Выбор пиццы
    std::cout << "\n1 - Пепперони (17$)\n2 - Маргарита (16$)\n3 - Четыре сыра (19$)\n4 - Гавайская (15$)";
    std::cout << "\nВведите номер пиццы: ";
    std::cin >> pizzaChoice;

    // Выбор количества пицц
    switch (pizzaChoice)
    {
    case 1:
        std::cout << "\nВыбрана пицца 'Пепперони'";
        std::cout << "\nВведите количество пицц: ";
        std::cin >> pizzaAmount;
        pizzaPrice = 17;
        break;
    case 2:
        std::cout << "\nВыбрана пицца 'Маргарита'";
        std::cout << "\nВведите количество пицц: ";
        std::cin >> pizzaAmount;
        pizzaPrice = 16;
        break;
    case 3:
        std::cout << "\nВыбрана пицца 'Четыре сыра'";
        std::cout << "\nВведите количество пицц: ";
        std::cin >> pizzaAmount;
        pizzaPrice = 19;
        break;
    case 4:
        std::cout << "\nВыбрана пицца 'Гавайская'";
        std::cout << "\nВведите количество пицц: ";
        std::cin >> pizzaAmount;
        pizzaPrice = 15;
        break;
    default:
        std::cout << "\nОшибка!";
    }

    // Выбор напитка
    std::cout << "\n1 - Кола (3$)\n2 - Фанта (2$)\n3 - Сок(1$)";
    std::cout << "\nВведите номер напитка:";
    std::cin >> drinkChoice;

    // Выбор количества напитков
    switch (drinkChoice)
    {
    case 1:
        std::cout << "\nВыбран напиток 'Кола'";
        std::cout << "\nВведите количество напитков: ";
        std::cin >> drinkAmount;
        drinkPrice = 3;
        break;
    case 2:
        std::cout << "\nВыбран напиток 'Фанта'";
        std::cout << "\nВведите количество напитков: ";
        std::cin >> drinkAmount;
        drinkPrice = 2;
        break;
    case 3:
        std::cout << "\nВыбран напиток 'Сок'";
        std::cout << "\nВведите количество напитков: ";
        std::cin >> drinkAmount;
        drinkPrice = 1;
        break;
    default:
        std::cout << "Ошибка!";
    }


    drinkTotalPrice = drinkAmount * drinkPrice;
    totalPriceWithoutDiscount = pizzaAmount * pizzaPrice + drinkAmount * drinkPrice;

    // Если напиток стоит больше 2$ и их больше 3, то 15% на напитки
    if (drinkPrice >= 2 and drinkAmount >= 3)
    {
        drinkTotalPrice = drinkTotalPrice - drinkTotalPrice * 0.15;
    }

    // Общая цена 
    totalPrice = pizzaAmount * pizzaPrice + drinkTotalPrice;

    // Если сумма заказа больше 50$, то -20%
    if (totalPrice >= 50)
    {
        totalPrice = totalPrice - totalPrice * 0.2;
    }


    // Пятая пицца - бесплатно
    pizzaAmount2 = pizzaAmount;
    while (pizzaAmount2 > 5)
    {
        totalPrice = totalPrice - pizzaPrice;
        pizzaAmount2 = pizzaAmount2 - 5;
    }

    // "Чек"
    std::cout << "\n\n       ЧЕК";

    // Вывод про пиццу
    switch (pizzaChoice)
    {
    case 1:
        std::cout << "\nПепперони - " << pizzaAmount << "шт - " << pizzaPrice << "$";
        break;
    case 2:
        std::cout << "\nМаргарита - " << pizzaAmount << "шт - " << pizzaPrice << "$";
        break;
    case 3:
        std::cout << "\nЧетыре сыра - " << pizzaAmount << "шт - " << pizzaPrice << "$";
        break;
    case 4:
        std::cout << "\nГавайская - " << pizzaAmount << "шт - " << pizzaPrice << "$";
        break;
    }

    //Вывод про напитки
    switch (drinkChoice)
    {
    case 1:
        std::cout << "\nКола - " << drinkAmount << "шт - " << drinkPrice << "$";
        break;
    case 2:
        std::cout << "\nФанта - " << drinkAmount << "шт - " << drinkPrice << "$";
        break;
    case 3:
        std::cout << "\nСок - " << drinkAmount << "шт - " << drinkPrice << "$";
        break;
    }

    // Итого
    std::cout << "\n\nЦена без скидки: " << totalPriceWithoutDiscount;
    std::cout << "\nЦена со скидкой: " << totalPrice;
}