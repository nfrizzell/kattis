#include <iostream>
#include <cstdlib>

int main()
{
    long long a, b;
    
    while (std::cin >> a >> b)
    {
        std::cout << std::abs(a - b) << std::endl;
    }
}