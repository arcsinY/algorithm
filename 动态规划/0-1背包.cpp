#include <stdio.h>

using namespace std;
int w[101];   //�����Ŵ�1��ʼ������
int v[101];   //��ֵ
int dp[101][1001];    //dp[i][j]��ʾ��1~i��ѡ������������j������ֵ
int main()
{
	int c, n;    //c�Ǳ��������n����Ʒ����
	while (scanf("%d %d", &c, &n) != EOF)
	{
		for (int i = 1; i <= n; ++i)
			scanf("%d %d", &w[i], &v[i]);
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= c; ++j)
			{
				if (j < w[i])   //���ÿռ�Ų�����һ����
					dp[i][j] = dp[i - 1][j];
				else      //�Ƿ�ѡ��һ�����������
					dp[i][j] = dp[i - 1][j] > (dp[i - 1][j - w[i]] + v[i]) ? dp[i - 1][j] : dp[i - 1][j - w[i]] + v[i];
			}
		}
		printf("%d\n", dp[n][c]);
	}
	return 0;
}
