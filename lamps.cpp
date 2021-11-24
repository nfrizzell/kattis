#include <iostream>

typedef long long ll;

int main()
{
	int h, p;
	std::cin >> h >> p;
	
	double incandescent_cost = 5;
	double lamp_cost = 60;

	int days = 0;
	int hours = 0;
	while (lamp_cost > incandescent_cost)
	{
		days++;
		hours+=h;
		incandescent_cost += 60*h*p*.00001;
		lamp_cost += 11*h*p*.00001;
		if (hours > 1000)
		{
			hours -= 1000;
			incandescent_cost += 5;
		}
	}
	std::cout << days;
}
