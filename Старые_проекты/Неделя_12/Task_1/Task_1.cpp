#include <iostream>
#include <time.h>

int** createArr2D(int rows, int cols)
{
    int** mas = new int* [rows];
    for (int r = 0; r < rows; r++)
        mas[r] = new int[cols] {0};
    return mas;
}
double** createArr2Ddouble(double rows, double cols)
{
    double** mas = new double* [rows];
    for (int r = 0; r < rows; r++)
        mas[r] = new double[cols] {0};
    return mas;
}
char** createArr2Dchar(int rows, int cols)
{
    char** mas = new char* [rows];
    for (int r = 0; r < rows; r++)
        mas[r] = new char[cols] {0};
    return mas;
}
void SetRndArray2D(int** arr, int n, int m, int a = 1, int b = 9)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            arr[i][j] = a + rand() % (b - a + 1);
}
void SetRndArray2Ddouble(double** arr, int n, int m, int a = 1, int b = 9)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            arr[i][j] = a + rand() % (b - a + 1) / static_cast<double>(rand() % 10 + 1);
}
void SetRndArray2Dchar(char** arr, int n, int m)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            arr[i][j] = 97 + rand() % 26;
}
void PrintArray2D(int** arr, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            std::cout << arr[i][j] << "\t";
        std::cout << std::endl;
    }
}
void PrintArray2Ddouble(double** arr, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            std::cout << arr[i][j] << "\t";
        std::cout << std::endl;
    }
}
void PrintArray2Dchar(char** arr, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            std::cout << arr[i][j] << "\t";
        std::cout << std::endl;
    }
}
void SortingArray2D(int** arr, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m - 1; j++)
        {
            int index = j;
            int minElement = arr[i][j];
            for (int p = j; p < m; p++)
            {
                if (minElement > arr[i][p])
                {
                    index = p;
                    minElement = arr[i][p];
                }
            }
            std::swap(arr[i][j], arr[i][index]);
        }
    }
}
void SortingArray2Ddouble(double** arr, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m - 1; j++)
        {
            int index = j;
            double minElement = arr[i][j];
            for (int p = j; p < m; p++)
            {
                if (minElement > arr[i][p])
                {
                    index = p;
                    minElement = arr[i][p];
                }
            }
            std::swap(arr[i][j], arr[i][index]);
        }
    }
}
void SortingArray2Dchar(char** arr, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m - 1; j++)
        {
            int index = j;
            int minElement = arr[i][j];
            for (int p = j; p < m; p++)
            {
                if (minElement > arr[i][p])
                {
                    index = p;
                    minElement = arr[i][p];
                }
            }
            std::swap(arr[i][j], arr[i][index]);
        }
    }
}
int MinElOnTheMainDiagonalArray2D(int** arr, int n)
{
    int min = arr[0][0];
    for (int i = 1; i < n; i++)
        if (min > arr[i][i]) min = arr[i][i];
    return min;
}
double MinElOnTheMainDiagonalArray2Ddouble(double** arr, int n)
{
    double min = arr[0][0];
    for (int i = 1; i < n; i++)
        if (min > arr[i][i]) min = arr[i][i];
    return min;
}
char MinElOnTheMainDiagonalArray2Dchar(char** arr, int n)
{
    int min = arr[0][0];
    for (int i = 1; i < n; i++)
        if (min > arr[i][i]) min = arr[i][i];
    return min;
}
int MaxElOnTheMainDiagonalArray2D(int** arr, int n)
{
    int max = arr[0][0];
    for (int i = 1; i < n; i++)
        if (max < arr[i][i]) max = arr[i][i];
    return max;
}
double MaxElOnTheMainDiagonalArray2Ddouble(double** arr, int n)
{
    double max = arr[0][0];
    for (int i = 1; i < n; i++)
        if (max < arr[i][i]) max = arr[i][i];
    return max;
}
char MaxElOnTheMainDiagonalArray2Dchar(char** arr, int n)
{
    int max = arr[0][0];
    for (int i = 1; i < n; i++)
        if (max < arr[i][i]) max = arr[i][i];
    return max;
}
void DeleteArray2D(int** arr, int n)
{
    for (int i = 0; i < n; i++)
        delete[] arr[i];
    delete[] arr;
}
void DeleteArray2Ddouble(double** arr, int n)
{
    for (int i = 0; i < n; i++)
        delete[] arr[i];
    delete[] arr;
}
void DeleteArray2Dchar(char** arr, int n)
{
    for (int i = 0; i < n; i++)
        delete[] arr[i];
    delete[] arr;
}

int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(NULL));

    int n = 4, m = n;
    char** arr = createArr2Dchar(n, m);

    SetRndArray2Dchar(arr, n, m);

    std::cout << "Квадратная матрица:\n";
    PrintArray2Dchar(arr, n, m);

    SortingArray2Dchar(arr, n, m);

    std::cout << "Отсортированная матрица:\n";
    PrintArray2Dchar(arr, n, m);

    std::cout << "Минимальный элемент на главной диагонали матрицы: " << MinElOnTheMainDiagonalArray2Dchar(arr, n) << std::endl;
    std::cout << "Максимальный элемент на главной диагонали матрицы: " << MaxElOnTheMainDiagonalArray2Dchar(arr, n) << std::endl;

    DeleteArray2Dchar(arr, n);

    /*
    setlocale(LC_ALL, "rus");
    srand(time(NULL));

    int n = 4, m = n;
    double** arr = createArr2Ddouble(n, m);

    SetRndArray2Ddouble(arr, n, m);

    std::cout << "Квадратная матрица:\n";
    PrintArray2Ddouble(arr, n, m);

    SortingArray2Ddouble(arr, n, m);

    std::cout << "Отсортированная матрица:\n";
    PrintArray2Ddouble(arr, n, m);

    std::cout << "Минимальный элемент на главной диагонали матрицы: " << MinElOnTheMainDiagonalArray2Ddouble(arr, n) << std::endl;
    std::cout << "Максимальный элемент на главной диагонали матрицы: " << MaxElOnTheMainDiagonalArray2Ddouble(arr, n) << std::endl;

    DeleteArray2Ddouble(arr, n);
    */

    /*
    setlocale(LC_ALL, "rus");
    srand(time(NULL));

    int n = 4, m = n;
    int** arr = createArr2D(n, m);

    SetRndArray2D(arr, n, m);

    std::cout << "Квадратная матрица:\n";
    PrintArray2D(arr, n, m);

    SortingArray2D(arr, n, m);

    std::cout << "Отсортированная матрица:\n";
    PrintArray2D(arr, n, m);

    std::cout << "Минимальный элемент на главной диагонали матрицы: " << MinElOnTheMainDiagonalArray2D(arr, n) << std::endl;
    std::cout << "Максимальный элемент на главной диагонали матрицы: " << MaxElOnTheMainDiagonalArray2D(arr, n) << std::endl;

    DeleteArray2D(arr, n);
    */
}