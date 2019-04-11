#include<bits\stdc++.h>
using namespace std;
/*
	�������������ж�һ��ͼ���Ƿ��л�
	��������n,m������n������m����
	֮��m����m���ߵĻ�β�ͻ�ͷ
*/
queue<int> q;   //����������ɣ����������ȳ��޹أ�Ҳ������ջ
vector<int> g[100];   //�ڽӱ�
int indegree[100];  //indegree[i]��ʾ����i�����
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
				indegree[g[nowp][i]]--;   //�����붥��nowp�����ĵ����-1
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
