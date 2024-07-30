#include <iostream>

int binarySearch(int arr[], int size, int key)
{
    int left = 0, right = size - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int array[] = { 10, 20, 30, 40, 50 };
    int size = sizeof(array) / sizeof(array[0]);
    int key = 30;
    int result = binarySearch(array, size, key);

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
