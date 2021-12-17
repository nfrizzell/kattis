#include <iostream>
#include <vector>

int main()
{
    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        int degree1, degree2;
        std::vector<int> p1coefficients {};
        std::vector<int> p2coefficients {};

        std::cin >> degree1;
        for (int i = 0; i <= degree1; i++)
        {
            int coefficient;
            std::cin >> coefficient;
            p1coefficients.push_back(coefficient);  
        }

        std::cin >> degree2;
        for (int i = 0; i <= degree2; i++)
        {
            int coefficient;
            std::cin >> coefficient;
            p2coefficients.push_back(coefficient);  

        }

        std::vector<int> product_coefficients (degree1 + degree2 + 1);
        for (int i = 0; i <= degree1; i++)
        {
            for (int j = 0; j <= degree2; j++)
            {
                int degree = i + j;
                product_coefficients[degree] += p1coefficients[i] * p2coefficients[j];
            }   
        }

        std::cout << product_coefficients.size()-1 << '\n';
        for (int i = 0; i < product_coefficients.size(); i++)
        {
            std::cout << product_coefficients[i] << " ";
        }
        std::cout << '\n';
    }
}
