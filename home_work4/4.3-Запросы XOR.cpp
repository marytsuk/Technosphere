#include <iostream>
#include <vector>
using namespace std;
struct intervalTree
{
	vector<unsigned int > body;
	unsigned int C;
	intervalTree(unsigned int n)
	{
		body.resize(n * 4, 0);
		int count = 0;
		body.resize(4 * n, 0);
		C = 0;
		while (n)
		{
			count += n & 1;
			n >>= 1u;
			++C;
		}
		C = 1u << (count == 1 ? C - 1 : C);
	}
	void insert(unsigned int index, unsigned int  value)
	{
		body[index + C] = value;
		propogate(index);
	}
	void propogate(unsigned int index)
	{
		unsigned int neighbour_index;
		int parent;
		index += C;
		while (index > 1)
		{
			if (index & 1)
			{
				neighbour_index = index - 1;
			}
			else
			{
				neighbour_index = index + 1;
			}
			parent = body[index] ^ body[neighbour_index];
			body[index / 2] = parent;
			index /= 2;
		}
	}
	unsigned int  op_xor(unsigned int left, unsigned int right)
	{
		int res = 0;
		if (left & 1)
			res ^= body[left++];
		if (!(right & 1))
			res ^= body[right--];
		if (right > left)
			res ^= op_xor(left / 2, right / 2);
		return res;
	}
};
int main()
{
	unsigned int n;
	unsigned int m;
	scanf("%u %u", &n, &m);
	intervalTree tree(n);
	for (unsigned int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		tree.insert(i, x);
	}
	unsigned int k;
	for (unsigned int i = 0; i < m; i++)
	{
		unsigned int op;
		unsigned int  x, y;
		scanf("%u %d %d", &op, &x, &y);
		if (op == 1)
		{
			printf("%d\n", tree.op_xor(x + tree.C, y + tree.C));
		}
		else if (op == 2)
		{
			tree.insert(x, y);
		}
	}
	
	return 0;
}