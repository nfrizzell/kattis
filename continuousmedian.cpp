#include <iostream>
#include <queue>

int main()
{
    std::ios_base::sync_with_stdio(false);

    int t;
    std::cin >> t;

    for (int i = 0; i < t; i++)
    {
        std::priority_queue<int, std::vector<int>, std::greater<int>> max {};
        std::priority_queue<int> min {};

        unsigned long long sum = 0;
        int n;
        std::cin >> n;

        int last_median;

        for (int j = 1; j <= n; j++)
        {
            int num;
            std::cin >> num;    

            if (j == 1)
            {
                last_median = num;
                min.push(num);
            }

            else
            {

                if (num <= last_median)
                {
                    min.push(num);
                }

                else if (num > last_median)
                {
                    max.push(num);
                }

                if (min.size() == max.size())
                {
                    last_median = (min.top() + max.top())/2;
                }

                else if (min.size() > max.size())
                {
                    if (min.size() - max.size() > 1)
                    {
                        int top = min.top();
                        min.pop();
                        max.push(top);
                        last_median = (min.top() + max.top())/2;
                    }   

                    else
                    {
                        last_median = min.top();    
                    }
                }

                else if (max.size() > min.size())
                {
                    if (max.size() - min.size() > 1)
                    {
                        int top = max.top();
                        max.pop();
                        min.push(top);
                        last_median = (min.top() + max.top())/2;
                    }   

                    else
                    {
                        last_median = max.top();    
                    }
                }
            }

            sum += last_median;
        }
        std::cout << sum << '\n';
    }
}
