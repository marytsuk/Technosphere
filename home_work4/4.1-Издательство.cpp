#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	unsigned long k, n;
	scanf("%lu %lu", &k, &n);
	vector<unsigned long> a(n);
	unsigned long maxPage = 0;
	for (unsigned long i = 0; i < n; i++)
	{
		scanf("%lu", &a[i]);
		maxPage = max(maxPage, a[i]);
	}

	unsigned long left = maxPage - 1;
	unsigned long right = 100;
	while (left + 1 < right)
	{
		unsigned long mid = (left + right) / 2;
		unsigned long c = 0;
		unsigned long volume = 0;
		for (unsigned long i = 0; i < n; i++)
		{
			if (volume + a[i] <= mid)
			{
				volume += a[i];
			}
			else
			{
				c++;
				volume = a[i];
				/*if (a[i] > mid)
				{
					break;
				}*/
			}
		}
		c++;
		if (c <= k)
		{
			right = mid;
		}
		else
		{
			left = mid;
		}
	}
	printf("%lu", right);
	return 0;
}
