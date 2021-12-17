#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::string input;
    std::cin >> input;
    std::string output;

    int num_to_ignore = 0;
    for (int i = input.length()-1; i >= 0; i--)
    {
        if (input.at(i) == '<')
        {
            num_to_ignore++;
        }

        else if (num_to_ignore > 0)
        {
            num_to_ignore--;
        }
        else
        {
            output.push_back(input.at(i));
        }
    }
    std::reverse(output.begin(), output.end());
    std::cout << output;
}
