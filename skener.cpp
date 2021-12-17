#include <iostream>

int main()
{
	int r, c, zr, zc;
	std::cin >> r >> c >> zr >> zc;

	for (int i = 0; i < r; i++)
	{
		std::string in;
		std::cin >> in;
		std::string out;
		for (int j = 0; j < c; j++)
		{
			for (int k = 0; k < zc; k++)
			{
				out += in[j];
			}
		}
		for (int j = 0; j < zr; j++)
		{
			std::cout << out << '\n';
		}
	}
}
