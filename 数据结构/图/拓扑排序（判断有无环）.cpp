#include<bits\stdc++.h>
using namespace std;
/*
	利用拓扑排序判断一个图中是否有环
	首先输入n,m，代表n个顶点m条边
	之后m行是m条边的弧尾和弧头
*/
queue<int> q;   //借助队列完成，这与先入先出无关，也可以用栈
vector<int> g[100];   //邻接表
int indegree[100];  //indegree[i]表示顶点i的入度
int main()
{
	int n, m;
	while (scanf("%d %d", &n, &m) != EOF)
	{
		if (n == 0 && m == 0)
			break;
		memset(indegree, 0, sizeof(indegree));
		for (int i = 1; i <= n; ++i)
			g[i].clear();
		while (q.empty() == false) 
			q.pop();
		for (int i = 0; i < m; ++i)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			indegree[b]++;
			g[a].push_back(b);
		}
		for (int i = 1; i <= n; ++i)
		{
			if (indegree[i] == 0)
				q.push(i);
		}
		int cnt = 0;
		while (q.empty() == false)
		{
			int nowp = q.front();
			q.pop();
			++cnt;
			for (int i = 0; i < g[nowp].size(); ++i)
			{
				indegree[g[nowp][i]]--;   //所有与顶点nowp相连的点入读-1
				if (indegree[g[nowp][i]] == 0)
					q.push(g[nowp][i]);
			}

		}
		if (cnt == n)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
