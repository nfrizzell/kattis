#include <iostream>
#include <set>

int main()
{
    int n;
    std::cin >> n;
    std::set<int> days {};

    for (int i = 0; i < n; i++)
    {
        int s, t;
        std::cin >> s >> t;
        for (int j = s; j <=t; j++)
        {
            days.insert(j);
        }
    }

    std::cout << days.size();
}
