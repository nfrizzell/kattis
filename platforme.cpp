#include <iostream>
#include <vector>

struct Platform
{
    int y, x1, x2;
};

int main()
{
    int n;
    std::cin >> n;
    
    int maxX2 = 0;
    int maxY = 0;

    std::vector<Platform> platforms {};

    for (int i = 0; i < n; i++)
    {
        int y, x1, x2;
        std::cin >> y >> x1 >> x2;

        if (y > maxY)
        {
            maxY = y;
        }

        if (x2 > maxX2)
        {
            maxX2 = x2;
        }

        Platform p {y, x1, x2};
        platforms.push_back(p);
    }   

    bool ** arr = new bool*[maxY];
    for (int i = 0; i < maxY; i++)
    {
        arr[i] = new bool[maxX2];
        for (int j = 0; j < maxX2; j++)
        {
            arr[i][j] = false;
        }
    }

    for (auto p : platforms)
    {
        for (int i = p.x1; i < p.x2; i++)
        {
            arr[p.y-1][i-1] = true;
        }
    }

    int total = 0;
    for (auto p : platforms)
    {
        int left = p.x1 - 1;
        int right = p.x2 - 2;

        for (int y = p.y-1; y >= 0; y--)
        {
            if (y != p.y-1 && arr[y][left])
            {
                break;
            }
            total++;
        }

        for (int y = p.y-1; y >= 0; y--)
        {
            if (y != p.y-1 && arr[y][right])
            {
                break;
            }
            total++;
        }
    }

    std::cout << total << '\n';
}
