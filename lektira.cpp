#include <iostream>
#include <algorithm>
#include <cstring>

int main()
{
	std::string word;
	std::cin >> word;
	int n = word.size();
	char * best = new char[n];
	char * buf = new char[n];
	std::memset(buf, 'z', sizeof(char) * n);
	std::memset(best, 'z', sizeof(char) * n);
	for (int l = 0; l < n-2; l++) {
		for (int r = l + 2; r < n; r++) {
			for (int i = 0; i <= l; i++)
				buf[i] = word[l - i];
			for (int i = l+1; i < r; i++)
				buf[i] = word[r - (i-l)];
			for (int i = r; i < n; i++)
				buf[i] = word[n - (i-r)-1];
			if (std::lexicographical_compare(buf, buf+n, best, best+n))
				std::memcpy(best, buf, n);
		}
	}
	for (int i = 0; i < n; i++)
		std::cout << best[i];
}
