#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
int main()
{
	int m, n;
	cin >> m >> n;
	vector<string> names;
	vector<int> scores;
	map<int, vector<string>> mymap;
	map<string, int> persons;
	for (int i = 0; i < n; i++)
	{
		string name;
		int score;
		cin >> name >> score;
		mymap[score].push_back(name);
		persons[name] = 0;
	}
	int count = 0;
	map <int, vector<string>> ::reverse_iterator it;
	for (it = mymap.rbegin(); it != mymap.rend(); it++) 
	{  
		for (int i = 0; i < it->second.size(); i++)
		{
			if (persons[it->second.at(i)])
				continue;
			else
			{
				cout << it->second.at(i) << endl;
				persons[it->second.at(i)]++;
				count++;
				if (count == m)
				{
					return 0;
				}
			}
		}
	}
	return 0;
}
 
