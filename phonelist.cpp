#include <iostream>
#include <vector>
#include <numeric>
#include <sstream>
#include <cstring>
#include <algorithm>

int main()
{
    std::ios_base::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    auto ss = std::stringstream();
    for (int i = 0; i < t; i++)
    {
        auto numbers = std::vector<std::string>();
        int n;
        std::cin >> n;
        for (int j = 0; j < n; j++)
        {
            std::string next;
            std::cin >> next;
            numbers.push_back(next);
        }
        std::sort(numbers.begin(), numbers.end());

        bool not_consistent = false;
        for (int j = 1; j < n; j++)
        {
            if (not_consistent)
            {
                break;
            }

            int least = std::min(numbers[j-1].size(), numbers[j].size());
            bool same = (std::strncmp(numbers[j-1].c_str(), numbers[j].c_str(), least) == 0);
            
            not_consistent = same || not_consistent;
        }

        if (!not_consistent)
        {
            ss << "YES" << '\n';
        }
        else
        {
            ss << "NO" << '\n';
        }
    }
    std::cout << ss.str();
}
