#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <string>
#include <queue>
#include <map>
#include <limits.h>
#include <math.h>
using namespace std;
int a[600];
bool gcd2(int a, int b);
bool gcd(int a, int b);
int main()
{
	int n;
	int res = 0;
	while (scanf("%d", &n) != EOF)
	{
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &a[i]);
		}
		sort(a, a + n);
		for (int i = 0; i < n; ++i)
		{
			for (int j = i+1; j < n; ++j)
			{
				if (gcd2(a[j], a[i]))
					continue;
				++res;
			}
		}
		printf("%d\n", res);
	}
	return 0;
}

bool gcd2(int a, int b)   //是否存在>1的公因数，是返回true
{
	int t = 0;
	while (a)
	{
		t = a;
		a = b%a;
		b = t;
	}
	if (b == 1)   //最后的b是最大公约数
		return false;
	else 
		return true;
}

bool gcd(int a, int b)   //返回最大公约数
{
	if (b == 0)
		return a;
	else
		return gcd(b, a%b);
}
