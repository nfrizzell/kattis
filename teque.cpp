#include <iostream>
#include <deque>
#include <unordered_map>

std::deque<int> teque1;
std::deque<int> teque2;

std::string op;
int val;

std::unordered_map<std::string, void(*)()> ops;

void push_back()
{
	teque2.push_back(val);
	while (teque2.size() > teque1.size())
	{
		teque1.push_back(teque2.front());
		teque2.pop_front();
	}
}

void push_front()
{
	teque1.push_front(val);
	while (teque1.size() > teque2.size()+1)
	{
		teque2.push_front(teque1.back());
		teque1.pop_back();
	}
}

void push_middle()
{
	teque2.push_front(val);
	while (teque2.size() > teque1.size())
	{
		teque1.push_back(teque2.front());
		teque2.pop_front();
	}
}

void get()
{
	if (val >= teque1.size())
	{
		std::cout << teque2[val - teque1.size()] << '\n';
	}

	else
	{
		std::cout << teque1[val] << '\n';
	}
}

int main()
{
	int n;	
	std::cin >> n;

	teque1 = std::deque<int>();
	teque2 = std::deque<int>();
	ops = 
	{
		{"push_back", push_back},
		{"push_front", push_front},
		{"push_middle", push_middle},
		{"get", get}
	};
	
	for (int i = 0; i < n; i++)
	{
	/*
		std::cout << "teque1: ";
		for (auto item : teque1)
		{
			std::cout << item << " ";
		}
		std::cout << "\nteque2: ";
		for (auto item : teque2)
		{
			std::cout << item << " ";
		}
		std::cout << '\n';
	*/
		std::cin >> op >> val;	
		ops[op]();
	}
}
