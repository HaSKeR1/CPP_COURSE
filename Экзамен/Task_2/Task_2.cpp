#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <windows.h>

struct Song
{
    std::string title;
    std::string author;
    int year;
    std::string lyrics;
};

std::vector<Song> songCatalog;

void addSongFromKeyboard()
{
    Song song;
    std::cout << "Введите название песни: ";
    std::getline(std::cin, song.title);
    std::cout << "Введите автора песни: ";
    std::getline(std::cin, song.author);
    std::cout << "Введите год песни (0, если неизвестно): ";
    std::cin >> song.year;
    std::cin.ignore();
    std::cout << "Введите текст песни: ";
    std::getline(std::cin, song.lyrics);

    songCatalog.push_back(song);
}

void addSongFromFile()
{
    std::string filename;
    std::cout << "Введите название файла: ";
    std::cin >> filename;
    std::cin.ignore();

    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Не удалось открыть файл.\n";
        return;
    }

    Song song;
    std::getline(file, song.title);
    std::getline(file, song.author);
    file >> song.year;
    file.ignore();
    std::ostringstream lyricsStream;
    lyricsStream << file.rdbuf();
    song.lyrics = lyricsStream.str();

    songCatalog.push_back(song);
}

void deleteSong()
{
    std::string title;
    std::cout << "Введите название песни для удаления: ";
    std::getline(std::cin, title);

    for (auto it = songCatalog.begin(); it != songCatalog.end(); ++it)
    {
        if (it->title == title)
        {
            songCatalog.erase(it);
            std::cout << "Песня удалена.\n";
            return;
        }
    }
    std::cout << "Песня не найдена.\n";
}

void editSong()
{
    std::string title;
    std::cout << "Введите название песни для изменения: ";
    std::getline(std::cin, title);

    for (auto& song : songCatalog)
    {
        if (song.title == title)
        {
            std::cout << "Изменение песни: " << song.title << "\n";
            std::cout << "Введите нового автора: ";
            std::getline(std::cin, song.author);
            std::cout << "Введите новый год: ";
            std::cin >> song.year;
            std::cin.ignore();
            std::cout << "Введите новый текст: ";
            std::getline(std::cin, song.lyrics);
            std::cout << "Песня обновлена.\n";
            return;
        }
    }
    std::cout << "Песня не найдена.\n";
}

void displaySong()
{
    std::string title;
    std::cout << "Введите название песни для отображения: ";
    std::getline(std::cin, title);

    for (const auto& song : songCatalog)
    {
        if (song.title == title)
        {
            std::cout << "Название: " << song.title << "\n";
            std::cout << "Автор: " << song.author << "\n";
            std::cout << "Год: " << song.year << "\n";
            std::cout << "Текст:\n" << song.lyrics << "\n";
            return;
        }
    }
    std::cout << "Песня не найдена.\n";
}

void saveSongToFile()
{
    std::string title;
    std::cout << "Введите название песни для сохранения: ";
    std::getline(std::cin, title);

    for (const auto& song : songCatalog)
    {
        if (song.title == title)
        {
            std::string filename;
            std::cout << "Введите название файла: ";
            std::cin >> filename;
            std::cin.ignore();

            std::ofstream file(filename);
            if (!file.is_open())
            {
                std::cerr << "Не удалось открыть файл.\n";
                return;
            }

            file << song.title << "\n" << song.author << "\n" << song.year << "\n" << song.lyrics;
            std::cout << "Песня сохранена в файл.\n";
            return;
        }
    }
    std::cout << "Песня не найдена.\n";
}

void searchByAuthor()
{
    std::string author;
    std::cout << "Введите автора для поиска: ";
    std::getline(std::cin, author);

    for (const auto& song : songCatalog) {
        if (song.author == author) {
            std::cout << "Название: " << song.title << "\n";
            std::cout << "Автор: " << song.author << "\n";
            std::cout << "Год: " << song.year << "\n";
            std::cout << "Текст:\n" << song.lyrics << "\n\n";
        }
    }
}

void searchByKeyword()
{
    std::string keyword;
    std::cout << "Введите слово: ";
    std::getline(std::cin, keyword);

    for (const auto& song : songCatalog)
    {
        if (song.lyrics.find(keyword) != std::string::npos)
        {
            std::cout << "Название: " << song.title << "\n";
            std::cout << "Автор: " << song.author << "\n";
            std::cout << "Год: " << song.year << "\n";
            std::cout << "Текст:\n" << song.lyrics << "\n\n";
        }
    }
}

void showMenu()
{
    std::cout << "1. Добавить песню с клавиатуры\n";
    std::cout << "2. Добавить песню через файл\n";
    std::cout << "3. Удалить песню\n";
    std::cout << "4. Изменить песню\n";
    std::cout << "5. Отображение песни\n";
    std::cout << "6. Сохранить песню в файл\n";
    std::cout << "7. Искать по автору\n";
    std::cout << "8. Поиск по ключевому слову\n";
    std::cout << "9. Выход\n";
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int choice;
    while (true)
    {
        showMenu();
        std::cout << "Введите выбор: ";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice)
        {
        case 1:
            addSongFromKeyboard();
            break;
        case 2:
            addSongFromFile();
            break;
        case 3:
            deleteSong();
            break;
        case 4:
            editSong();
            break;
        case 5:
            displaySong();
            break;
        case 6:
            saveSongToFile();
            break;
        case 7:
            searchByAuthor();
            break;
        case 8:
            searchByKeyword();
            break;
        case 9:
            return 0;
        default:
            std::cout << "Ошибка!\n";
        }
    }

    return 0;
}
