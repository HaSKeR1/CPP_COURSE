#include <iostream>
#include <string>
#include <algorithm>
#include <windows.h>

struct Book
{
    std::string title;
    std::string author;
    std::string publisher;
    std::string genre;
};

const int NUM_BOOKS = 10;
Book library[NUM_BOOKS];

void editBook(Book& book)
{
    std::cout << "Изменение книги: " << book.title << std::endl;
    std::cout << "Введите новое название: ";
    std::cin.ignore();
    std::getline(std::cin, book.title);
    std::cout << "Введите нового автора: ";
    std::getline(std::cin, book.author);
    std::cout << "Ввеедите нового издателя: ";
    std::getline(std::cin, book.publisher);
    std::cout << "Введите новый жанр: ";
    std::getline(std::cin, book.genre);
}

void printAllBooks()
{
    for (int i = 0; i < NUM_BOOKS; ++i)
    {
        std::cout << "Книга " << i + 1 << ":" << std::endl;
        std::cout << "Название: " << library[i].title << std::endl;
        std::cout << "Автор: " << library[i].author << std::endl;
        std::cout << "PИздатель: " << library[i].publisher << std::endl;
        std::cout << "Жанр: " << library[i].genre << std::endl;
        std::cout << std::endl;
    }
}

void searchBooksByAuthor(const std::string& author)
{
    for (int i = 0; i < NUM_BOOKS; ++i)
    {
        if (library[i].author == author)
        {
            std::cout << "Название: " << library[i].title << std::endl;
            std::cout << "Автор: " << library[i].author << std::endl;
            std::cout << "Издатель: " << library[i].publisher << std::endl;
            std::cout << "Жанр: " << library[i].genre << std::endl;
            std::cout << std::endl;
        }
    }
}

void searchBookByTitle(const std::string& title)
{
    for (int i = 0; i < NUM_BOOKS; ++i)
    {
        if (library[i].title == title)
        {
            std::cout << "Название: " << library[i].title << std::endl;
            std::cout << "Автор: " << library[i].author << std::endl;
            std::cout << "Издатель: " << library[i].publisher << std::endl;
            std::cout << "Жанр: " << library[i].genre << std::endl;
            std::cout << std::endl;
            return;
        }
    }
    std::cout << "Книга не найдена." << std::endl;
}

void sortBooksByTitle()
{
    std::sort(library, library + NUM_BOOKS, [](const Book& a, const Book& b)
        {
        return a.title < b.title;
        });
}

void sortBooksByAuthor()
{
    std::sort(library, library + NUM_BOOKS, [](const Book& a, const Book& b)
        {
        return a.author < b.author;
        });
}

void sortBooksByPublisher()
{
    std::sort(library, library + NUM_BOOKS, [](const Book& a, const Book& b)
        {
        return a.publisher < b.publisher;
        });
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::string author, title;
    int choice;
    library[0] = { "Книга1", "Автор1", "Издатель1", "Жанр1" };
    library[1] = { "Книга2", "Автор2", "Издатель2", "Жанр2" };
    library[2] = { "Книга3", "Автор3", "Издатель3", "Жанр3" };
    library[3] = { "Книга4", "Автор4", "Издатель4", "Жанр4" };
    library[4] = { "Книга5", "Автор5", "Издатель5", "Жанр5" };
    library[5] = { "Книга6", "Автор6", "Издатель6", "Жанр6" };
    library[6] = { "Книга7", "Автор7", "Издатель7", "Жанр7" };
    library[7] = { "Книга8", "Автор8", "Издатель8", "Жанр8" };
    library[8] = { "Книга9", "Автор9", "Издатель9", "Жанр9" };
    library[9] = { "Книга10", "Автор10", "Издатель10", "Жанр10" };

    do
    {
        std::cout << "Меню библиотеки:\n";
        std::cout << "1. Изменить книгу\n";
        std::cout << "2. Печать всех книг\n";
        std::cout << "3. Поиск книг по автору\n";
        std::cout << "4. Поиск книг по названиюe\n";
        std::cout << "5. Сортировать книги по названию\n";
        std::cout << "6. Сортировать книги по автору\n";
        std::cout << "7. Сортировать книги по издателю\n";
        std::cout << "8. Выход\n";
        std::cout << "Введите номер: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            int bookNumber;
            std::cout << "Введите номер книги для изменения (1-10): ";
            std::cin >> bookNumber;
            if (bookNumber >= 1 && bookNumber <= 10)
            {
                editBook(library[bookNumber - 1]);
            }
            else
            {
                std::cout << "Некорректный номер книги!\n";
            }
            break;
        case 2:
            printAllBooks();
            break;
        case 3:
            std::cout << "Введите автора для поиска: ";
            std::cin.ignore();
            std::getline(std::cin, author);
            searchBooksByAuthor(author);
            break;
        case 4:
            std::cout << "Введите название для поиска: ";
            std::cin.ignore();
            std::getline(std::cin, title);
            searchBookByTitle(title);
            break;
        case 5:
            sortBooksByTitle();
            std::cout << "BКниги отсортированы по названию." << std::endl;
            break;
        case 6:
            sortBooksByAuthor();
            std::cout << "Книги отсортированы по автору." << std::endl;
            break;
        case 7:
            sortBooksByPublisher();
            std::cout << "Книги отсортированы по издателю.\n";
            break;
        case 8:
            std::cout << "Выход...\n";
            break;
        default:
            std::cout << "Неверный выбор! Пожалуйста, попробуйте снова.\n";
            break;
        }
    } while (choice != 8);

    return 0;
}
