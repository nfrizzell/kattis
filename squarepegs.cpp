#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

int main()
{
    int n, m, k;

    std::cin >> n >> m >> k;

    auto plot_radius = std::vector<double>();
    auto house_size = std::vector<double>();

    double temp = 0;
    for (int i = 0; i < n; i++)
    {
        std::cin >> temp;
        plot_radius.push_back(temp);
    }

    for (int i = 0; i < m; i++)
    {
        std::cin >> temp;
        house_size.push_back(temp);
    }
    
    for (int i = 0; i < k; i++)
    {
        std::cin >> temp;
        house_size.push_back((temp * std::sqrt(2))/2);
    }

    std::sort(plot_radius.begin(), plot_radius.end());
    std::sort(house_size.begin(), house_size.end());

    int total = 0;
    while (plot_radius.size() > 0 && house_size.size() > 0)
    {
        if (house_size.back() < plot_radius.back())
        {
            house_size.pop_back();
            plot_radius.pop_back();
            total++;
        }
        else if (house_size.back() >= plot_radius.back())
        {
            house_size.pop_back();
        }
    }
    std::cout << total;
}
