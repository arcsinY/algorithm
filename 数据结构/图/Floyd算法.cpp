#include<bits\stdc++.h>
using namespace std;
/*
	�ø��������㷨�����·�������Ϊ1���յ�Ϊn
	���룺��һ��n,m��n���㣬��m����
		֮��m������ߵĶ˵��cost
*/
int res[101][101];

int main()
{
	int n, m;
	while (scanf("%d %d", &n, &m) != EOF)
	{
		if (m == 0 && n == 0)
			break;
		for (int i = 1; i <= n; ++i)   //�ڽӾ����ʼ��Ϊ������Լ����Լ��ľ���Ϊ0
		{
			for (int j = 1; j <= n; ++j)
				res[i][j] = INT_MAX;
			res[i][i] = 0;
		}
		for (int i = 0; i < m; ++i)
		{
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			res[a][b] = res[b][a] = c;    //����ͼ������ԳƵ��ڽӾ���
		}
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)   //����j->k����̾��룬ÿ�ΰѶ���i���뵽j->k��·����
			{
				for (int k = 1; k <= n; ++k)
				{
					if ((long)(res[j][i] + res[i][k]) < res[j][k])    //����i��j->k�ľ��������С������
						res[j][k] = res[j][i] + res[i][k];
				}
			}
		}
		printf("%d\n", res[1][n]);
	}
	return 0;
}
