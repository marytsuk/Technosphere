#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n1, n2;
	cin >> n1 >> n2;

	vector<int> arr1(n1);
	vector<int> arr2(n2);

	for (int i = 0; i < n1; i++)
	{
		cin >> arr1[i];
	}
	for (int i = 0; i < n2; i++)
	{
		cin >> arr2[i];
	}

	int i = 0, j = 0;
	int count = 0;
	while (i < n1 && j < n2)
	{
		if (arr1[i] == arr2[j])
		{
			count++;
			i++;
			j++;
		}
		else
			if (arr1[i] < arr2[j])
				i++;
			else
				j++;
	}
	cout << count;
}
