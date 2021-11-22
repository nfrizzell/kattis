#include <iostream>
#include <cmath>

int main()
{
	int x;
	std::cin >> x;

	int pf = 0;
	for (int i = 2; i*i <= x; i++)
	{
		while (x % i == 0)
		{
			pf++;
			x /= i;
		}
	}

	if (x != 1)
	{
		pf++;
	}

	std::cout << pf << '\n';
}
