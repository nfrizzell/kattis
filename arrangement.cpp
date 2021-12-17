#include <iostream>

int main()
{
    int n, m;
    std::cin >> n >> m;
    int * room = new int[n];
    for (int i = 0; i < m; i++)
    {
        room[i % n] += 1;   
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < room[i]; j++)
        {
            std::cout << "*";
        }
        std::cout << '\n';
    }
}
