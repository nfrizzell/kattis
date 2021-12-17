#include <iostream>
#include <vector>

char board[8][8];

struct QueenPos
{
    int x, y;
};

bool DiagonalsClear(int x, int y)
{
    int i = x;
    int j = y;

    while (i >= 0 && j >= 0)
    {
        if ((i != x && j != y) && board[i][j] == '*')
        {
            return false;
        }
        i--;
        j--;
    }

    i = x;
    j = y;

    while (i < 8 && j < 8)
    {
        if ((i != x && j != y) && board[i][j] == '*')
        {
            return false;
        }

        i++;
        j++;
    }

    i = x;
    j = y;

    while (i < 8 && j >= 0)
    {
        if ((i != x && j != y) && board[i][j] == '*')
        {
            return false;
        }
        i++;
        j--;
    }

    i = x;
    j = y;

    while (i >= 0 && j < 8)
    {
        if ((i != x && j != y) && board[i][j] == '*')
        {
            return false;
        }
        i--;
        j++;
    }

    return true;
}

bool PlusClear(int x, int y)
{
    for (int i = 0; i < 8; i++)
    {
        if ((x != i) && board[i][y] == '*')
        {
            return false;
        }

        if ((y != i) && board[x][i] == '*')
        {
            return false;
        }
    }

    return true;
}

int main()
{
    auto pos = std::vector<QueenPos>();
    for (int i = 0; i < 8; i++)
    {
        std::string line;
        std::cin >> line;

        for (int j = 0; j < 8; j++)
        {
            board[i][j] = line[j];  

            if (line[j] == '*')
            {
                pos.push_back(QueenPos{i, j});
            }
        }
    }

    for (auto qp : pos)
    {
        if (!DiagonalsClear(qp.x, qp.y) || !PlusClear(qp.x, qp.y))
        {
            std::cout << "invalid";
            return 0;
        }
    }


    if (pos.size() != 8)
    {
        std::cout << "invalid";
        return 0;
    }

    std::cout << "valid";
}
