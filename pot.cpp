#include <iostream>
#include <cmath>

int main()
{
    int x;
    std::cin >> x;

    int total = 0;
    for (int i = 0; i < x; i++)
    {
        int input;
        std::cin >> input;

        int pow = input % 10;
        int num = input / 10;

        total += std::pow(num, pow);
    }
    std::cout << total;
}
