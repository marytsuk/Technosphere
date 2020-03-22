#include <iostream>
using namespace std;
char c;

int k1 = 0;
int k2 = 0;
int k3 = 0;
int k4 = 0;
void gc()
{
	c = getchar();
}
void DFA()
{
	enum set { OUT, IN1, IN2, IN3, IN4, IN5, IN6, IN7 } state = OUT;
	do
	{
		gc();
		if (state == OUT && c == '(')
		{
			gc();
			if (c == '*')
			{
				state = IN2;
			}
			else 
			{
				state = OUT;
				cin.putback(c);
			}
		}
		else if (state == IN2 && c == '*')
		{
			state = IN3;
		}
		else if (state == IN3 && c == ')')
		{
			state = OUT;
			k1++;
		}
		else if (state == IN3)
		{
			state = IN2;
		}

		else if (state == OUT && c == '{') 
		{ 
			state = IN4; 
		}
		else if (state == IN4 && c == '}')
		{
			state = OUT;
			k2++;
		}
		else if (state == OUT && c == 39)
		{
			state = IN5;
		}
		else if (state == IN5 && c == 39)
		{
			state = OUT;
			k4++;
		}
		if (state == OUT && c == '/')
		{
			gc();
			if (c == '/')
			{
				state = IN7;
			}
			else 
			{
				state = OUT;
				cin.putback(c);
			}
		}
		else if (state == IN7 && c == '\n')
		{
			state = OUT;
			k3++;
		}
	} while (c != EOF);
}
int main()
{
	DFA();
	cout << k1 << " " << k2 << " " << k3 << " " << k4;

	return 0;
}