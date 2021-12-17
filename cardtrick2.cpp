#include <iostream>
#include <deque>
#include <sstream>

int main()
{
    int n;
    std::cin >> n;
    auto output = std::stringstream();
    for (int i = 0; i < n; i++)
    {
        auto deck = std::deque<int>();
        auto dealt = std::deque<int>();

        int c;
        std::cin >> c;
        for (int j = 0; j < c; j++)
        {
            dealt.push_front(j);
        }

        for (int j = c; j > 0; j--)
        {
            deck.push_front(dealt.front());
            dealt.pop_front();
            for (int k = 0; k < j; k++)
            {
                deck.push_front(deck.back());   
                deck.pop_back();
            }
        }

        for (auto card : deck)
        {
            output << card+1 << " ";
        }

        output << '\n';
    }

    std::cout << output.str();
}
