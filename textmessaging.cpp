#include <iostream>
#include <algorithm>

typedef long long ll;

int main()
{
	ll n;
	std::cin >> n;

	for (ll i = 0; i < n; i++) {
		ll sum = 0;
		ll p, k, l;
		std::cin >> p >> k >> l;
		ll * freq = new ll [l];
		for (ll j = 0; j < l; j++) 
			std::cin >> freq[j];
		std::sort(freq, freq + l, std::greater());
		for (ll j = 0; j < l; j++)
			sum += freq[j] * ((j / k) + 1);
		std::cout << "Case #" << i+1 << ": " << sum << '\n';
	}
}
