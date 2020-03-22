#include <iostream>
using namespace std;
unsigned long long modular_pows(unsigned long long a, unsigned long long b, unsigned long long m)
{
	if (b == 0)
		return (unsigned long long)1;
	if (b & 1)
		return (modular_pows(a, b - 1, m) * (a % m)) % m;
	unsigned long long y = modular_pows(a, b / 2, m);
	return (y * y) % m;
}

int main()
{
	unsigned long long x, p, m;
	cin >> x >> p >> m;
	cout << modular_pows(x, p, m);
	return 0;
}