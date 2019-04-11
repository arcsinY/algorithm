#include<bits\stdc++.h>
using namespace std;
/*
	用弗洛伊德算法求最短路径，起点为1，终点为n
	输入：第一行n,m，n个点，共m条边
		之后m行输入边的端点和cost
*/
int res[101][101];

int main()
{
	int n, m;
	while (scanf("%d %d", &n, &m) != EOF)
	{
		if (m == 0 && n == 0)
			break;
		for (int i = 1; i <= n; ++i)   //邻接矩阵初始化为无穷大，自己到自己的距离为0
		{
			for (int j = 1; j <= n; ++j)
				res[i][j] = INT_MAX;
			res[i][i] = 0;
		}
		for (int i = 0; i < m; ++i)
		{
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			res[a][b] = res[b][a] = c;    //无向图，构造对称的邻接矩阵
		}
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)   //计算j->k的最短距离，每次把顶点i加入到j->k的路径上
			{
				for (int k = 1; k <= n; ++k)
				{
					if ((long)(res[j][i] + res[i][k]) < res[j][k])    //加入i后j->k的距离比现在小，更新
						res[j][k] = res[j][i] + res[i][k];
				}
			}
		}
		printf("%d\n", res[1][n]);
	}
	return 0;
}
