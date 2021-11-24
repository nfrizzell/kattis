#include <iostream>
#include <stack>

int main()
{
	int n;
	std::cin >> n;
	std::stack<int> input;
	for (int i = 0; i < n; i++)
	{
		int next;
		std::cin >> next;
		input.push(next);
	}

	while (input.size() > 0)
	{
		std::cout << input.top() << '\n';
		input.pop();
	}
}
