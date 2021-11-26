#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>

int main()
{
	int n;
	std::cin >> n;
	std::vector<int> c(n);
	int * price_to_idx = new int[n];
	for (int i = 0; i < n; i++)
	{
		std::cin >> c[i];	
		price_to_idx[c[i]] = i;
	}

	int m;
	std::cin >> m;
	for (int i = 0; i < m; i++)
	{
		int s;
		std::cin >> s;
		std::vector<std::vector<int>> memo(s+1);
		for (int j = 0; j <= s; j++)
		{
			memo[j] = {};
		}

		memo[0] = {-1};

		for (int j = 1; j <= s; j++)
		{
			for (int k = 0; k < n; k++)
			{
				int price = c[k];
				int diff = j - price;
				if (diff >= 0 && !memo[diff].empty())
				{
					memo[j].push_back(price);
				}
			}
		}

		if (memo[s].empty())
		{
			std::cout << "Impossible" << '\n';
			continue;
		}

		std::vector<int> out;
		while (s > 0)
		{
			out.push_back(price_to_idx[memo[s][0]]+1);
			s -= memo[s][0];
		}

		std::sort(out.begin(), out.end());
		for (auto j : out)
		{
			std::cout << j << " ";
		}
		std::cout << '\n';
	}
}
