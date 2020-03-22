#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;
const unsigned long MAX = 20000000;
int main()
{
	unsigned long m, n;
	long k = -1;

	scanf("%ld", &m);
	scanf("%ld", &n);

	vector<bool> a(MAX, true);
	for (unsigned long p = 2; p * p < MAX; ++p)
	{
		if (a[p])
		{
			for (unsigned long j = p * p; j < MAX; j += p)
				a[j] = false;
		}
	}
	unsigned long l = 2, r = n + 1, count = 0;
	for (unsigned long i = l; i <= r; ++i)
		if (a[i])
		{
			++count;
		}
	for (unsigned long i = l; i < MAX - n; ++i)
	{
		if (count == m)
		{
			k = i;
			break;
		}

		if (a[++r])
		{
			++count;
		}
		if (a[l++])
		{
			--count;
		}
	}
	printf("%ld", k);
	return 0;
}
