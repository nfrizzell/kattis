#include <iostream>
#include <cstdio>
#include <vector>

int main()
{
    int c;
    std::cin >> c;

    auto percentages = std::vector<float>();
    for (int i = 0; i < c; i++)
    {
        auto grades = std::vector<int>();

        int n;
        std::cin >> n;
        for (int j = 0; j < n; j++)
        {
            int grade;
            std::cin >> grade;
            grades.push_back(grade);
        }

        float total = 0;
        for (auto g : grades)
        {
            total += g;
        }
        float average = total / n;

        float above_average = 0;
        for (auto g : grades)
        {
            if (g > average)
            {
                above_average++;
            }
        }

        float percentage = above_average / n;
        percentages.push_back(percentage);
    }

    for (auto p : percentages)
    {
        printf("%.3f%%\n", p*100);
    }
}
