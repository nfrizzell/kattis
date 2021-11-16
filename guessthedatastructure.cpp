#include <iostream>
#include <string>
#include <queue>
#include <stack>

int main()
{
	int n;
	std::string line;
	while (std::cin >> n)
	{
		bool stack = true;
		bool queue = true;
		bool priority_queue = true;

		auto qu = std::queue<int>(); 
		auto pri_qu = std::priority_queue<int>(); 
		auto st = std::stack<int>(); 

		int op, element;
		for (int i = 0; i < n; i++)
		{
			std::cin >> op >> element;	

			if (op == 2) 
			{
				int qu_element;
				int pri_qu_element;
				int st_element;
				if (qu.size() > 0)
				{
					qu_element = qu.front();	
					qu.pop();
				}
				else
				{
					qu_element = -9999;
				}
				if (pri_qu.size() > 0)
				{
					pri_qu_element = pri_qu.top();
					pri_qu.pop();
				}
				else
				{
					pri_qu_element = -9999;
				}
				if (st.size() > 0)
				{
					st_element = st.top();
					st.pop();
				}
				else
				{
					st_element = -9999;
				}

				if (qu_element != element)
				{
					queue = false;
				}
				if (pri_qu_element != element)
				{
					priority_queue = false;
				}
				if (st_element != element)
				{
					stack = false;
				}
			}

			else
			{
				qu.push(element);
				pri_qu.push(element);
				st.push(element);
			}
		}

		if (stack && !queue && !priority_queue)
		{
			std::cout << "stack" << '\n';
		}

		else if (!stack && queue && !priority_queue)
		{
			std::cout << "queue" << '\n';
		}

		else if (!stack && !queue && priority_queue)
		{
			std::cout << "priority queue" << '\n';
		}
		else if (!stack && !queue && !priority_queue)
		{
			std::cout << "impossible" << '\n';
		}
		else
		{
			std::cout << "not sure" << '\n';
		}
	}
}
