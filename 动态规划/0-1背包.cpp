#include <stdio.h>

using namespace std;
int w[101];   //物体编号从1开始，重量
int v[101];   //价值
int dp[101][1001];    //dp[i][j]表示从1~i中选出重量不超过j的最大价值
int main()
{
	int c, n;    //c是背包体积，n是物品种类
	while (scanf("%d %d", &c, &n) != EOF)
	{
		for (int i = 1; i <= n; ++i)
			scanf("%d %d", &w[i], &v[i]);
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= c; ++j)
			{
				if (j < w[i])   //可用空间放不下这一物体
					dp[i][j] = dp[i - 1][j];
				else      //是否选这一物体两种情况
					dp[i][j] = dp[i - 1][j] > (dp[i - 1][j - w[i]] + v[i]) ? dp[i - 1][j] : dp[i - 1][j - w[i]] + v[i];
			}
		}
		printf("%d\n", dp[n][c]);
	}
	return 0;
}
