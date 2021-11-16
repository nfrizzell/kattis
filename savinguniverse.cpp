#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iterator>
#include <sstream>

int main()
{
	int t;
	std::cin >> t;

	std::stringstream ss = std::stringstream();;

	for (int i = 0; i < t; i++)
	{
		int s;
		std::cin >> s;
		auto engines = std::vector<std::string>();

		std::cin.ignore();
		for (int j = 0; j < s; j++)
		{
			std::string buf;
			std::getline(std::cin, buf);
			engines.push_back(buf);
		}

		int q;
		std::cin >> q;
		auto queries = std::vector<std::string>();

		std::cin.ignore();
		for (int j = 0; j < q; j++)
		{
			std::string buf;
			std::getline(std::cin, buf);
			queries.push_back(buf);
		}

		int switches = -1;
		if (queries.size() > 0)
		{
			std::string current_engine = queries[0];
			
			auto iter = queries.begin();
			while (iter != queries.end())
			{
				if (*iter == current_engine)
				{
					auto furthest = iter;
					for (std::string engine : engines)
					{
						auto next_instance = std::find(iter, queries.end(), engine);
						if (std::distance(iter, next_instance) > std::distance(iter, furthest))
						{
							furthest = next_instance;
							current_engine = engine;
						}
					}
					switches++;
				}
				iter++;
			}
		}

		else
		{
			switches = 0;
		}

		ss << "Case #" << i+1 << ": " << switches << "\n";
	}

	std::cout << ss.str();
}
