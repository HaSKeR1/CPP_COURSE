#include "funclib.h"
#include <cstdlib>
#include <cctype>
#include <iostream>

int mystrcmp(const char* str1, const char* str2)
{
	if (*str1 == *str2) return 0;
	else if (*str1 > *str2) return 1;
	else return -1;
}

int StringToNumber(char* str)
{
	return atoi(str);
}

char* NumberToString(int number)
{
    char* ptrstr;
    if (!number)
    {
        ptrstr = new char[2];
        ptrstr[0] = '0';
        ptrstr[1] = '\0';

        return ptrstr;
    }
}

char* Uppercase(char* str1)
{
    char* original = str1;
    while (*str1) {
        *str1 = toupper(*str1);
        str1++;
    }
    return original;
}
char* Lowercase(char* str1)
{
    char* original = str1;
    while (*str1) {
        *str1 = std::tolower(*str1);
        str1++;
    }
    return original;
}

char* mystrrev(char* str)
{
    int len = std::strlen(str);
    for (int i = 0; i < len / 2; ++i) {
        std::swap(str[i], str[len - i - 1]);
    }
    return str;
}