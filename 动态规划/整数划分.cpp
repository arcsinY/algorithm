#include <bits\stdc++.h>
int dp[21][21];

int divide(int n)  //整数n有多少种划分。dp[i][j]:对i划分，所有的划分数不超过j
{
	dp[1][1] = 1;
	for (int i = 1; i <= 20; ++i)
	{
		for (int j = 1; j <= 20; ++j)
		{
			if (i == j)
				dp[i][j] = 1 + dp[i][j - 1];   //划出一个1
			else if (i > j)
				dp[i][j] = dp[i - j][j] + dp[i][j - 1];   //划分中包括j和不包括j
			else if (i < j)
				dp[i][j] = dp[i][i];   //所有的划分数不会超过i的
			else   //j==1的情况
				dp[i][j] = 1;   //只能划分为i个1相加
		}
	}
	return dp[n][n];
}


int divide(int n, int m)  //整数n划分为m个数的和。dp[i][j]:用j个数对i划分
{
	dp[1][1] = 1;
	for (int i = 1; i <= 20; ++i)
	{
		for (int j = 1; j <= 20; ++j)
		{
			if (i == j)
				dp[i][j] = 1;   //划分为j个1
			else if (j == 1)
				dp[i][j] = 1;   //划分为一个i
			else
				dp[i][j] = dp[i - 1][j - 1] + dp[i - j][j];   //含1的划分和不含1的划分
		}
	}
	return dp[n][m];
}

int main()
{
	int n, m;
	while (scanf("%d %d", &n, &m) != EOF)
	{
		printf("%d\n", divide(n));
		printf("%d\n", divide(n, m));
	}
	return 0;
}
