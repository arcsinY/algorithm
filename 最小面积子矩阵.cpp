//一个N*M的矩阵，找出这个矩阵中元素和不小于K的面积最小的子矩阵（矩阵中元素个数为矩阵面积） 
//类似于动态规划的最小子矩阵，将矩阵的若干行加到一行上，将矩阵问题转化为数组问题
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
int martix[101][101];
int sum[101]; 
int shortest(int m, int k);
int main()
{
	int n, m, k;
	while (scanf("%d %d %d", &n, &m, &k) != EOF)
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
				scanf("%d", &martix[i][j]);
		}
		int area = INT_MAX;   //面积
		for (int i = 0; i < n; ++i)   //逐行搜索
		{
			for (int j = 0; j < m; ++j)   //数组清零
				sum[j] = 0;
			for (int a = i; a < n; ++a)    //从当前行合并到最后一行
			{
				for (int b = 0; b < m; ++b)
					sum[b] += martix[a][b];
				int len = shortest(m, k);  //子矩阵的宽度
				if (len != INT_MAX)
				{
					if (len*(a - i + 1) < area)  //比现有面积小
						area = len*(a - i + 1);
				}
			}
		}
		if (area == INT_MAX)
			printf("-1\n");
		else
			printf("%d\n", area);
	}
	return 0;
}

int shortest(int m,int k)   //在长度为m的数组sum中求和不小于k的最短子数组的长度
{
	int from = 0, to = 0;  //子数组起点和终点
	int len = INT_MAX;  //子数组长度
	int x = 0;   //子数组元素和
	while (to < m)
	{
		while (x < k && to < m)   //找到一个子数组
		{
			x += sum[to];
			++to;
		}
		while (x >= k && from < to - 1)
		{
			if (len > to - from)
				len = to - from;    //找到更短的
			x -= sum[from];
			++from;    //起点后移
		}
		if (from == to - 1)
			return 1;
	}
	return len;
}
