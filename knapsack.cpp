#include <iostream>
#include <stack>

int main()
{
	int c, n;
	while (std::cin >> c >> n)
	{
		int * weight = new int[n];
		int * value = new int[n];

		for (int i = 0; i < n; i++)
		{
			std::cin >> value[i] >> weight[i];
		}

		int ** table = new int*[n+1];
		for (int i = 0; i <= n; i++)
		{
			table[i] = new int[c+1];
			for (int j = 0; j <= c; j++)
			{
				table[i][j] = 0;
			}
		}

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= c; j++)
			{
				int maxValExcluding = table[i-1][j];
				int maxValIncluding = 0;

				if (weight[i-1] <= j)
				{
					int remainingWeight = j - weight[i-1];
					maxValIncluding = value[i-1] + table[i-1][remainingWeight];
				}

				table[i][j] = std::max(maxValExcluding, maxValIncluding);
			}
		}

		/*
		for (int i = 0; i < n+1; i++)
		{
			for (int j = 0; j < c+1; j++)
			{
				std::cout << table[i][j] << " ";
			}
			std::cout << '\n';

		}
		*/

		int capacity = c;
		std::stack<int> out;
		for (int i = n; i > 0; i--)
		{
			if (table[i][capacity] > table[i-1][capacity])
			{
				out.push(i-1);
				capacity -= weight[i-1];
				if (capacity <= 0)
				{
					break;
				}
			}
		}
		std::cout << out.size() << '\n';
		while (!out.empty())
		{
			std::cout << out.top() << " ";
			out.pop();
		}
		std::cout << '\n';
	}
}
