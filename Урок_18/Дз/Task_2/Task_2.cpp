#include <iostream>
#include <string>
#include <windows.h>

void printContacts(std::string** contacts, int size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << "Имя: " << contacts[i][0] << ", Телефон: " << contacts[i][1] << std::endl;
    }
}

void searchByName(std::string** contacts, int size, const std::string& name)
{
    for (int i = 0; i < size; ++i)
    {
        if (contacts[i][0] == name)
        {
            std::cout << "Найден контакт: Имя: " << contacts[i][0] << ", Телефон: " << contacts[i][1] << std::endl;
            return;
        }
    }
    std::cout << "Контакт с именем " << name << " не найден." << std::endl;
}

void searchByPhone(std::string** contacts, int size, const std::string& phone)
{
    for (int i = 0; i < size; ++i)
    {
        if (contacts[i][1] == phone)
        {
            std::cout << "Найден контакт: Имя: " << contacts[i][0] << ", Телефон: " << contacts[i][1] << std::endl;
            return;
        }
    }
    std::cout << "Контакт с номером телефона " << phone << " не найден." << std::endl;
}

void addContact(std::string**& contacts, int& size, const std::string& name, const std::string& phone)
{
    std::string** newContacts = new std::string * [size + 1];
    for (int i = 0; i < size; ++i)
    {
        newContacts[i] = contacts[i];
    }
    newContacts[size] = new std::string[2];
    newContacts[size][0] = name;
    newContacts[size][1] = phone;
    delete[] contacts;
    contacts = newContacts;
    size++;
}

void updateContact(std::string** contacts, int size, const std::string& name, const std::string& newPhone)
{
    for (int i = 0; i < size; ++i)
    {
        if (contacts[i][0] == name)
        {
            contacts[i][1] = newPhone;
            std::cout << "Телефон для контакта " << name << " обновлен на " << newPhone << std::endl;
            return;
        }
    }
    std::cout << "Контакт с именем " << name << " не найден." << std::endl;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int size = 0;
    std::string** contacts = new std::string * [size];

    int choice;
    std::string name, phone;

    do
    {
        std::cout << "Меню:\n1. Показать все контакты\n2. Найти контакт по имени\n3. Найти контакт по телефону\n4. Добавить контакт\n5. Изменить контакт\n6. Выход\n";
        std::cout << "Выберите опцию: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            printContacts(contacts, size);
            break;
        case 2:
            std::cout << "Введите имя: ";
            std::cin >> name;
            searchByName(contacts, size, name);
            break;
        case 3:
            std::cout << "Введите номер телефона: ";
            std::cin >> phone;
            searchByPhone(contacts, size, phone);
            break;
        case 4:
            std::cout << "Введите имя: ";
            std::cin >> name;
            std::cout << "Введите номер телефона: ";
            std::cin >> phone;
            addContact(contacts, size, name, phone);
            break;
        case 5:
            std::cout << "Введите имя: ";
            std::cin >> name;
            std::cout << "Введите новый номер телефона: ";
            std::cin >> phone;
            updateContact(contacts, size, name, phone);
            break;
        case 6:
            std::cout << "Выход из программы.\n";
            break;
        default:
            std::cout << "Неверный выбор. Попробуйте снова.\n";
        }
    } while (choice != 6);

    for (int i = 0; i < size; ++i)
    {
        delete[] contacts[i];
    }
    delete[] contacts;

    return 0;
}
