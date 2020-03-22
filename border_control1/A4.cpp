#include <iostream>
#include <vector>

using namespace std;

int main()
{
	unsigned long n, m;
	cin >> n >> m;
	vector<unsigned long> vec1(n);
	vector<unsigned long> vec2(n);
	for (unsigned long i = 0; i < n; i++)
	{
		cin >> vec1[i];
	}
	for (unsigned long i = 0; i < m; i++)
	{
		cin >> vec2[i];
	}
	unsigned long l = 0;
	unsigned long r = 1;

	for (int i = 0; i < m; i++)
	{
		unsigned long l = 0;
		unsigned long r = 1;
		bool flag = false;
		unsigned long sum = vec1[l] + vec1[r];
		while (l < n && r < n)
		{
			if (sum < vec2[i])
			{
				r++;
				sum += vec1[r];
			}
			else
				if (sum > vec2[i])
				{
					sum -= vec1[l];
					l++;

				}
				else
				{
					cout << l + 1 << " " << r + 2 << endl;
					flag = true;
					break;
				}
		}
		if (!flag)
			cout << "Not found" << endl;

	}
	return 0;
}
