#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

// Функция для поиска и замены слова в строке
void findAndReplace(char* text, const char* oldWord, const char* newWord) {
    char buffer[1024];
    char* pos;

    // Начальное положение в тексте
    pos = strstr(text, oldWord);

    while (pos != NULL) {
        // Создаем новую строку с заменой
        int len = pos - text;
        strncpy(buffer, text, len);
        buffer[len] = '\0';

        strcat(buffer, newWord);
        strcat(buffer, pos + strlen(oldWord));

        strcpy(text, buffer);

        pos = strstr(text, oldWord);
    }
}

// Функция для изменения текста так, чтобы каждое предложение начиналось с большой буквы
void capitalizeSentences(char* text) {
    int capitalize = 1;

    for (int i = 0; text[i] != '\0'; ++i) {
        if (capitalize && isalpha((unsigned char)text[i])) {
            text[i] = toupper((unsigned char)text[i]);
            capitalize = 0;
        }

        if (text[i] == '.' || text[i] == '!' || text[i] == '?') {
            capitalize = 1;
        }
    }
}

// Функция для подсчета частоты каждой буквы в тексте
void countLetters(const char* text, int* count) {
    for (int i = 0; text[i] != '\0'; ++i) {
        if (isalpha((unsigned char)text[i])) {
            count[tolower((unsigned char)text[i]) - 'a']++;
        }
    }
}

// Функция для подсчета количества цифр в тексте
int countDigits(const char* text) {
    int count = 0;

    for (int i = 0; text[i] != '\0'; ++i) {
        if (isdigit((unsigned char)text[i])) {
            count++;
        }
    }

    return count;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    char text[1024] = "это пример текста. он содержит несколько предложений. как и цифры 1234.";
    char oldWord[50], newWord[50];

    // Заменить слово
    printf("Введите слово для замены: ");
    scanf("%s", oldWord);
    printf("Введите новое слово: ");
    scanf("%s", newWord);
    findAndReplace(text, oldWord, newWord);
    printf("Текст после замены слова: %s\n", text);

    // Капитализация предложений
    capitalizeSentences(text);
    printf("Текст после капитализации предложений: %s\n", text);

    // Подсчет букв
    int letterCount[26] = { 0 };
    countLetters(text, letterCount);
    printf("Частота букв:\n");
    for (int i = 0; i < 26; ++i) {
        if (letterCount[i] > 0) {
            printf("%c: %d\n", 'a' + i, letterCount[i]);
        }
    }

    // Подсчет цифр
    int digitCount = countDigits(text);
    printf("Количество цифр в тексте: %d\n", digitCount);

    return 0;
}
