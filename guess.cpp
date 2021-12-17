#include <iostream>

int main()
{
    int min = 0;
    int max = 1001;
    int guess;

    std::string result;

    while (true)
    {
        guess = (max + min)/2;
        std::cout << guess << '\n';
        std::cout.flush();
        std::cin >> result;

        if (result == "correct")
        {
            return 0;
        }

        else if (result == "higher")
        {
            min = guess;
        }
        
        else if (result == "lower")
        {
            max = guess;
        }
    }
}
