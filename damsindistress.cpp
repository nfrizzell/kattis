#include <iostream>
#include <numeric>
#include <vector>

struct Node 
{
    int has;
    int max;
    std::vector<int> branches;
};

Node * allNodes;

int search(int node, int largest_requirement_along_branch)
{
    Node n = allNodes[node];

    int diff = n.max - n.has;
    int min_add = std::max(diff, (largest_requirement_along_branch - n.has));
    int min = min_add;

    if (n.branches.size() > 0)
    {
        for (auto b : n.branches)
        {
            min = std::min(min, search(b, min_add));
        }
    }

    return min;
}

int main()
{
    int n, w;
    std::cin >> n >> w; 

    allNodes = new Node[n+1];
    allNodes[0] = Node{0, w, {}};

    for (int i = 1; i <= n; i++)
    {
        int di, ci, ui;
        std::cin >> di >> ci >> ui;
        allNodes[di].branches.push_back(i);
        allNodes[i] = Node {ui, ci, {}};
    }

    std::cout << search(0, 0);
}
