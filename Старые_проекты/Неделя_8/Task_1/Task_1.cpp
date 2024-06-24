#include <iostream>
#include <random>
#include <time.h>

int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(NULL));

    int arr[10];

    for (int i = 0; i < 10; i++)
    {
        arr[i] = rand();
        std::cout << arr[i] << " ";
    }

    int max = arr[0];
    int min = arr[0];

    for (int i = 0; i < 10; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }

    std::cout << std::endl << "Максимальный: " << max << std::endl << "Минимальный: " << min;

    return 0;
}
