#include <iostream>
#include <set>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	multiset<long long> myset;
	for (int i = 0; i < n; i++)
	{
		long long x;
		cin >> x;
		//myset.insert(x);
		if (myset.size() >= k)
		{
			//myset.erase(myset.begin());
			if (x > *myset.begin())
			{
				myset.erase(myset.begin());
				myset.insert(x);
			}
		}
		else
		{
			myset.insert(x);
		}
		
	}
	for (auto it = myset.rbegin(); it!= myset.rend(); it++)
	{
		cout << *it << endl;
	}
	return 0;
}