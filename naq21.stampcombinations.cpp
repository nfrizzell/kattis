#include <iostream>
#include <unordered_map>
#include <vector>

typedef unsigned long long ull;

int main()
{
	ull m, n;
	std::cin >> m >> n;
	std::unordered_map<ull, std::vector<ull>> memo(m);
	ull * clusters = new ull[m];
	for (ull i = 0; i < m; i++) {
		memo[i] = {};
		std::cin >> clusters[i];
	}
	ull rsum = 0;
	for (ull i = m; i-- > 0; ) {
		rsum += clusters[i];
		memo[rsum].push_back(i);
	}
	for (ull i = 0; i < n; i++) {
		ull test = 0;
		ull lsum = 0;
		std::cin >> test;
		if (test == 0 || memo.count(test) && memo[test].size() > 0) {
			std::cout << "Yes" << '\n';
			goto next;
		}
		for (ull j = 0; j < m; j++) {
			lsum += clusters[j];
			if (lsum == test)
			{
				std::cout << "Yes" << '\n';
				goto next;
			}
			else if (lsum < test && memo.count(test - lsum))
			{
				for (auto k : memo[test-lsum])
				{
					if (k > j)
					{
						std::cout << "Yes" << '\n';
						goto next;
					}
				}
			}
		}
		std::cout << "No" << '\n';
next:		
		1+1;
	}
}
