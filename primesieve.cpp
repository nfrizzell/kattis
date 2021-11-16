#include <iostream>
#include <vector>

int main()
{
	int n, q;
	std::cin >> n >> q;
	
	// Sieve of Eratosthenes
	std::vector<bool> composite = std::vector<bool>(n + 1);
	unsigned int p = 2;
	bool finished = false;
	while (!finished)
	{
		finished = true;
		for (int i = 2; (i * p) <= n; i++)
		{
			composite[i*p] = true;
		}
		
		for (int i = p + 1; i <= n; i++)
		{
			if (!composite.at(i))
			{
				p = i;
				finished = false;
				break;
			}
		}
	}

	// Correct for these two which are not prime for mathematical reasons
	composite[0] = true;
	composite[1] = true;
	
	int k = 0;
	for (int i = 0; i < composite.size(); i++)
	{
		if (!composite.at(i))
		{
			k++;
		}
	}

	std::cout << k << '\n';

	for (unsigned int i = 0; i < q; i++)
	{
		unsigned int x = 0;
		std::cin >> x;

		if (composite.at(x))
		{
			std::cout << 0 << '\n';
		}		
		else
		{
			std::cout << 1 << '\n';
		}
	}
}
