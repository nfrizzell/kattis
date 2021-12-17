#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>

int main()
{
    int t;
    std::cin >> t;
    auto outputs = std::vector<float>();

    for (int i = 0; i < t; i++)
    {
        int n_stores = 0;
        std::cin >> n_stores;
        auto store_pos = std::vector<float>();

        for (int j = 0; j < n_stores; j++)
        {
            float f;
            std::cin >> f;
            store_pos.push_back(f);
        }

        std::sort(store_pos.begin(), store_pos.end());

        int total = 0;
        float avg = 0;
        for (int j = 0; j < n_stores; j++)
        {
            total += store_pos[j];  
        }

        avg = total / n_stores;
        store_pos[n_stores] = avg;

        outputs.push_back(((avg - store_pos.front()) + (store_pos.back() - store_pos.front()) + (store_pos.back() - avg)));
    }

    for (auto i : outputs)
    {
        std::cout << i << '\n';
    }
}


