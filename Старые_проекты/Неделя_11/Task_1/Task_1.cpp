#include <iostream>

int linearSearch(int arr[], int size, int key)
{
    for (int i = 0; i < size; ++i)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    setlocale(LC_ALL, "rus");
    int array[] = { 10, 20, 30, 40, 50 };
    int size = sizeof(array) / sizeof(array[0]);
    int key = 30;

    int result = linearSearch(array, size, key);

    if (result != -1)
    {
        std::cout << "Элемент найден на индексе: " << result << std::endl;
    }
    else
    {
        std::cout << "Элемент не найден" << std::endl;
    }

    return 0;
}
