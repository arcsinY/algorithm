#include<bits\stdc++.h>
using namespace std;
/*
	用迪杰斯特拉算法求最短路径，起点为1
	输入：第一行n,m，n个点，共m条边
		之后m行输入边的端点和cost
*/
typedef struct
{
	int vex;
	int cost;
}edge;
vector<edge> arr[100];   //用数组作为邻接表
int d[100];   //d[i]:从起点开始，到i点的最短距离
bool final[100];  //若final[i] == true，则起点到i点的最短距离已经求得

int main()
{
	int n, m;
	while (scanf("%d %d", &n, &m)!= EOF)
	{
		if (n == 0 && m == 0)
			break;
		for (int i = 1; i <= n; ++i)
			d[i] = INT_MAX;
		memset(final, 0, sizeof(final));
		for (int i = 1; i <= n; ++i)
			arr[i].clear();
		for (int i = 1; i <= m; ++i)
		{
			int a, b, t;
			scanf("%d %d %d", &a, &b, &t);
			edge te = { b,t };   //输入的这条边
			arr[a].push_back(te);   //加入a点的链表中
			te = { a,t };
			arr[b].push_back(te);  //若是无向图，还要加入b点的链表中
		}
		d[1] = 0; final[1] = true;   //一开始只有起点
		for (int i = 0; i < arr[1].size(); ++i)    //能从起点直接到达的顶点，可得出路径长度
			d[arr[1][i].vex] = arr[1][i].cost;
		for (int i = 1; i <= n; ++i)
			q.push(d[i]);   //建立一个堆
		for (int i = 1; i < n; ++i)   //n-1次循环
		{
			int min = INT_MAX;   //从起点到newp的距离
			int newp;
			for (int j = 1; j <= n; ++j)   //找出未在集合s的点到起点的最短距离
			{
				if (final[j] == false)
				{
					if (d[j] < min)
					{
						min = d[j];
						newp = j;
					}
				}
			}
			final[newp] = true;
			for (int j = 0; j < arr[j].size(); ++j)
			{
				int tp = arr[newp][j].vex;    //与newp相连的顶点
				int tc = arr[newp][j].cost;   //newp->j的距离
				if (final[j] == false)
				{
					if (d[j] < min + arr[newp][j].cost)
					{
						d[j] = min + arr[newp][j].cost;
					}
				}
			}
		}
		printf("%d\n", d[n]);
	}
	return 0;
}
