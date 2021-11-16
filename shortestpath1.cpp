#include <iostream>
#include <vector>
#include <utility>
#include <climits>
#include <set>
#include <numeric>
#include <queue>
#include <map>

typedef std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> minHeap;

int search(const int start, const int dest, std::vector<minHeap> adj)
{
	minHeap frontier; 

	int * dist = new int[adj.size()];
	bool * visited = new bool[adj.size()];
	for (int i = 0; i < adj.size(); i++)
	{
		dist[i] = INT_MAX;
		visited[i] = false;
	}
	dist[start] = 0;
	frontier.push({dist[start], start});

	while (!frontier.empty())
	{
		auto p = frontier.top();
		int cur = p.second;
		int total_weight = p.first;
		frontier.pop();

		visited[cur] = true;

		if (cur == dest)
		{
			break;
		}

		while (!adj[cur].empty())
		{
			auto n = adj[cur].top();
			adj[cur].pop();

			int weight = n.first;
			int next = n.second;
			if (!visited[next])
			{
				dist[next] = std::min(total_weight + weight, dist[next]);
				frontier.push({dist[next], next});
			}
		}
	}

	return dist[dest];
}

int main()
{
	while (true)
	{
		int n, m, q, s;
		std::cin >> n >> m >> q >> s;
		if (n == 0 && m == 0 && q == 0 && s == 0)
		{
			break;
		}

		std::vector<minHeap> adj;
		for (int i = 0; i < n; i++)
		{
			adj.push_back({});
		}

		for (int i = 0; i < m; i++)
		{
			int u, v, w;
			std::cin >> u >> v >> w;
			adj[u].push({w, v});
		}

		for (int i = 0; i < q; i++)
		{
			int dest;
			std::cin >> dest;
			int dist = search(s, dest, adj);
			if (dist == INT_MAX)
			{
				std::cout << "Impossible" << '\n';
			}
			else
			{
				std::cout << dist << '\n';
			}
		}
	}
}
