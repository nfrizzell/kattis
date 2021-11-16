#include <iostream>
#include <cmath>
#include <numeric>
#include <iomanip>

int main()
{
	long double const pi = 3.14159265358979323846;
	long double m, n;
	long double r;

	std::cin >> m >> n >> r;

	long double ax, ay, bx, by;
	std::cin >> ax >> ay >> bx >> by;

	long double ring = (ay < by) ? ay : by;
	long double rad = (ring / n) * r;
	long double circum = pi * rad;
	long double arclen = circum * (std::abs(bx-ax)/m);
	long double straight_dist = (std::abs(by-ay) / n) * r;
	long double distance1 = straight_dist + arclen;

	long double rad1 = (ay/n)*r;
	long double rad2 = (by/n)*r;
	long double distance2 = rad1 + rad2;

	std::cout << std::fixed;
	std::cout << std::setprecision(15);

	if (distance1 < distance2)
	{
		std::cout << distance1;
	}

	else
	{
		std::cout << distance2;
	}
}
