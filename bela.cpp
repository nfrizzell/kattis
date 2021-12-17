#include <iostream>
#include <map>

int main()
{
    auto dom = std::map<char, int>
    {
        {'A', 11},
        {'K', 4},
        {'Q', 3},
        {'J', 20},
        {'T', 10},
        {'9', 14},
        {'8', 0},
        {'7', 0}
    };


    auto not_dom = std::map<char, int>
    {
        {'A', 11},
        {'K', 4},
        {'Q', 3},
        {'J', 2},
        {'T', 10},
        {'9', 0},
        {'8', 0},
        {'7', 0}
    };

    int n;
    char b;
    std::cin >> n >> b;

    int total = 0;
    for (int i = 0; i < n*4; i++)
    {
        std::string line;
        std::cin >> line;   

        char card = line[0];
        char suit = line[1];

        if (suit == b)
        {
            total += dom[card];
        }

        else
        {
            total += not_dom[card];
        }
    }

    std::cout << total;
}
