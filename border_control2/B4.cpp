#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
long long MAX = 1000000000000000001;
long long MIN = -1000000000000000001;
struct point
{
	long long x, y, z;
	point(long long X = 0, long long Y = 0, long long Z = 0) : x(X), y(Y), z(Z) {}
	bool operator < (const point& obj) const
	{
		return x < obj.x || ((x == obj.x && y < obj.y) || (y == obj.y && z < obj.z));

	}
};
int main()
{
	int n;
	cin >> n;
	vector<point> arr(n);
	set<point> myset;
	point max_point(MIN, MIN, MIN);
	point min_point(MAX, MAX, MAX);
	point mid_point;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i].x >> arr[i].y >> arr[i].z;
		myset.insert(arr[i]);
		max_point.x = max(max_point.x, arr[i].x);
		max_point.y = max(max_point.y, arr[i].y);
		max_point.z = max(max_point.z, arr[i].z);

		min_point.x = min(min_point.x, arr[i].x);
		min_point.y = min(min_point.y, arr[i].y);
		min_point.z = min(min_point.z, arr[i].z);
	}
	mid_point.x = max_point.x + min_point.x;
	mid_point.y = max_point.y + min_point.y;
	mid_point.z = max_point.z + min_point.z;

	for (int i = 0; i < n; i++)
	{
		if (myset.find(point(mid_point.x - arr[i].x, mid_point.y - arr[i].y, mid_point.z - arr[i].z)) == myset.end())
		{
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;
	
}