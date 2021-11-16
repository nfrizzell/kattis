#include <iostream>

struct PhoneCall
{
	int source;
	int dest;
	int start;
	int end;
};

int main()
{
	int n, m;
	do
	{
		std::cin >> n >> m;

		PhoneCall calls[n];
		for (int i = 0; i < n; i++)
		{
			int so, de, st, du;
			std::cin >> so >> de >> st >> du;

			calls[i] = {so, de, st, (st+du)};
		}

		for (int i = 0; i < m; i++)
		{
			int count = 0;

			int start, duration, end;
			std::cin >> start >> duration;
			end = start + duration;

			for (int j = 0; j < n; j++)
			{
				PhoneCall c = calls[j];
				if (c.end > start && c.end <= end)
				{
					count++;
				}

				else if (c.start >= start && c.start < end)
				{
					count++;
				}

				else if ((c.start <= start) && (c.end >= end))
				{
					count++;
				}
			}
			std::cout << count << '\n';
		}
	}
	while (n != 0 || m != 0);
}
