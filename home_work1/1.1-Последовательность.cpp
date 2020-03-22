#include <iostream>
#include <string>
using namespace std;
string str = "abcdefghijklmnopqrstuvwxyz";
char get_letter(unsigned long k)
{
	return str[k];
}
int main()
{
	unsigned long x, y, z;
	cin >> x >> y >> z;
	for (unsigned long i = y; i <= z; i++)
	{
		unsigned long n = i;
		unsigned long k = x;
		while (n != 1)
		{
			if (n <= (1 << (k - 1)))
			{
				n--;
				k--;
						
			}
			else
			{
				n -= (1 << (k - 1));
				k--;
			}
			
			
		}
		cout << get_letter(k - 1);
	}
	return 0;
}
