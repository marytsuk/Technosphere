#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

struct point
{
	int x, y;
	point(int X, int Y)
	{
		x = X;
		y = Y;
	}
};

double dist(const point &A, const point &B)
{
	return sqrt(0.0 + (A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}
int n;
vector<point> mas;
vector<int> mystack;
double P;
int orient(const point &A, const point &B, const point &C)
{
	return A.x * (B.y - C.y) + B.x * (C.y - A.y) + C.x * (A.y - B.y);
}

bool isInside(const point &p1, const point &p, const point &p2)
{
	return (p1.x <= p.x && p.x <= p2.x && p1.y <= p.y && p.y <= p2.y);
}
void Jarvis(const vector<point> &mas, vector<int> &convex_hull)
{
	int base = 0;
	for (int i = 1; i < n; i++)
	{
		if (mas[i].y < mas[base].y)
		{
			base = i;
		}
		else
			if (mas[i].y == mas[base].y && mas[i].x < mas[base].x)
				base = i;
	}
	mystack.push_back(base);

	int first = base;
	int cur = base;
	do
	{
		int next = (cur + 1) % n;
		for (int i = 0; i < n; i++)
		{
			int sign = orient(mas[cur], mas[next], mas[i]);
			if (sign < 0)
				next = i;
			else if (sign == 0)
			{
				if (isInside(mas[cur], mas[next], mas[i]))
					next = i;
			}
		}
		cur = next;
		mystack.push_back(next);
	} while (cur != first);


}
void solve()
{
	Jarvis(mas, mystack);
	for (int i = 0; i < mystack.size() - 1; i++)
		P += dist(mas[mystack[i]], mas[mystack[i + 1]]);
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		mas.push_back(point(x, y));
	}
	solve();

	printf("%0.2f", P);
	return 0;
}
