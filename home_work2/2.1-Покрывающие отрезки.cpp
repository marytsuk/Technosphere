#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;
int main()
{
	unsigned long n;
	scanf("%lu", &n);
	vector<long double> elem(n);
	for (unsigned long i = 0; i < n; i++)
		cin >> elem[i];
	sort(elem.begin(), elem.end());
	unsigned long count = 0, i = 0;
	long double r = 0.0;
	while (i < n)
	{
		count += 1;
		r = elem[i] + 1;
		while (i < n and elem[i] <= r)
		{
			i += 1;
		}
	}
	printf("%lu", count);
	return 0;

}
