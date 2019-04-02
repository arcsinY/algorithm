#include <bits\stdc++.h>
int dp[21][21];

int divide(int n)  //����n�ж����ֻ��֡�dp[i][j]:��i���֣����еĻ�����������j
{
	dp[1][1] = 1;
	for (int i = 1; i <= 20; ++i)
	{
		for (int j = 1; j <= 20; ++j)
		{
			if (i == j)
				dp[i][j] = 1 + dp[i][j - 1];   //����һ��1
			else if (i > j)
				dp[i][j] = dp[i - j][j] + dp[i][j - 1];   //�����а���j�Ͳ�����j
			else if (i < j)
				dp[i][j] = dp[i][i];   //���еĻ��������ᳬ��i��
			else   //j==1�����
				dp[i][j] = 1;   //ֻ�ܻ���Ϊi��1���
		}
	}
	return dp[n][n];
}


int divide(int n, int m)  //����n����Ϊm�����ĺ͡�dp[i][j]:��j������i����
{
	dp[1][1] = 1;
	for (int i = 1; i <= 20; ++i)
	{
		for (int j = 1; j <= 20; ++j)
		{
			if (i == j)
				dp[i][j] = 1;   //����Ϊj��1
			else if (j == 1)
				dp[i][j] = 1;   //����Ϊһ��i
			else
				dp[i][j] = dp[i - 1][j - 1] + dp[i - j][j];   //��1�Ļ��ֺͲ���1�Ļ���
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
