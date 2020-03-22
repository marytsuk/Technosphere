#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main()
{
	unsigned long n, r;

	scanf("%ld", &n);
	scanf("%ld", &r);
	vector<unsigned long> vec(r, 0);

	unsigned long tmp = 0;
	for (unsigned long i = 0; i < n; i++)
	{
		unsigned long x;
		scanf("%ld", &x);
		vec[x]++;
		tmp += r - x;
	}

	unsigned long min = tmp;
	unsigned long min_point;
	for (unsigned long i = 1; i < r; i++)
	{
		tmp = tmp + n - vec[i] * r;
		if (tmp < min)
		{
			min = tmp;
			min_point = i;
		}
	}

	printf("%ld", min_point);

	return 0;
}
