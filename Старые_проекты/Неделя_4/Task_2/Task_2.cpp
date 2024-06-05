#include <iostream>

int main()
{
	setlocale(LC_ALL, "rus");
	int firstSales, secondSales, thirdSales, firstSalary, secondSalary, thirdSalary;
	
	// Ввод количества продаж менеджеров
	std::cout << "Введите количество продаж первого менеджера:";
	std::cin >> firstSales;
	std::cout << "Введите количество продаж второго менеджера:";
	std::cin >> secondSales;
	std::cout << "Введите количество продаж третьего менеджера:";
	std::cin >> thirdSales;

	// Уровень продаж первого менеджера
	if (firstSales < 500)
	{
		firstSalary = firstSales + 0.03 * firstSales;
	}
	else if (firstSales >= 500 and firstSales < 1000)
	{
		firstSalary = firstSales + 0.05 * firstSales;
	}
	else if (firstSales >= 1000)
	{
		firstSalary = firstSales + 0.08 * firstSales;
	}

	// Уровень продаж второго менеджера
	if (secondSales < 500)
	{
		secondSalary = secondSales + 0.03 * secondSales;
	}
	else if (secondSales >= 500 and secondSales < 1000)
	{
		secondSalary = secondSales + 0.05 * secondSales;
	}
	else if (secondSales >= 1000)
	{
		secondSalary = secondSales + 0.08 * secondSales;
	}

	// Уровень продаж третьего менеджера
	if (thirdSales < 500)
	{
		thirdSalary = thirdSales + 0.03 * thirdSales;
	}
	else if (thirdSales >= 500 and thirdSales < 1000)
	{
		thirdSalary = thirdSales + 0.05 * thirdSales;
	}
	else if (thirdSales >= 1000)
	{
		thirdSalary = thirdSales + 0.08 * thirdSales;
	}

	std::cout << secondSalary;
}