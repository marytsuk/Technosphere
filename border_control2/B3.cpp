#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n, m;
	cin >> n >> m;
	vector<long long> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());

	for (int i = 0; i < m; i++)
	{
		long long x;
		cin >> x;
		long long left = 0;
		long long right = n - 1;
		while (left < right)
		{
			long long sum = arr[left] + arr[right];
			if (sum < x)
			{
				left++;
			}
			else if (sum > x)
			{
				right--;
			}
			else if (sum == x)
			{
				cout << arr[left] << " " << arr[right] << endl;
				break;
			}
			
		}
		if (left == right)
		{
			cout << "Not found" << endl;
		}
	}
	return 0;
}