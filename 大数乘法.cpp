#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <string>
#include <queue>
#include <limits.h>
#include <math.h>
using namespace std;
int res[10000];
int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		int index = 0;   //数组下标
		int up = 0;    //进位
		res[0] = 1;
		for (int i = 1; i <= n; ++i)      //阶乘
		{
			for (int j = 0; j <= index; ++j)    //每次乘法
			{
				int t = (res[j] * i + up) / 10;   //本次运算的进位
				res[j] = (res[j] * i + up) % 10;
				up = t;
			}
			while (up)
			{
				res[++index] = up % 10;
				up /= 10;
			}
		}
		for (int i = index; i >= 0; --i)   //输出
		{
			printf("%d", res[i]);
		}
		printf("\n");
	}
	return 0;
}
