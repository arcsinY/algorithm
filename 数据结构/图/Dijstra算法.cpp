#include<bits\stdc++.h>
using namespace std;
/*
	�õϽ�˹�����㷨�����·�������Ϊ1
	���룺��һ��n,m��n���㣬��m����
		֮��m������ߵĶ˵��cost
*/
typedef struct
{
	int vex;
	int cost;
}edge;
vector<edge> arr[100];   //��������Ϊ�ڽӱ�
int d[100];   //d[i]:����㿪ʼ����i�����̾���
bool final[100];  //��final[i] == true������㵽i�����̾����Ѿ����

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
			edge te = { b,t };   //�����������
			arr[a].push_back(te);   //����a���������
			te = { a,t };
			arr[b].push_back(te);  //��������ͼ����Ҫ����b���������
		}
		d[1] = 0; final[1] = true;   //һ��ʼֻ�����
		for (int i = 0; i < arr[1].size(); ++i)    //�ܴ����ֱ�ӵ���Ķ��㣬�ɵó�·������
			d[arr[1][i].vex] = arr[1][i].cost;
		for (int i = 1; i <= n; ++i)
			q.push(d[i]);   //����һ����
		for (int i = 1; i < n; ++i)   //n-1��ѭ��
		{
			int min = INT_MAX;   //����㵽newp�ľ���
			int newp;
			for (int j = 1; j <= n; ++j)   //�ҳ�δ�ڼ���s�ĵ㵽������̾���
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
				int tp = arr[newp][j].vex;    //��newp�����Ķ���
				int tc = arr[newp][j].cost;   //newp->j�ľ���
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
