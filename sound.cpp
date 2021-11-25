#include <iostream>
#include <cmath>
#include <vector>

typedef long long ll;

int main()
{
	ll n, m, c; 
	std::cin >> n >> m >> c;

	ll * sound = new ll[n];

	ll * left_min = new ll[n];
	ll * right_min = new ll[n];
	ll * left_max = new ll[n];
	ll * right_max = new ll[n];

	ll running_left_min = 1000001;
	ll running_left_max = 0;
	for (ll i = 0; i < n; i++)
	{
		ll a;
		std::cin >> a;

		if (i % m == 0)
		{
			running_left_min = 1000001;
			running_left_max = 0;
		}

		running_left_min = std::min(running_left_min, a);
		running_left_max = std::max(running_left_max, a);

		left_min[i] = running_left_min;
		left_max[i] = running_left_max;

		sound[i] = a;
	}

	ll running_right_min = 1000001;
	ll running_right_max = 0;
	for (ll i = n-1; i >= 0; i--)
	{
		ll a = sound[i];
		if (i % m == 0)
		{
			running_right_min = 1000001;
			running_right_max = 0;
		}

		running_right_min = std::min(running_right_min, a);
		running_right_max = std::max(running_right_max, a);

		right_min[i] = running_right_min;
		right_max[i] = running_right_max;
	}

	std::vector<ll> output;
	for (ll i = 0; i <= n-m; i++)
	{
		ll min = std::min(left_min[i+m-1], right_min[i]);
		ll max = std::max(left_max[i+m-1], right_max[i]);

		if (std::abs(max - min) <= c)
		{
			output.push_back(i+1);
		}
	}

	if (output.size() > 0)
	{
		for (auto i : output)
		{
			std::cout << i << '\n';
		}
	}

	else
	{
		std::cout << "NONE";
	}
	
}
