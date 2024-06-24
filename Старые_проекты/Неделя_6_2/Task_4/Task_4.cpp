#include <iostream>

int main()
{
    setlocale(LC_ALL, "rus");

	size_t A, B = 1;

	std::cout << "Введите число A: ";
	std::cin >> A;

	while (B < A)
	{
		if (A % (B * B) == 0 && A % (B * B * B) != 0)
		{
			std::cout << B << " ";
		}
		B++;
	}

	return 0;
}
