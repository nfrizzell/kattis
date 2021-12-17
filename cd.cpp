
#include <iostream>
#include <unordered_set>
#include <sstream>

int main()
{
    int n = -1, m = -1;

    auto ss = std::stringstream();
    while (n != 0 && m != 0)
    {
        std::cin >> n >> m;     
        auto jack = std::unordered_set<int>();
        int both = 0;

        unsigned int cd = 0;
        for (int i = 0; i < n; i++)
        {
            std::cin >> cd;
            jack.insert(cd);
        }

        for (int i = 0; i < m; i++)
        {
            std::cin >> cd;
            if (jack.count(cd))
            {
                both++;
            }
        }

        if (n != 0)
            ss << both << '\n';
    }
    std::cout << ss.str(); 
}


