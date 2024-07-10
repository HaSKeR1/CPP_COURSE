#include <iostream>
#include <cstdlib>
#include <time.h>
#include <algorithm>

using namespace std;

void generateArray(int** array, int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            array[i][j] = rand() % 201 - 100;
        }
    }
}

int* flattenArray(int** array, int rows, int cols, int& size)
{
    size = rows * cols;
    int* result = new int[size];
    int index = 0;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            result[index++] = array[i][j];
        }
    }
    return result;
}

bool contains(int* array, int size, int value)
{
    for (int i = 0; i < size; ++i)
    {
        if (array[i] == value)
        {
            return true;
        }
    }
    return false;
}

int* getCommonValues(int* a, int sizeA, int* b, int sizeB, int* c, int sizeC, int& size)
{
    int* temp = new int[min(sizeA, min(sizeB, sizeC))];
    int index = 0;
    for (int i = 0; i < sizeA; ++i) {
        if (contains(b, sizeB, a[i]) && contains(c, sizeC, a[i]))
        {
            if (!contains(temp, index, a[i]))
            {
                temp[index++] = a[i];
            }
        }
    }
    size = index;
    int* common = new int[size];
    for (int i = 0; i < size; ++i)
    {
        common[i] = temp[i];
    }
    delete[] temp;
    return common;
}

int* getUniqueValues(int* a, int sizeA, int* b, int sizeB, int* c, int sizeC, int& size)
{
    int* temp = new int[sizeA + sizeB + sizeC];
    int index = 0;
    for (int i = 0; i < sizeA; ++i)
    {
        if (!contains(temp, index, a[i]))
        {
            temp[index++] = a[i];
        }
    }
    for (int i = 0; i < sizeB; ++i)
    {
        if (!contains(temp, index, b[i]))
        {
            temp[index++] = b[i];
        }
    }
    for (int i = 0; i < sizeC; ++i)
    {
        if (!contains(temp, index, c[i]))
        {
            temp[index++] = c[i];
        }
    }
    size = index;
    int* unique = new int[size];
    for (int i = 0; i < size; ++i)
    {
        unique[i] = temp[i];
    }
    delete[] temp;
    return unique;
}

int* getCommonValuesAC(int* a, int sizeA, int* c, int sizeC, int& size)
{
    int* temp = new int[min(sizeA, sizeC)];
    int index = 0;
    for (int i = 0; i < sizeA; ++i)
    {
        if (contains(c, sizeC, a[i]))
        {
            if (!contains(temp, index, a[i]))
            {
                temp[index++] = a[i];
            }
        }
    }
    size = index;
    int* common = new int[size];
    for (int i = 0; i < size; ++i)
    {
        common[i] = temp[i];
    }
    delete[] temp;
    return common;
}

int* getNegativeValues(int* a, int sizeA, int* b, int sizeB, int* c, int sizeC, int& size)
{
    int* temp = new int[sizeA + sizeB + sizeC];
    int index = 0;
    for (int i = 0; i < sizeA; ++i)
    {
        if (a[i] < 0 && !contains(temp, index, a[i]))
        {
            temp[index++] = a[i];
        }
    }
    for (int i = 0; i < sizeB; ++i)
    {
        if (b[i] < 0 && !contains(temp, index, b[i]))
        {
            temp[index++] = b[i];
        }
    }
    for (int i = 0; i < sizeC; ++i)
    {
        if (c[i] < 0 && !contains(temp, index, c[i]))
        {
            temp[index++] = c[i];
        }
    }
    size = index;
    int* negative = new int[size];
    for (int i = 0; i < size; ++i)
    {
        negative[i] = temp[i];
    }
    delete[] temp;
    return negative;
}

int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(NULL));

    int rowsA, colsA, rowsB, colsB, rowsC, colsC;
    cout << "Введите количество строк и столбцов для массива A: ";
    cin >> rowsA >> colsA;
    cout << "Введите количество строк и столбцов для массива B: ";
    cin >> rowsB >> colsB;
    cout << "Введите количество строк и столбцов для массива C: ";
    cin >> rowsC >> colsC;

    int** A = new int* [rowsA];
    int** B = new int* [rowsB];
    int** C = new int* [rowsC];

    for (int i = 0; i < rowsA; ++i) A[i] = new int[colsA];
    for (int i = 0; i < rowsB; ++i) B[i] = new int[colsB];
    for (int i = 0; i < rowsC; ++i) C[i] = new int[colsC];

    generateArray(A, rowsA, colsA);
    generateArray(B, rowsB, colsB);
    generateArray(C, rowsC, colsC);

    cout << "Массив A:" << endl;
    for (int i = 0; i < rowsA; ++i)
    {
        for (int j = 0; j < colsA; ++j)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Массив B:" << endl;
    for (int i = 0; i < rowsB; ++i)
    {
        for (int j = 0; j < colsB; ++j)
        {
            cout << B[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Массив C:" << endl;
    for (int i = 0; i < rowsC; ++i)
    {
        for (int j = 0; j < colsC; ++j)
        {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    int sizeA, sizeB, sizeC;
    int* flatA = flattenArray(A, rowsA, colsA, sizeA);
    int* flatB = flattenArray(B, rowsB, colsB, sizeB);
    int* flatC = flattenArray(C, rowsC, colsC, sizeC);

    int commonSizeABC, uniqueSizeABC, commonSizeAC, negativeSizeABC;
    int* commonABC = getCommonValues(flatA, sizeA, flatB, sizeB, flatC, sizeC, commonSizeABC);
    int* uniqueABC = getUniqueValues(flatA, sizeA, flatB, sizeB, flatC, sizeC, uniqueSizeABC);
    int* commonAC = getCommonValuesAC(flatA, sizeA, flatC, sizeC, commonSizeAC);
    int* negativeABC = getNegativeValues(flatA, sizeA, flatB, sizeB, flatC, sizeC, negativeSizeABC);

    cout << "Общие значения для A, B, C: ";
    for (int i = 0; i < commonSizeABC; ++i)
    {
        cout << commonABC[i] << " ";
    }
    cout << endl;

    cout << "Уникальные значения для A, B, C: ";
    for (int i = 0; i < uniqueSizeABC; ++i)
    {
        cout << uniqueABC[i] << " ";
    }
    cout << endl;

    cout << "Общие значения для A и C: ";
    for (int i = 0; i < commonSizeAC; ++i)
    {
        cout << commonAC[i] << " ";
    }
    cout << endl;

    cout << "Отрицательные значения для A, B, C без повторений: ";
    for (int i = 0; i < negativeSizeABC; ++i)
    {
        cout << negativeABC[i] << " ";
    }
    cout << endl;

    delete[] flatA;
    delete[] flatB;
    delete[] flatC;
    delete[] commonABC;
    delete[] uniqueABC;
    delete[] commonAC;
    delete[] negativeABC;
    for (int i = 0; i < rowsA; ++i) delete[] A[i];
    for (int i = 0; i < rowsB; ++i) delete[] B[i];
    for (int i = 0; i < rowsC; ++i) delete[] C[i];
    delete[] A;
    delete[] B;
    delete[] C;

    return 0;
}
