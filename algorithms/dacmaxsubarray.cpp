#include <iostream>
#include <vector>

using namespace std;

int midmax(vector<int> arr, int l, int r)
{
	int lmax = 0, rmax = 0, running_total = 0;
	int mid = ((r - l) / 2) + l;
	for (int i = mid; i >= 0; i--)
	{
		running_total += arr[i];
		if (running_total > lmax)
			lmax = running_total;
	}
	running_total = 0;
	for (int i = mid+1; i <= r; i++)
	{
		running_total += arr[i];
		if (running_total > rmax)
			rmax = running_total;
	}
	return lmax + rmax;
}

int dac(vector<int> arr, int l, int r)
{
	if (r == l)
		return arr[l];
		
	int mid = ((r - l)/ 2) + l;

	int lmax = dac(arr, l, mid);
	int rmax = dac(arr, mid+1, r);
	int mmax = midmax(arr, l, r);
	return max(lmax, max(rmax, mmax));
}

int main()
{
	int len; cin >> len;
	vector<int> arr(len);
	for (int i = 0; i < len; i++)
		cin >> arr[i];
	cout << dac(arr, 0, arr.size()-1);
}
