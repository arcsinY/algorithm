#include <stdio.h>
int main()
{
	int n; int a[101];
	int left[101], right[101];   //left[i]表示从左往右看最以a[i]结尾的最长上升子序列的长度，right[i]表示从右往左看
	while (scanf("%d", &n) != EOF)
	{
		for (int i = 0; i < n; ++i)
			scanf("%d", &a[i]);
		for (int i = 0; i < n; ++i)    //从a[0]~a[i]中寻找子序列
		{
			left[i] = 1;
			for (int j = 0; j <= i; ++j)
			{
				if (a[j] < a[i])   //在这一子序列中，让a[j]之后接a[i]
					left[i] = left[i] > left[j] + 1 ? left[i] : left[j] + 1;
			}
		}
		for (int i = n - 1; i >= 0; --i)
		{
			right[i] = 1;
			for (int j = n - 1; j >= i; --j)
			{
				if (a[j] < a[i])
					right[i] = right[i] > right[j] + 1 ? right[i] : right[j] + 1;
			}
		}
	}
	return 0;
}
