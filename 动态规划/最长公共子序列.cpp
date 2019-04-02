#include <stdio.h>
#include <string.h>

char a[101], b[101];
int dp[101][101];    //串长为i，j的两个串的最长公共子序列长度为dp[i][j],dp[0][i]=dp[i][0]=0
int main()
{
	while (scanf("%s %s", a, b) != EOF)
	{
		int len_a = strlen(a), len_b = strlen(b);
		for (int i = 1; i <= len_a; ++i)
		{
			for (int j = 1; j <= len_b; ++j)
			{
				if (a[i - 1] == b[j - 1])   //a[0]~a[i-1]的串长为i
					dp[i][j] = dp[i - 1][j - 1] + 1;
				else
					dp[i][j] = dp[i - 1][j] > dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1];
			}
		}
		printf("%d\n", dp[len_a][len_b]);
	}
	return 0;
}
