#include <iostream>
#include <vector>
#include <stack>

typedef long long ll;

int main()
{
	ll n;
	std::cin >> n;
	while (n != 0)
	{
		ll * seq = new ll[n];
		ll * max = new ll[n];
		ll * prev = new ll[n];

		for (ll i = 0; i < n; i++)
		{
			ll a;
			std::cin >> a;
			seq[i] = a;
			max[i] = 1;
			prev[i] = -1;
		}

		ll max_seq_len = 1;
		ll top_idx = 1;
		for (ll i = 0; i < n; i++)
		{
			ll max_less = 1;
			for (ll j = i-1; j >= 0; j--)
			{
				if (seq[j] < seq[i])
				{
					if (max[j]+1 > max_less)
					{
						max_less = max[j]+1;
						prev[i] = j;
					}
				}
			}
			max[i] = max_less;

			if (max_less >= max_seq_len)
			{
				max_seq_len = max_less;
				top_idx = i;
			}
		}

		std::stack<ll> reverse;
		while (top_idx != -1)
		{
			reverse.push(seq[top_idx]);
			top_idx = prev[top_idx];
		}

		std::cout << max_seq_len << " ";
		while (reverse.size() > 0)
		{
			std::cout << reverse.top() << " ";
			reverse.pop();
		}
		std::cout << '\n';
		std::cin >> n;
	}
}
