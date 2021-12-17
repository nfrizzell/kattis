#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include <algorithm>
#include <numeric>

int main()
{
    int n, m;
    typedef std::pair<int, std::pair<int, int>> edge;

    while (true)
    {
        std::cin >> n >> m;

        if (n == 0 && m == 0)
        {
            return 0;
        }

        std::vector<edge> edges {};
        
        for (int i = 0; i < m; i++)
        {
            int u, v, w;
            int smallerv;
            int largerv;

            std::cin >> u >> v >> w;
            smallerv = std::min(u, v);
            largerv = std::max(u, v);
            edges.push_back({w, {smallerv, largerv}});
        }

        std::vector<int> ** vertexSets = new std::vector<int>*[n];
        std::vector<int> * glob = new std::vector<int>[n];
        for (int i = 0; i < n; i++)
        {
            glob[i] = std::vector<int>{};
            glob[i].push_back(i);
            vertexSets[i] = &(glob[i]);
        }

        std::set<std::pair<int, int>> orderedEdges {};
        std::sort(edges.begin(), edges.end());

        int total = 0;
        int idx = 0;
        while (vertexSets[0]->size() < n && idx < edges.size())
        {
            edge nextEdge = edges[idx];
            int v1 = nextEdge.second.first;
            int v2 = nextEdge.second.second;
            int weight = nextEdge.first;

            std::vector<int> * v1SetPtr = vertexSets[v1];   
            std::vector<int> * v2SetPtr = vertexSets[v2];

            if (v1SetPtr != v2SetPtr)
            {
                for (auto i : *v2SetPtr)
                {
                    v1SetPtr->push_back(i);
                    vertexSets[i] = v1SetPtr;
                }

                orderedEdges.insert(nextEdge.second);
                total += weight; 
            }

            idx++;
        }

        if (vertexSets[0]->size() < n)
        {
            std::cout << "Impossible" << '\n';
        }

        else
        {
            std::cout << total << '\n';
            for (auto edge : orderedEdges)
            {
                std::cout << edge.first << " " << edge.second << '\n';
            }
        }
    }
}


