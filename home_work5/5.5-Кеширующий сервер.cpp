#include <iostream>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <vector>
using namespace std;
const int MAX_INDEX = 1000000;
int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	unordered_set<unsigned long long> myset;
	unordered_map<unsigned long long, set<int>> interval;
	vector<unsigned long long> vec(m);
	vector<pair<int, unsigned long long>> bh;
	for (int i = 0; i < m; i++)
	{
		unsigned long long q;
		scanf("%llu", &q);
		interval[q].insert(i);
		vec[i] = q;
	}
	int count = 0;
	int priority;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < bh.size(); j++)
		{
			bh[j].first--;
		}
		interval[vec[i]].erase(interval[vec[i]].begin());
		if (myset.find(vec[i]) == myset.end())
		{
			count++;
			if (myset.size() < n)
			{
				myset.insert(vec[i]);
				if (interval[vec[i]].empty())
				{
					priority = MAX_INDEX;
				}
				else
				{
					priority = *(interval[vec[i]].begin()) - i;
				}
				bh.push_back({ priority, vec[i] });
			}
			else
			{
				int temp = 0;
				int p = bh[0].first;
				vector<pair<int, unsigned long long>> ::iterator it = bh.begin();
				vector<pair<int, unsigned long long>> ::iterator max_it = bh.begin();
				for (int j = 1; j < bh.size(); j++)
				{
					it++;
					if (bh[j].first > p)
					{
						temp = j;
						p = bh[j].first;
						max_it = it;
					}
				}
				unsigned long long k = bh[temp].second;
				bh.erase(max_it);
				myset.erase(k);
				myset.insert(vec[i]);
				if (interval[vec[i]].empty())
				{
					priority = MAX_INDEX;
				}
				else
				{
					priority = *(interval[vec[i]].begin()) - i;

				}
				bh.push_back({ priority, vec[i] });
			}
		}
		else
		{
			for (int j = 0; j < bh.size(); j++)
			{
				if (bh[j].second == vec[i])
				{
					if (interval[vec[i]].empty())
					{
						priority = MAX_INDEX;
					}
					else
					{
						priority = *(interval[vec[i]].begin()) - i;

					}
					bh[j].first = priority;
					break;
				}
			}
		}
	}
	printf("%d", count);
	return 0;
}
