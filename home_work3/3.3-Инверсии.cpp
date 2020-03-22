#include <vector>
#include <stdio.h>
using namespace std;

long long merge_sort(vector<long int> &vec, long long left, long long right)
{
	if (right - left == 1)
		return 0;

	vector<long> temp(right - left);
	long long res = 0;
	long long mid = (right + left) / 2;

	res += merge_sort(vec, left, mid);
	res += merge_sort(vec, mid, right);

	long long j = left, g = mid;

	for (long long i = 0; i < right - left; ++i)
	{
		if (j < mid && g < right)
		{
			if (vec[j] <= vec[g])
			{
				temp[i] = vec[j++];
			}
			else
			{
				res += mid - j;
				temp[i] = vec[g++];
			}
		}
		else if (j == mid)
		{
			temp[i] = vec[g++];
		}
		else
		{
			temp[i] = vec[j++];
		}
	}
	for (long long i = 0; i < temp.size(); i++)
		vec[i + left] = temp[i];
	return res;
}


int main()
{
	long long N;
	scanf("%lld", &N);
	vector<long int> vec(N);

	for (long long i = 0; i < N; ++i)
		scanf("%ld", &vec[i]);

	printf("%lld", merge_sort(vec, 0, N));
	return 0;
}
