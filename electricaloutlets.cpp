#include <iostream>
#include <sstream>

int main()
{
    int n;
    std::cin >> n;

    auto output = std::stringstream();
    for (int i = 0; i < n; i++)
    {
        int k;
        std::cin >> k;
        if (k == 0)
        {
            output << 1 << '\n';    
        }

        int total = 0;
        int j; 
        for (j = 0; j < k; j++)
        {
            int o;
            std::cin >> o;
            total += o;
        }
        total -= (j - 1);

        output << total << '\n';
    }

    std::cout << output.str();
}
