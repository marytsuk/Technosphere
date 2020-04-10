#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct point
{
	double x, y;
	int num;
	point(double X = 0, double Y = 0, int n = 0) : x(X), y(Y), num(n) {}
	bool operator<(const point& obj) const
	{
		return (x < obj.x) || (x == obj.x && y < obj.y);
	}
	double getDistanse(const point& obj)
	{
		return (x - obj.x) * (x - obj.x) + (y - obj.y) * (y - obj.y);
	}
};
struct compare
{
	bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) const
	{
		return p1.first > p2.first || p1.first == p2.first && p1.second < p2.second;
	}
};
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	double r;
	cin >> n >> r;
	vector<point> points(n);
	vector<pair<int, int>> result(n);
	for (int i = 0; i < n; i++)
	{
		double x, y;
		cin >> x >> y;
		points[i] = point(x, y, i);
		result[i].second = i;
	}
	sort(points.begin(), points.end());
	int i1 = 0;
	int i2 = 0;
	for (int i = 0; i < n; i++)
	{
		
		
		while (points[i].x - points[i1].x >= r)
		{
			i1++;
		}
		while (i2 < n && points[i2].x - points[i].x < r)
		{
			i2++;
		}
		for (int j = i1; j < i2; j++)
		{
			if (points[i].getDistanse(points[j]) <= r * r)
			{
				result[points[i].num].first++;
			}
		}
	}
	sort(result.begin(), result.end(), compare());
	for (int i = 0; i < n && i < 10; i++)
	{
		cout << result[i].second << " " << result[i].first - 1 << '\n';
	}
	return 0;
}