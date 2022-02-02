#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>

int main()
{
	int c;
	std::cin >> c;
	for (int i = 0; i < c; i++)
	{
		std::string winner = "Cat's";
		unsigned int game, checked = 0;
		std::cin >> std::oct >> game;

		std::vector<std::vector<bool>> played;
		std::vector<std::vector<bool>> xo;
		for (int i = 0; i < 3; i++)
		{
			played.push_back(std::vector<bool>(3));
			xo.push_back(std::vector<bool>(3));
		}

		for (int j = 0; j < 9; j++)
		{
			int goff = 1 << j;
			int xooff = 1 << (j+9);
			int p = (bool)(game & goff);
			if (!p)
				winner = "In progress";
			played[j/3][j%3] = p;
			xo[j/3][j%3] = (bool)(game & xooff);
		}

		/*
		played[0] = {1,1,0};
		played[1] = {1,1,1};
		played[2] = {1,1,1};

		xo[0] = {1,1,0};
		xo[1] = {0,0,1};
		xo[2] = {1,0,0};

		std::cout << "played: \n";
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				std::cout << played[j][k];
			}
			std::cout << '\n';
		}

		std::cout << "mark: \n";
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				std::cout << xo[j][k];
			}
			std::cout << '\n';
		}
		*/

		int mark = xo[0][0];
		for (int j = 0; j < 3; j++)
		{
			if (played[j][j] && xo[j][j] == mark)
			{
				if (j == 2)
				{
					if (mark == 1)
						winner = "X wins";
					else
						winner = "O wins";
					goto win;
				}
			}
			else
			{
				break;
			}
		}
		mark = xo[0][2];
		for (int j = 0; j < 3; j++)
		{
			if (played[j][(2-j)] && xo[j][(2-j)] == mark)
			{
				if (j == 2)
				{
					if (mark == 1)
						winner = "X wins";
					else
						winner = "O wins";
					goto win;
				}
			}
			else
			{
				break;
			}
		}
		//row
		for (int j = 0; j < 3; j++)
		{
			mark = xo[j][0];
			for (int k = 0; k < 3; k++)
			{
				if (played[j][k] && xo[j][k] == mark)
				{
					if (k == 2)
					{
						if (mark == 1)
							winner = "X wins";
						else
							winner = "O wins";
						goto win;
					}
				}
				else
				{
					break;
				}
			}
		}
		//col
		for (int j = 0; j < 3; j++)
		{
			mark = xo[0][j];
			for (int k = 0; k < 3; k++)
			{
				if (played[k][j] && xo[k][j] == mark)
				{
					if (k == 2)
					{
						if (mark == 1)
							winner = "X wins";
						else
							winner = "O wins";
						goto win;
					}
				}
				else
				{
					break;
				}
			}
		}

win:
		std::cout << winner << '\n';
	}
}
