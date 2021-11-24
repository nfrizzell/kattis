#include <iostream>

int main()
{
	int n;
	std::cin >> n;
	while (n != -1)
	{
		int last = 0;
		int total = 0;
		for (int i = 0; i < n; i++)
		{
			int s, t;
			std::cin >> s >> t;
			total += (s * (t - last));
			last = t;
		}

		std::cout << total << " miles" << '\n';
		std::cin >> n;
	}
}
