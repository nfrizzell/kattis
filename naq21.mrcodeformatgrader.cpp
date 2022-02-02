#include <iostream>
#include <cstring>
#include <vector>
#include <utility>

int main()
{
	int lines, errors;
	std::cin >> lines >> errors;
	bool * err = new bool[lines+1];
	std::memset(err, 0, lines);
	std::vector<std::pair<int, int>> cInterval, eInterval;

	for (int i = 0; i < errors; i++)
	{
		int e;
		std::cin >> e;
		err[e] = true;
	}

	int start = 1;
	int type = err[1];
	for (int i = 1; i <= lines; i++)
	{
		if (err[i] != type)
		{
			if (type == 1) // err
				eInterval.push_back({start, i-1});
			else
				cInterval.push_back({start, i-1});
			start = i;
			type = err[i];
		}

		if (i == lines)
		{
			if (type == 1) // err
				eInterval.push_back({start, i});
			else
				cInterval.push_back({start, i});
		}
	}

	std::cout << "Errors: ";
	for (int i = 0; i < eInterval.size(); i++)
	{
		auto item = eInterval[i];
		if (item.first == item.second)
			std::cout << item.first;
		else
			std::cout << item.first << "-" << item.second;
		if (i == eInterval.size()-2)
			std::cout << " and ";
		else if (i != eInterval.size()-1)
			std::cout << ", ";
	}

	std::cout << "\nCorrect: ";
	for (int i = 0; i < cInterval.size(); i++)
	{
		auto item = cInterval[i];
		if (item.first == item.second)
			std::cout << item.first;
		else
			std::cout << item.first << "-" << item.second;
		if (i == cInterval.size()-2)
			std::cout << " and ";
		else if (i != cInterval.size()-1)
			std::cout << ", ";
	}

}
