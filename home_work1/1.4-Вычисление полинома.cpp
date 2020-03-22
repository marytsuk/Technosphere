#include <iostream>
#include <vector>
using namespace std;
unsigned long Horners(vector<unsigned long> &A, unsigned long n, unsigned long x, unsigned long m)
{
	unsigned long r = A[0];
	for (unsigned long j = 0; j < n - 1; j++)
	{
		r = (r * x) % m;
		r = r + A[j + 1] % m;
	}
	return r % m;
}
int main()
{
	vector <unsigned long> A;
	unsigned long n, k, m, a;
	cin >> n >> k >> m;
	for (int i = 0; i < n + 1; i++)
	{
		unsigned long a;
		cin >> a;
		A.push_back(a);
	}
	
	vector <unsigned long> result;
	
	for (int i = 0; i < k; i++)
	{
		unsigned long x;
		cin >> x;
		result.push_back(Horners(A, n + 1, x, m));
	}
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << endl;
	}
	return 0;
	
}