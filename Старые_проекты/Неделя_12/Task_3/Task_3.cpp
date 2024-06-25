#include <iostream>
#include <time.h>
bool M[10] = { false };

struct game
{
    int q[4];
    int a[4];
    int num;

    void init()
    {
        int d, Cnt = 4;
        while (Cnt)
        {
            d = rand() % 10;
            if (!M[d])
            {
                q[Cnt - 1] = d;
                Cnt--;
            }
        }
    }

    void proceed(int n)
    {
        n++;

        std::cout << "\nВведите число: ";
        std::cin >> num;

        if (check(num))
        {
            std::cout << "\n*****\n\nУгадано! Было сделано " << n << " попыток.";

            char x;
            do
            {
                std::cout << "\n\nЕщё раз? (y/n) ";
                std::cin >> x;
            } while (x != 'y' && x != 'n');

            if (x == 'y') run();


        }
        else {
            proceed(n);
        }
    }

    bool check(int num)
    {
        int temp[4];
        memcpy(temp, q, 4 * sizeof(int));

        for (int i = 3; i >= 0; i--)
        {
            a[i] = num % 10;
            num /= 10;
        }

        int b = 0;
        int c = 0;

        for (int i = 0; i < 4; i++)
        {
            if (a[i] == temp[i])
            {
                b++;
                temp[i] = -1;
            }

        }

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; ++j)
            {
                if (a[i] == temp[j])
                {
                    c++;
                    temp[j] = -1;
                    break;
                }
            }
        }

        std::cout << "\n Коровы = " << c << " Быки = " << b;
        std::cout << "\n------------------------";
        if (b == 4) return true;

        return false;
    }

    void run()
    {
        init();
        proceed(0);
    }
};

int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(0));
    game A;
    A.run();

    return 0;
}