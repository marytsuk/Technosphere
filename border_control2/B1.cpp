#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	unsigned long long w, h, n;
	cin >> w >> h >> n;
	unsigned long long right = w * n > h * n ? w * n : h * n;
	unsigned long long left = 1;
	while (left + 1 < right)
	{
		unsigned long long mid = (left + right) / 2;

		unsigned long long res = (mid / h) * (mid / w);
		if (res >= n)
		{
			right = mid;
		}
		else
			left = mid;
	}
	cout << right;
	return 0;
}
