#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <sstream>
#include <string>

int main()
{
    auto translation = std::map<char, std::string> 
    {
        {'a', "@"},
        {'b', "8"},
        {'c', "("},
        {'d', "|)"},
        {'e', "3"},
        {'f', "#"},
        {'g', "6"},
        {'h', "[-]"},
        {'i', "|"},
        {'j', "_|"},
        {'k', "|<"},
        {'l', "1"},
        {'m', "[]\\/[]"},
        {'n', "[]\\[]"},
        {'o', "0"},
        {'p', "|D"},
        {'q', "(,)"},
        {'r', "|Z"},
        {'s', "$"},
        {'t', "']['"},
        {'u', "|_|"},
        {'v', "\\/"},
        {'w', "\\/\\/"},
        {'x', "}{"},
        {'y', "`/"},
        {'z', "2"}
    };

    auto keys = std::vector<char>();
    for (auto pair : translation)
    {
        keys.push_back(pair.first);
    }

    std::string input;
    std::getline(std::cin, input);
    std::transform(input.begin(), input.end(), input.begin(), ::tolower);

    auto output = std::stringstream();

    for (int i = 0; i < input.length(); i++)
    {
        if (std::find(keys.begin(), keys.end(), input[i]) != keys.end())
        {
            output << translation[input[i]];
        }

        else
        {
            output << input[i];
        }
    }
    std::cout << output.str();
}
