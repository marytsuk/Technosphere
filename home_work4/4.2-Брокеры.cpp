#include <iostream>
#include <vector>
using namespace std;
struct binary_heap 
{
	vector<unsigned long long> body;
	unsigned long long bodysize;
	unsigned long long numnodes;
	binary_heap(unsigned long long maxsize) 
	{
		bodysize = maxsize;
		body.resize(maxsize + 1);
		numnodes = 0;
	}
	void swap(unsigned long long a, unsigned long long b) 
	{
		unsigned long long temp = body[a];
		body[a] = body[b];
		body[b] = temp;
	}
	unsigned long long insert(unsigned long long node)
	{
		if (numnodes >= bodysize) 
		{
			return 0; // или расширяем.
		}
		body[++numnodes] = node;
		for (unsigned long long i = numnodes; i > 1 && body[i] < body[i / 2]; i /= 2)
		{
			swap(i, i / 2);
		}
		return 1;
	}
	unsigned long long fetchMin() 
	{
		return numnodes == 0 ? 0 : body[1];
	}
	void heapify(unsigned long long index) 
	{
		for (;;) 
		{
			unsigned long long left = index + index;
			unsigned long long right = left + 1;
			unsigned long long largest = index;
			if (left <= numnodes && body[left] < body[index])
				largest = left;
			if (right <= numnodes && body[right] < body[largest])
				largest = right;
			if (largest == index) break;
			swap(index, largest);
			index = largest;
		}
	}
	unsigned long long getMin()
	{
		unsigned long long tmp = fetchMin();
		if (tmp != -1)
		{
			body[1] = body[numnodes];
			numnodes--;
			heapify(1);
			return tmp;
		}
	}
};

int main()
{
	unsigned long long n;
	scanf("%llu", &n);
	binary_heap obj(n);
	for (unsigned long long i = 0; i < n; i++)
	{
		unsigned long long x;
		scanf("%llu", &x);
		obj.insert(x);
	}
	unsigned long long sum_per = 0;
	for (unsigned long long i = 0; i < n - 1; i++)
	{
		unsigned long long sum = obj.getMin() + obj.getMin();
		obj.insert(sum);
		sum_per += sum;
	}
	printf("%0.2f", (double)sum_per / 100);
	return 0;
}