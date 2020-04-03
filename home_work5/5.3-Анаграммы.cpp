#include <iostream>
#include <set>
#include <vector>
#include <stdio.h>
#include <string.h>
using namespace std;
int main()
{
	int n;
	scanf("%d", &n);
	
	set<vector<int>> myset;
	for (int i = 0; i < n; i++)
	{
		char str[10000];
		vector<int> myvector(26, 0);
		scanf("%s", str);
		int len = strlen(str);
		for (int j = 0; j < len; j++)
		{
			myvector[str[j] - 'A']++;
		}
		myset.insert(myvector);
	}
	printf("%ld", myset.size());
	return 0;
}