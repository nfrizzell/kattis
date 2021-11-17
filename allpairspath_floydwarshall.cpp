#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <numeric>
#include <queue>
#include <map>

const int INF = 100000000;

int main()
{
	while (true)
	{
		int n, m, q;
		std::cin >> n >> m >> q;
		if (n == 0 && m == 0 && q == 0)
		{
			break;
		}

		int ** distance = new int*[n];
		for (int i = 0; i < n; i++)
		{
			distance[i] = new int[n];
			for (int j = 0; j < n; j++)
			{
				distance[i][j] = INF;
			}
		}

		for (int i = 0; i < n; i++)
		{
			distance[i][i] = 0;
		}

		for (int i = 0; i < m; i++)
		{
			int u, v, w;
			std::cin >> u >> v >> w;
			distance[u][v] = std::min(w, distance[u][v]);
		}

		for (int k = 0; k < n; k++)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (distance[i][j] > (distance[i][k] + distance[k][j]) && distance[i][k] < INF && distance[k][j] < INF)
					{
						distance[i][j] = (distance[i][k] + distance[k][j]);
					}

				}
			}
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				for (int k = 0; distance[i][j] != -INF && k < n; k++)
				{
					if (distance[i][k] != INF &&
						distance[k][j] != INF &&
						distance[k][k] < 0)
					{
						distance[i][j] = -INF;
					}
				}
			}
		}

		for (int c = 0; c < q; c++)
		{
			int u, v;
			std::cin >> u >> v;

			int d = distance[u][v];
			if (d == INF)
			{
				std::cout << "Impossible" << '\n';
			}

			else if (d == -INF)
			{
				std::cout << "-Infinity" << '\n';
			}

			else
			{
				std::cout << distance[u][v] << '\n';
			}
		}

		std::cout << '\n';
	}
}
