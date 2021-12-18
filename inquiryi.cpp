#include <iostream>
#include <algorithm>

typedef long long ll;

int main()
{
	int n;
	std::cin >> n;
	
	ll lsum = 0;
	ll rsum = 0;
	ll * arr = new ll[n];
	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
		rsum += arr[i];
	}

	ll max = 0;
	for (int k = 0; k < n; k++) {
		lsum += (arr[k] * arr[k]);
		rsum -= arr[k];
		max = std::max(max, lsum * rsum);
	}

	std::cout << max;
}
