#include <iostream>

double maxFunc(const double* arr, int size)
{
    double maxVal = arr[0];
    for (int i = 1; i < size; ++i)
    {
        if (arr[i] > maxVal)
        {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

double minFunc(const double* arr, int size)
{
    double minVal = arr[0];
    for (int i = 1; i < size; ++i)
    {
        if (arr[i] < minVal)
        {
            minVal = arr[i];
        }
    }
    return minVal;
}

double avgFunc(const double* arr, int size)
{
    double sum = 0;
    for (int i = 0; i < size; ++i)
    {
        sum += arr[i];
    }
    return sum / size;
}

double Action(const double* arrA, const double* arrB, int sizeA, int sizeB, double(*func)(const double*, int))
{
    double resultA = func(arrA, sizeA);
    double resultB = func(arrB, sizeB);
    return (resultA + resultB) / 2;
}

int main()
{

    setlocale(LC_ALL, "rus");
    int choice;
    const int sizeA = 5;
    const int sizeB = 5;
    double arrA[sizeA] = { 1, 2, 3, 4, 5 };
    double arrB[sizeB] = { 6, 7, 8, 9, 10 };

    std::cout << "Выберите действие:\n";
    std::cout << "1 - Найти максимум\n";
    std::cout << "2 - Найти минимум\n";
    std::cout << "3 - Найти среднее\n";
    std::cin >> choice;

    double(*selectedFunc)(const double*, int) = nullptr;

    switch (choice) {
    case 1: selectedFunc = maxFunc; break;
    case 2: selectedFunc = minFunc; break;
    case 3: selectedFunc = avgFunc; break;
    default:
        std::cout << "Неверный выбор!\n";
        return 1;
    }

    double result = Action(arrA, arrB, sizeA, sizeB, selectedFunc);
    std::cout << "Результат: " << result << std::endl;

    return 0;
}
