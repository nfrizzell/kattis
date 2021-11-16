#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <string>
#include <algorithm>
#include <cstring>

int main()
{
	int recitals;
	std::cin >> recitals;
	
	int ** intersections = new int *[recitals];

	for (int i = 0; i < recitals; i++)
	{
		intersections[i] = new int[recitals];
		memset(intersections[i], 0, recitals);
	}
	
	auto hasChar = std::unordered_map<char, std::vector<int>>(); 
	std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for (auto ch : alphabet)
	{
		hasChar[ch] = std::vector<int>();
	}

	for (int i = 0; i < recitals; i++)
	{
		std::string recital;
		std::cin >> recital;
		for (auto ch : recital)
		{
			hasChar[ch].push_back(i);
		}
	}

	for (auto pair : hasChar)
	{
		auto vec = pair.second;
		for (int i = 0; i < vec.size(); i++)
		{
			for (int j = 0; j < vec.size(); j++)
			{
				if (i != j)
				{
					int i1 = vec[i];
					int i2 = vec[j];
					intersections[i1][i2] += 1;
				}
			}
		}
	}

	int * set = new int[recitals];
	for (int i = 0; i < recitals; i++)
	{
		set[i] = i;
	}

	int least_quick_changes = 9999;
	do
	{
		if (least_quick_changes == 0)
		{
			break;
		}

		int count = 0;
		for (int i = 0; i < recitals-1; i++)
		{
			count += intersections[set[i]][set[i+1]];
		}

		if (count < least_quick_changes)
		{
			least_quick_changes = count;
		}
	}
	while(std::next_permutation(set, set + recitals));
	
	std::cout << least_quick_changes;
}
