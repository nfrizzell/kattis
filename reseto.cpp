#include <iostream>
#include <cstring>

int main()
{
	int n, k;
	std::cin >> n >> k;
	bool * arr = new bool[n+1];
	std::memset(arr, 0, sizeof(bool)*n+1);
	int crossed = 0;
	arr[0] = true;
	arr[1] = true;
	int idx = 2;
	int p;
	while (true) {
		if (!arr[idx]) {
			p = idx;
			for (int i = p; i <= n; i += p) {
				if (!arr[i]) {
					crossed++;
					arr[i] = true;
				}
				if (crossed == k) {
					std::cout << i;	
					return 0;
				}
			}
			idx = 2;
		} else {
			idx++;
		}
	}

}
