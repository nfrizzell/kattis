#include <iostream>

int main()
{
	unsigned int b, k, g;
	std::cin >> b >> k >> g;
	b = b-1;
	
	unsigned int num_groups = k / g;
	std::cout << (b / num_groups + (b % num_groups != 0));
}
