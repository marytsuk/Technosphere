#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n;
	cin >> n;
	bool if_odd = true;
	unsigned long sum = 0; 
	unsigned long tmp;
	
	vector<unsigned long> digits(n);
	
	for (int i = 0; i < n; i++)
	{
		cin >> digits[i];
	}

	cin >> tmp;

	int j1 = 0;
	int j2 = 0;

	for (int i = 0; i < 2 * n; i++)
	{
		if (j1 < n && j2 < n)
		{
			if (tmp < digits[j1])
			{
				if (if_odd)
				{
					sum += tmp;
					if_odd = false;
				}
				else
				{
					if_odd = true;
				}

				j2++;

				if (j2 < n)
				{
					cin >> tmp;
				}
			}
			else
			{
				if (if_odd)
				{
					sum += digits[j1];
					if_odd = false;
				}
				else
				{
					if_odd = true;
				}

				j1++;
			}
		}
		else
		{
			if (j2 < n)
			{
				if (if_odd)
				{
					sum += tmp;
					if_odd = false;
				}
				else
				{
					if_odd = true;
				}

				j2++;
				if (j2 < n)
				{
					cin >> tmp;
				}
			}
			else
			{
				if (if_odd)
				{
					sum += digits[j1];
					if_odd = false;
				}
				else
				{
					if_odd = true;
				}

				j1++;
			}
		}
	}
	cout << sum % 1000000000;
	return 0;
}