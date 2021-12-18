#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

int knapsack(std::vector<int> v, std::vector<int> w, int c, int wsum)
{
	int n = v.size();
	int ** table = new int*[n+1];
	for (int i = 0; i <= n; i++) {
		table[i] = new int[c+1];
		std::memset(table[i], 0, sizeof(int) * c+1);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= c; j++) {
			int max_exc = table[i-1][j];
			int max_inc = 0;
			if (w[i-1] <= j)
				max_inc = v[i-1]+table[i-1][j-w[i-1]];
			table[i][j] = std::max(max_exc, max_inc);
		}
	}
	
	int sum = 0;
	for (int i = n; i > 0; i--) {
		if (table[i][c] > table[i-1][c]) {
			c -= w[i-1];
			sum += v[i-1];
			if (c <= 0) {
				break;
			}
		}
	}

	return wsum - sum;
}

int main()
{
	int s;
	std::cin >> s;

	int cd = 0;
	int fd = 0;

	int wrem = 0;
	int vrem = 0;

	std::vector<int> w;
	std::vector<int> v;
	for (int i = 0; i < s; i++) {
		int d, c, f, u;
		std::cin >> d >> c >> f >> u;
		if ((c - f) > u)
			cd += d;
		else if ((f - c) >= u)
			fd += d;
		else {
			int needed = ((c + f + u) / 2) - c + 1;
			w.push_back(needed);
			v.push_back(d);
			wrem += needed;
			vrem += d;
		}
	}

	if ((fd - cd)+1 > vrem) {
		std::cout << "impossible";
		return 0;
	}

	int mindel = fd - cd + ((vrem - (fd - cd))/ 2) + 1;
	std::cout << knapsack(w, v, (vrem - mindel), wrem);
}
