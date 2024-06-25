#include <iostream>

int main()
{
    setlocale(LC_ALL, "rus");
    const int size = 5;
    int arr1[size];
    int arr2[size];
    int arrs[size];

    std::cout << "Первый массив: \n";

    for (int i = 0; i < size; i++)
    {
        arr1[i] = rand() % 41 - 20;
        std::cout << "arr1[" << i << "] = " << arr1[i] << std::endl;
    }

    std::cout << "\nВторой массив: \n";

    for (int i = 0; i < size; i++)
    {
        arr2[i] = rand() % 41 - 20;
        std::cout << "arr2[" << i << "] = " << arr2[i] << std::endl;
    }

    std::cout << "\nТретий массив:\n";

    for (int i = 0; i < size; i++)
    {
        arrs[i] = arr1[i] + arr2[i];
        std::cout << "arr3[" << i << "] = ";
        std::cout << arrs[i] << "\n";
    }
}