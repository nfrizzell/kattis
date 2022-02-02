#include <iostream>
#include <cmath>
#include <vector>
#include <utility>
#include <algorithm>

int main()
{
	int n;
	long double l, w;
cont:
	while(std::cin >> n >> l >> w)
	{
		std::vector<std::pair<long double, long double>> intervals;
		for (int i = 0; i < n; i++)
		{
			long double x, r;
			std::cin >> x >> r;
			if (r < w/2.0)
				continue;
			long double q = std::sqrt(4*(std::pow(r,2)) - std::pow(w, 2));
			long double a = x - q/2;
			long double b = x + q/2;
			intervals.push_back({a, b});
		}
		std::sort(intervals.begin(), intervals.end());
		long double lbound = 0;
		int total = 0;
		int idx = 0;
		while (lbound < l)
		{
			int i;
			long double r_max = 0;
			for (i = idx; i < intervals.size(); i++)
			{
				if (intervals[i].first <= lbound) 
				{
					if (intervals[i].second > r_max)
					{
						r_max = intervals[i].second;
					}
					//std::cout << intervals[i].first << " " << intervals[i].second << '\n';
				}
				else
					break;
			}
			if (r_max == 0)
			{
				std::cout << -1 << '\n';
				goto cont;
			}
			lbound = r_max;
			idx = i;
			total++;
		}
		std::cout << total << '\n';
	}
}
