#include <iostream>

int main() {
	setlocale(LC_ALL, "rus");

	int const SIZE = 7;
	int arr[SIZE], summ = 0, a = 0;

	for (int i = 0; i < SIZE; i++)
	{
		std::cout << "Введите расход за неделю (7 дней): ";
		std::cin >> arr[i];
		summ += arr[i];
	}

	std::cout << std::endl << "Общая сумма потраченная за неделю: " << summ;
	std::cout << std::endl << "Средняя за неделя потраченная сумма: " << summ / 7 << std::endl << std::endl;

	for (int i = 0; i < SIZE; i++)
	{
		if (arr[i] > 100)
		{
			a++;
			switch (i)
			{
			case 0:
				std::cout << "Понедельник\n";
				break;
			case 1:
				std::cout << "Вторник\n";
				break;
			case 2:
				std::cout << "Среда\n";
				break;
			case 3:
				std::cout << "Четверг\n";
				break;
			case 4:
				std::cout << "Пятница\n";
				break;
			case 5:
				std::cout << "Суббота\n";
				break;
			case 6:
				std::cout << "Воскресенье\n";
				break;
			}
		}
	}
	std::cout << a << " раз(а) вы потратили больше 100 долларов в день";
}