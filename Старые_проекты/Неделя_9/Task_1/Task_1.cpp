#include <iostream>
#include <time.h>

int main()
{
    srand(time(NULL));

    int arr1[10], arr2[5], arr3[5];

    for (int i = 0; i < 10; i++)
    {
        arr1[i] = rand() % 41 - 20;
        std::cout << "arr1[" << i << "] = " << arr1[i] << std::endl;
    }
    std::cout << std::endl;

    for (int i = 0; i < 5; i++)
    {
        arr2[i] = arr1[i];
        std::cout << "arr2[" << i << "] = " << arr2[i] << std::endl;
    }
    std::cout << std::endl;

    for (int i = 0; i < 5; i++)
    {
        arr3[i] = arr1[i + 5];
        std::cout << "arr3[" << i << "] = " << arr3[i] << std::endl;
    }

    return 0;
}