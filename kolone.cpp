#include <iostream>
#include <vector>
#include <algorithm>

struct Ant
{
	bool walkingLeft;
	char id;	
};

int main()
{
	int n1, n2;
	std::cin >> n1 >> n2;
	auto order = std::vector<Ant>();

	for (int i = 0; i < n1; i++)
	{
		char id;
		std::cin >> id;
		Ant nextAnt {false, id};
		order.push_back(nextAnt);	
	}
	std::reverse(order.begin(), order.end());

	for (int i = 0; i < n2; i++)
	{
		char id;
		std::cin >> id;
		Ant nextAnt {true, id};
		order.push_back(nextAnt);	
	}

	int t;
	std::cin >> t;

	for (int i = 0; i < t; i++)
	{
		
		auto transformedPos = std::vector<Ant>();
		for (int j = 0; j < (n1 + n2); j++)
		{
			if (j == (n1 + n2)-1)
			{
				transformedPos.push_back(order[j]);
			}

			else if (order[j+1].walkingLeft && !order[j].walkingLeft)
			{
				transformedPos.push_back(order[j+1]);
				transformedPos.push_back(order[j]);
				j++;
			}
			else
			{
				transformedPos.push_back(order[j]);
			}
		}
		order = transformedPos;
	}

	for (auto ant : order)
	{
		std::cout << ant.id;
	}
}
