#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <stack>
using namespace std;
/*
1+2*3+4    
1+2/2 + 1    
1+2-3    
*/
bool cmp(char a, char b)
{
	if (a == '+' || a == '-')
	{
		if(b == '*' || b == '/')
			return false;
		return false;
	}
	else
	{
		if (b == '+' || b == '-')
			return true;
		else
			return false;
	}
}
int main()
{
	char s[101];
	while (gets_s(s))
	{
		if (strcmp(s, "0") == 0)
			return 0;
		stack<int> num;
		stack<char> op;
		for (int i = 0; i < strlen(s); ++i)
		{
			if (s[i] == ' ')
				continue;
			if (s[i] >= '0' && s[i] <= '9')
				num.push(s[i] - '0');
			else
			{
				if (op.empty() == true)
				{
					op.push(s[i]);
					continue;
				}
				else
				{
					if (cmp(op.top(), s[i]) == true)
					{
						int a = num.top();
						num.pop();
						int b = num.top();
						num.pop();
						char c = op.top();
						op.pop();
						if (c == '*')
							a *= b;
						else
							a /= b;
						num.push(a);
						op.push(s[i]);
					}
					else
						op.push(s[i]);
				}
			}
		}
		if(op.empty())
			printf("%d\n", num.top());
		else
		{
			while (op.empty() == false)
			{
				int a = num.top();
				num.pop();
				int b = num.top();
				num.pop();
				char c = op.top();
				op.pop();
				switch (c)
				{
				case '+' :
					b += a;
					break;
				case '-':
					b -= a;
					break;
				case '*':
					b *= a;
					break;
				case '/':
					b /= a;
					break;
				}
				num.push(b);
			}
			printf("%d\n", num.top());
		}
	}
	return 0;
}
