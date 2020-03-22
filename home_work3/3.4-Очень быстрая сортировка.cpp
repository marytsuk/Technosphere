#include <iostream>
#include <vector>
using namespace std;
union
{
	unsigned int a;
	unsigned short b[2];
} digit;
const int C = 65536;
vector<vector<unsigned short>> vec(C);
int main()
{

	unsigned int N;
	unsigned int K, M, L;
	scanf("%u %u %u %u", &N, &K, &M, &L);
	digit.a = K;
	vec[digit.b[1]].push_back(digit.b[0]);
	for (unsigned int i = 0; i < N - 1; i++)
	{
		digit.a = (unsigned int)((digit.a * (unsigned long long)M) & 0xFFFFFFFFU) % L;
		vec[digit.b[1]].push_back(digit.b[0]);
	}

	unsigned long long sum = 0;
	int c = 1;
	for (unsigned int i = 0; i < C; i++)
	{
		if (!vec[i].empty())
		{
			vector<unsigned int> counter(C, 0);
			for (int j = 0; j < vec[i].size(); j++)
			{
				counter[vec[i][j]]++;
			}
			for (unsigned int j = 0; j < C; j++)
			{
				if (counter[j])
				{
					digit.b[1] = (unsigned short)i;
					digit.b[0] = (unsigned short)j;
					sum += digit.a * (unsigned long long)((counter[j] + c % 2) / 2);
					c += counter[j];
				}
			}

		}

	}

	printf("%u", (unsigned int)(sum % L));
	return 0;
}
