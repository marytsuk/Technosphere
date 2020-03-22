#include <iostream>
#include <vector>
using namespace std;
unsigned long fact(unsigned long a)
{
	unsigned long result = 1;
	for (unsigned long b = 2; b <= a; b++)
	{
		result *= b;
	}
	return result;
}
int main()
{
	unsigned long n, m;
	cin >> n >> m;
	unsigned long k = 0;
	unsigned long n_f = fact(n);
	vector<bool> vec(n, true);
	m--;
	while (k != n)
	{
		n_f = n_f / (n - k);
		unsigned long c = m / n_f + 1;
		unsigned long count = 0;
		unsigned long i = 0;
		for (; i < n; i++)
		{
			if (vec[i])
				count++;
			if (count == c)
			{
				vec[i] = false;
				break;
			}
		}
		cout << i + 1 << " ";
		m = m % n_f;
		k++;
	}
	return 0;
}
