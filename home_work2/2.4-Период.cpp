#include <iostream>
#include <stdio.h>
using namespace std;
unsigned long NOD(unsigned long p, unsigned long q)
{
	while (p != q)
	{
		if (p > q)
			p -= q;
		else
			q -= p;
	}
	return p;
}
int main()
{
	unsigned long n, m;
	unsigned long p, q, z;

	scanf("%lu", &m);
	scanf("%lu", &n);
	printf("%lu", m / n);

	m %= n;
	if (m > 0)
	{
		printf(".");
		p = NOD(n, m);
		m /= p;
		n /= p;

		unsigned long p = 0, q = 0, z = n;

		while (z % 2 == 0)
		{
			p++;
			z /= 2;
		}
		while (z % 5 == 0)
		{
			q++;
			z /= 5;
		}
		if (p < q)
			p = q;
		for (unsigned long j = 0; j < p; j++)
		{
			m *= 10;
			printf("%lu", m / n);
			m %= n;
		}
		if (z > 1)
		{
			printf("(");
			q = 9;
			p = 1;
			while (q % z > 0)
			{
				p++;
				q = q % z * 10 + 9;
			}
			for (unsigned long j = 0; j < p; j++)
			{
				m *= 10;
				printf("%lu", m / n);
				m %= n;
			}
			printf(")");
		}
	}
	return 0;
}
