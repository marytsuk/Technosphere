#include <iostream>
#include <vector>

using namespace std;

vector<vector<unsigned long long>> mul(vector<vector<unsigned long long>>& m1, vector<vector<unsigned long long>>& m2, unsigned long long mod)
{
	vector <vector<unsigned long long>> res(2, vector <unsigned long long>(2, 0));
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			res[i][j] = ((m1[i][0] * m2[0][j]) % mod + (m1[i][1] * m2[1][j]) % mod) % mod;
		}
	}
	return res;
}

vector<vector<unsigned long long>> binpow(vector <vector<unsigned long long>> A, unsigned long long n, unsigned long long m)
{
	if (n == 1)
	{
		return A;
	}
	if (n & 1)
	{
		auto B = binpow(A, n - 1, m);
		return mul(A, B, m);
	}
	else
	{
		auto B = binpow(A, n / 2, m);
		return mul(B, B, m);
	}
}

int main()
{
	vector <unsigned long long> vec(2);
	vector <vector<unsigned long long>> mat(2, vector <unsigned long long>(2, 0));
	mat[0][1] = mat[1][0] = mat[1][1] = 1;
	unsigned long long n, m;
	cin >> vec[0] >> vec[1] >> n >> m;
	vec[0] %= m;
	vec[1] %= m;
	if (n == 0)
	{
		cout << vec[0] << endl;
		return 0;
	}
	auto M = binpow(mat, n, m);
	cout << ((vec[0] * M[0][0]) % m + (vec[1] * M[1][0]) % m) % m << endl;
	return 0;
}
