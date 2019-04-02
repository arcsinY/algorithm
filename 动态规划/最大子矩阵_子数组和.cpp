#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
int n;
int mat[101][101];

int maxSumInArray(int* a, int n);    //n个数的数组中找最大子数组
int maxSumInMatrix(int a[][101], int n);  //n*n的矩阵中找最大子矩阵

int main()
{
	while (scanf("%d", &n) != EOF)
	{
		memset(mat, 0, sizeof(mat));
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				scanf("%d", &mat[i][j]);
			}
		}
		printf("%d\n", maxSumInMatrix(mat, n));
	}
	return 0;
}

int maxSumInArray(int* a, int n)   //返回n个元素的数组a的最大子数组和
{
	int dp[101];   //dp[n]:以a[n]为结尾的最大子数组和
	dp[0] = a[0];
	for (int i = 1; i < n; ++i)
	{
		dp[i] = dp[i - 1] + a[i] > a[i] ? dp[i - 1] + a[i] : a[i];
	}
	int res = dp[0];
	for (int i = 1; i < n; ++i)  //找出dp数组中最大的元素即为结果
	{
		if (dp[i] > res)
			res = dp[i];
	}
	return res;
}

int maxSumInMatrix(int a[][101], int n)
{
	int res = INT_MIN;
	for (int i = 0; i < n; ++i)    //逐行搜索
	{
		int t[101];
		for (int j = 0; j < n; ++j)   //保存第i行到t
		{
			t[j] = a[i][j];
		}
		res = res > maxSumInArray(t, n) ? res : maxSumInArray(t, n);   //第i行的最大子数组
		for (int j = i + 1; j < n; ++j)   //第i行之后的每行加入t
		{
			for (int k = 0; k < n; ++k)
			{
				t[k] += a[j][k];
			}
			res = res > maxSumInArray(t, n) ? res : maxSumInArray(t, n);
		}
	}
	return res;
}