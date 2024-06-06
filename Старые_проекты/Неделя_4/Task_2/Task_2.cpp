#include <iostream>

int main()
{
	setlocale(LC_ALL, "rus");
	int firstSales, secondSales, thirdSales, bestManager;
	double firstSalary, secondSalary, thirdSalary;
	
	// Ввод количества продаж менеджеров
	std::cout << "Введите количество продаж первого менеджера: ";
	std::cin >> firstSales;
	std::cout << "Введите количество продаж второго менеджера: ";
	std::cin >> secondSales;
	std::cout << "Введите количество продаж третьего менеджера: ";
	std::cin >> thirdSales;

	// Уровень продаж первого менеджера
	if (firstSales < 500)
	{
		firstSalary = 200 + 0.03 * firstSales;
	}
	else if (firstSales >= 500 and firstSales < 1000)
	{
		firstSalary = 200 + 0.05 * firstSales;
	}
	else if (firstSales >= 1000)
	{
		firstSalary = 200 + 0.08 * firstSales;
	}

	// Уровень продаж второго менеджера
	if (secondSales < 500)
	{
		secondSalary = 200 + 0.03 * secondSales;
	}
	else if (secondSales >= 500 and secondSales < 1000)
	{
		secondSalary = 200 + 0.05 * secondSales;
	}
	else if (secondSales >= 1000)
	{
		secondSalary = 200 + 0.08 * secondSales;
	}

	// Уровень продаж третьего менеджера
	if (thirdSales < 500)
	{
		thirdSalary = 200 + 0.03 * thirdSales;
	}
	else if (thirdSales >= 500 and thirdSales < 1000)
	{
		thirdSalary = 200 + 0.05 * thirdSales;
	}
	else if (thirdSales >= 1000)
	{
		thirdSalary = 200 + 0.08 * thirdSales;
	}

	// Поиск лучшего менеджера
	bestManager = firstSalary;

	if (bestManager < secondSalary)
	{
		bestManager = secondSalary;
	}
	else if (bestManager < thirdSalary)
	{
		bestManager = thirdSalary;
	}
	
	// Выдача премии 200$
	if (bestManager == firstSalary)
	{
		firstSalary += 200;
	}
	else if (bestManager == secondSalary)
	{
		secondSalary += 200;
	}
	else if (bestManager == thirdSalary)
	{
		thirdSalary += 200;
	}

	// Вывод итогов
	std::cout << "\nЗарплата первого менеджера: " << firstSalary << "$\nЗарплата второго менеджера: " << secondSalary << "$\nЗарплата третьего менеджера: " << thirdSalary << "$";

	return 0;
}