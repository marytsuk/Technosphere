#include <iostream>
#include <string>

using namespace std;

int check(string& s, int& i, bool black)
{
	int count = 0;
	switch (s[i + 1])
	{
	case 'g':
		i+=2;
		while (s[i] == ',')
		{
			count += check(s, ++i, black);
		}
		i++;
		break;
	case 'w':
		i+=2;
		if (black)
			count++;
		while (s[i] == ',')
		{
			
			count += check(s, ++i, black);
		}
		i++;
		break;
	case 'b':
		black = true;
		i+=2;
		while (s[i] == ',')
		{
			
			count += check(s, ++i, black);
		}
		i++;
		break;
	}
	return count;
}

int main()
{
	string str;
	cin >> str;
	int i = 0;
	cout << check(str, i, false) << endl;
	return 0;
}
