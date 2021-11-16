#include <iostream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <unordered_set>
#include <cstring>

int r, c;
int r2, c2;
char ** arr;
int ** colors;

void traverse_region(int row, int col, int color, char charchecked)
{
	colors[row][col] = color;

	if (col > 0 && arr[row][col-1] == charchecked && colors[row][col-1] == -1)
	{
		traverse_region(row, col-1, color, charchecked);
	}

	if (row > 0 && arr[row-1][col] == charchecked && colors[row-1][col] == -1)
	{
		traverse_region(row-1, col, color, charchecked);
	}

	if (col < c-1 && arr[row][col+1] == charchecked && colors[row][col+1] == -1)
	{
		traverse_region(row, col+1, color, charchecked);
	}

	if (row < r-1 && arr[row+1][col] == charchecked && colors[row+1][col] == -1)
	{
		traverse_region(row+1, col, color, charchecked);
	}
}

int main()
{
	std::cin >> r >> c;

	// Represents the grid in the problem
	arr = new char*[r];
	for (int i = 0; i < r; i++)
	{
		arr[i] = new char[c];
	}

	colors = new int*[r];
	for (int i = 0; i < r; i++)
	{
		colors[i] = new int[c];
		for (int j = 0; j < c; j++)
		{
			colors[i][j] = -1;
		}
	}

	for (int i = 0; i < r; i++)
	{
		// Get each row of characters and break them up into individual columns
		std::string line;
		std::cin >> line;
		for (int j = 0; j < c; j++)
		{
			arr[i][j] = line[j];
		}
	}

	int n;
	std::cin >> n;

	int color = 0;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (colors[i][j] == -1)
			{
				char charchecked = arr[i][j];
				traverse_region(i, j, color, charchecked);
				color++;
			}
		}
	}

	auto ss = std::stringstream();
	for (int i = 0; i < n; i++)
	{
		int r1, c1;
		std::cin >> r1 >> c1 >> r2 >> c2;
		r1 = r1-1;
		r2 = r2-1;
		c1 = c1-1;
		c2 = c2-1;

		std::string tooutput = "decimal\n";
		if (arr[r1][c1] == '0')
		{
			tooutput = "binary\n";
		}

		if (arr[r1][c1] != arr[r2][c2])
		{
			ss << "neither\n";
		}

		else if (r1 == r2 && c1 == c2)
		{
			ss << tooutput;
		}

		else
		{
			if (colors[r1][c1] == colors[r2][c2])
			{
				ss << tooutput;	
			}

			else
			{
				ss << "neither\n";
			}
		}
	}

	std::cout << ss.str();
}
