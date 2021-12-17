#include <iostream>

int main()
{
    int total, empty, c;
    std::cin >> total >> empty >> c;

    total = total + empty;
    int drank = 0;
    while (total >= c)
    {
        drank++;
        total -= c;
        total++;
    }

    std::cout << drank;
}
