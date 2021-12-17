#include <iostream>

int main()
{
    std::string p1, p2;
    std::cin >> p1 >> p2;

    int p1num = 0;
    int p2num = 0;
    for (int i = 0; i < p1.size(); i++)
    {
        if (p1[i] == 'S')
        {
            p1num++;
        }
    }

    for (int i = 0; i < p2.size(); i++)
    {
        if (p2[i] == 'S')
        {
            p2num++;
        }
    }

    for (int i = 0; i < p1num * p2num; i++)
    {
        std::cout << "S(";
    }
    std::cout << 0;
    for (int i = 0; i < p1num * p2num; i++)
    {
        std::cout << ")";
    }
}
