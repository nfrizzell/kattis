#include <iostream>
#include <vector>

typedef long long ll;

int main()
{
	ll n;
	std::cin >> n;

	std::vector<ll> students;
	for (ll i = 0; i < n; i++)
	{
		ll a;
		std::cin >> a;
		if (a != 0)
		{
			students.push_back(a);
		}
	}

	ll running_total = 0;
	ll max_total = 0;
	ll max_pos = students.size();

	for (ll i = students.size()-1; i >= 0; i--)
	{
		running_total += students[i];
		if (running_total > max_total)
		{
			max_total = running_total;
			max_pos = i;
		}
	}

	students.insert(students.begin() + max_pos, 0);

	ll total = 0;
	for (ll i = 0; i < students.size(); i++)
	{
		total += ((i+1) * students[i]);
	}
	std::cout << total << '\n';
}
