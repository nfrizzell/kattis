#include <iostream>
#include <sstream>
#include <string>

int main()
{
    auto output = std::stringstream();
    while (true)
    {
        // Non-inclusive
        int upper_bound =11;
        int lower_bound =0;
        int most_recent_input;
        std::string response;

        while (true)
        {
            std::cin >> most_recent_input;
            if (most_recent_input == 0)
            {
                std::cout << output.str();
                return 0;
            }

            std::cin.ignore();
            std::getline(std::cin, response);

            if (response == "too high" && most_recent_input < upper_bound)
            {
                upper_bound = most_recent_input;
            }
            else if (response == "too low" && most_recent_input > lower_bound)
            {
                lower_bound = most_recent_input;
            }
            else if (response == "right on")
            {
                if (most_recent_input <= lower_bound || most_recent_input >= upper_bound)
                {
                    output << "Stan is dishonest\n";
                }
                else
                {
                    output << "Stan may be honest\n";
                }
                break;
            }
        }
    }
}
