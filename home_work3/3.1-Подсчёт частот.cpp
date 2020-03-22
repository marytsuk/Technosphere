#include <iostream>
#include <string>
#include <vector>
using namespace std;

string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
void bubblesort(vector<int>& a)
{
	bool sorted = false;
	while (!sorted)
	{
		sorted = true;
		for (int i = 0; i < a.size() - 1; i++)
		{
			if (a[i] < a[i + 1])
			{
				int tmp = a[i];
				char c_tmp = alphabet[i];

				a[i] = a[i + 1];
				a[i + 1] = tmp;

				alphabet[i] = alphabet[i + 1];
				alphabet[i + 1] = c_tmp;

				sorted = false;
			}
		}
	}
}
int main()
{
	string str;
	cin >> str;
	vector<int> freq(26);
	int j = 0;
	for (int i = 0; i < str.length(); i++)
	{
		int j = str[i] - 65;
		freq[j]++;
	}

	bubblesort(freq);

	for (int i = 0; i < freq.size(); i++)
	{
		if (freq[i])
		{
			cout << alphabet[i] << " " << freq[i] << endl;
		}
	}

}
