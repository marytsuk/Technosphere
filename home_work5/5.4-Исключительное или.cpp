#include <iostream>
using namespace std;
class tree
{
	tree* chld[2];
	unsigned long long x;
public:
	tree()
	{
		for (int i = 0; i < 2; i++)
		{
			chld[i] = nullptr;
		}
		x = 0;
	}
	unsigned long long getMax(unsigned long long value)
	{
		tree* tmp = this;
		for (int i = 31; i >= 0; i--)
		{
			int j = (value >> i) & 1 ? 0 : 1;
			if (tmp->chld[j])
			{
				tmp = tmp->chld[j];
			}
			else
			{
				tmp = tmp->chld[j ? 0 : 1];
			}
		}
		return tmp->x;
	}
	void insert(unsigned long long value)
	{
		tree* tmp = this;

		for (int i = 31; i >= 0; i--)
		{
			int j = (value >> i) & 1;
			if (tmp->chld[j])
			{
				tmp = tmp->chld[j];
			}
			else
			{
				tmp->chld[j] = new tree;
				tmp = tmp->chld[j];
			}
		}
		tmp->x = value;
	}
	friend void erase(tree* tr, unsigned long long value, int h)
	{
		if (erase_bit(tr->chld[value >> h - 1], value, h - 1))
			tr->chld[value >> h - 1] = nullptr;
	}
	friend bool erase_bit(tree* tr, unsigned long long value, int h);
	
};
bool erase_bit(tree* tr, unsigned long long value, int h)
{
	tree* tmp = tr;
	if (!h)
	{
		delete tmp;
		return 1;
	}

	int i = (value >> (h - 1)) & 1u;
	if (tmp == nullptr)
	{
		return 0;
	}

	if (erase_bit(tmp->chld[i], value, h - 1))
	{
		if (tmp->chld[i ? 0 : 1])
		{
			tmp->chld[i] = nullptr;
			return 0;
		}
		else
		{
			delete tmp;
			return 1;
		}
	}
	return 0;
}
int main()
{
	unsigned long long n;
	scanf("%llu", &n);
	tree* tr = new tree;
	for (unsigned long long i = 0; i < n; i++)
	{
		unsigned long long x, y;
		scanf("%llu %llu", &x, &y);
		if (x == 1)
		{
			tr->insert(y);
		}
		else
		if (x == 2)
		{
			erase(tr, y, 32);
		}
		if (x == 3)
		{
			printf("%llu\n", tr->getMax(y));
		}
	}
	return 0;
}