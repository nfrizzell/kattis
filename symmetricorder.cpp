#include <iostream>
#include <vector>

int main()
{
	int n;
	int setno = 1;
	std::cin >> n;
	while (n != 0)
	{
		std::vector<std::string> strs(n);
		for (int i = 0; i < n; i++)
		{
			std::cin >> strs[i];
		}

		std::vector<std::string> left, right;
		for (int i = 0; i < n; i++)
		{
			if (i % 2 == 0)
			{
				left.push_back(strs[i]);
			}

			else
			{
				right.push_back(strs[i]);
			}
		}

		std::cout << "SET " << setno << '\n';
		for (int i = 0; i < left.size(); i++)
		{
			std::cout << left[i] << '\n';
		}

		for (int i = right.size()-1; i >= 0; i--)
		{
			std::cout << right[i] << '\n';
		}

		std::cin >> n;
		setno++;
	}
}
