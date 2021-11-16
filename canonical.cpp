#include <iostream>
#include <climits>
#include <numeric>
#include <cstring>

int denominations;
int * sizes = new int[denominations];
bool * found;
int * result;

int greedy(int total)
{
	int amount_coins = 0;

	while (total > 0)
	{
		if (total < sizes[1])
		{
			amount_coins += total;
			break;
		}

		for (int i = denominations-1; i >= 0; i--)
		{
			if (sizes[i] <= total)
			{
				total -= sizes[i];
				amount_coins++;
				break;
			}
		}
	}
		
	return amount_coins;
}

int complete(int remaining)
{
	if (remaining < 0)
	{
		return 10e8;
	}

	if (remaining == 0)
	{
		return 0;
	}

	if (remaining < sizes[1])
	{
		return remaining;
	}

	if (found[remaining])
	{
		return result[remaining];
	}

	int best = 10e8;

	for (int i = 0; i < denominations; i++)
	{
		best = std::min(best, complete(remaining-sizes[i]) + 1);
	}

	found[remaining] = true;
	result[remaining] = best;
	return best;
}

int main()
{
	std::cin >> denominations;
	for (int i = 0; i < denominations; i++)
	{
		int next;
		std::cin >> next;
		sizes[i] = next;
	}

	int upper_bound = sizes[denominations-1] + sizes[denominations-2];

	found = new bool[upper_bound];
	result = new int[upper_bound];

	memset(found, false, upper_bound);

	for (int i = 1; i < upper_bound; i++)
	{
		int greedy_amount;
		int complete_amount;
		
		greedy_amount = greedy(i);	
		complete_amount = complete(i);	

		if (greedy_amount != complete_amount)
		{
			std::cout << "non-canonical";
			return 0;
		}
	}
	std::cout << "canonical";

}
