#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	string line;
next:	while(std::getline(std::cin, line)) {
		vector<int> marks;
		int token;
		stringstream ss(line);
		while (ss >> token)
			marks.push_back(token);
		sort(marks.begin(), marks.end());
		int marksmax = *max_element(begin(marks), end(marks));
		vector<bool> dist(marksmax+1);

		for (int left = 0; left < marks.size(); left++) {
			for (int right = left+1; right < marks.size(); right++) {
				int size = marks[right] - marks[left];
				if (dist[size]) {
					cout << "not a ruler" << '\n';
					goto next;
				}
				dist[size] = true;
			}
		}
		vector<int> missing;
		for (int i = 1; i < marksmax; i++)
			if (!dist[i])
				missing.push_back(i);
		if (missing.size() == 0) {
			cout << "perfect";
		} else {
			cout << "missing";
			for (auto e : missing)
				cout << " " << e;
		}
		cout << '\n';
	}
}
