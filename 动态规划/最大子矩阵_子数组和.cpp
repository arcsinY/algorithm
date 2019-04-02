#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
int n;
int mat[101][101];

int maxSumInArray(int* a, int n);    //n�����������������������
int maxSumInMatrix(int a[][101], int n);  //n*n�ľ�����������Ӿ���

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

int maxSumInArray(int* a, int n)   //����n��Ԫ�ص�����a������������
{
	int dp[101];   //dp[n]:��a[n]Ϊ��β������������
	dp[0] = a[0];
	for (int i = 1; i < n; ++i)
	{
		dp[i] = dp[i - 1] + a[i] > a[i] ? dp[i - 1] + a[i] : a[i];
	}
	int res = dp[0];
	for (int i = 1; i < n; ++i)  //�ҳ�dp����������Ԫ�ؼ�Ϊ���
	{
		if (dp[i] > res)
			res = dp[i];
	}
	return res;
}

int maxSumInMatrix(int a[][101], int n)
{
	int res = INT_MIN;
	for (int i = 0; i < n; ++i)    //��������
	{
		int t[101];
		for (int j = 0; j < n; ++j)   //�����i�е�t
		{
			t[j] = a[i][j];
		}
		res = res > maxSumInArray(t, n) ? res : maxSumInArray(t, n);   //��i�е����������
		for (int j = i + 1; j < n; ++j)   //��i��֮���ÿ�м���t
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