#include <iostream>
#include <string>
#include <cmath>

int binaryToDecimal(std::string binary_str)
{
    int decimal = 0;
    int length = binary_str.size();
    for (int i = 0; i < length; ++i)
    {
        if (binary_str[length - 1 - i] == '1')
        {
            decimal += pow(2, i);
        }
    }
    return decimal;
}

int main()
{
    std::string binary_str = "1101";
    int decimal = binaryToDecimal(binary_str);

    std::cout << "Десятичное представление числа " << binary_str << " равно " << decimal << std::endl;

    return 0;
}
