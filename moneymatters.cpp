#include <unordered_map>
#include <unordered_set>
#include <iostream>

struct Node
{
	int total;
	std::unordered_set<int> friends;
	bool found = false;
};

int main()
{
	auto friends = std::unordered_map<int, Node>(); 
		
	int n, m;
	std::cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		Node n;
		std::cin >> n.total;
		friends[i] = n;
	}

	for (int i = 0; i < m; i++)
	{
		int friend1, friend2;
		std::cin >> friend1 >> friend2;
		friends[friend1].friends.insert(friend2);
		friends[friend2].friends.insert(friend1);
	}

	while (friends.size() > 0)
	{
		int total = 0;
		auto connectedFriends = std::unordered_set<int>();

		auto fringe = std::unordered_set<int>();
		int firstFriend = (*friends.begin()).first;
		fringe.insert(firstFriend);
		while (fringe.size() > 0)
		{
			int current = *fringe.begin();
			fringe.erase(current);
			friends[current].found = true;
			connectedFriends.insert(current);	
			for (auto key : friends[current].friends)
			{
				if (friends[key].found == false)
				{
					fringe.insert(key);
				}
			}
		}

		for (auto f : connectedFriends)
		{
			total += friends[f].total;
			friends.erase(f);
		}

		if (total != 0)
		{
			std::cout << "IMPOSSIBLE";
			return 0;
		}
	}

	std::cout << "POSSIBLE";
}
