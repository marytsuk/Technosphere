#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
using namespace std;

int main()
{

	unsigned long n;
	scanf("%lu", &n);
	vector <int> p(n);
	vector <int> u(n);
	for (unsigned long i = 0; i < n; i++)
	{
		int hours, minutes, seconds;
		char c;
		scanf("%d%c%d%c%d", &hours, &c, &minutes, &c, &seconds);
		p[i] = hours * 3600 + minutes * 60 + seconds;
		scanf("%d%c%d%c%d", &hours, &c, &minutes, &c, &seconds);
		u[i] = hours * 3600 + minutes * 60 + seconds;

	}

	sort(p.begin(), p.end());
	sort(u.begin(), u.end());

	unsigned long i = 0, j = 0, max = 0, k = 0;

	while (i < n && j < n)
	{
		while ((i < n) && (p[i] <= u[j]))
		{
			i++;
		}
		k = i - j;
		if (k > max)
			max = k;
		j++;

	}

	printf("%lu", max);
}

