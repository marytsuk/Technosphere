#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void bubblesort_by_row(int k, vector<vector<int>>& a)
{
	bool sorted = false;
	while (!sorted)
	{
		sorted = true;
		for (int i = 0; i < a[k].size() - 1; i++)
		{
			if (a[k][i] > a[k][i + 1])
			{
				for (int j = 0; j < a.size(); j++)
				{
					int tmp = a[j][i];
					a[j][i] = a[j][i + 1];
					a[j][i + 1] = tmp;
				}
				sorted = false;
			}
		}
	}
}
void bubblesort_by_column(vector<vector<int>>& a, int m)
{
	bool sorted = false;
	while (!sorted)
	{
		sorted = true;
		for (int i = 0; i < a.size() - 1; i++)
		{
			if (a[i][0] > a[i + 1][0])
			{
				vector<int> tmp(m);
				tmp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = tmp;
				sorted = false;
			}
		}
	}
}
int main()
{
	int n, m;
	cin >> n >> m;

	vector<vector<int>> mat(n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			int c;
			cin >> c;
			mat[i].push_back(c);
		}

	int min_el = (1 << 31) - 1;
	int i_min = 0;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			if (mat[i][j] < min_el)
			{
				min_el = mat[i][j];
				i_min = i;
			}
		}
	bubblesort_by_row(i_min, mat);

	bubblesort_by_column(mat, m);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
}
