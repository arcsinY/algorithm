#include<bits\stdc++.h>
using namespace std;
/*
	克鲁斯卡尔算法求MST，使用并查集查询两个结点是否同一个集合中
	输入:一个整数n，代表有n个顶点，当n=0时输入结束
		之后n*(n-1)/2行输入a b c 代表从结点a->b的路径长度为c
	输出：最小生成树的路径总长
*/
int tree[100];
edge arr[100];
typedef struct  //边的结构体
{
	int a, b;
	int cost;
}edge;
int find(int i)   
{
	if (tree[i] == -1)
		return i;
	int t = find(tree[i]);
	tree[i] = t;
	return t;
}
bool cmp(edge a, edge b)
{
	return a.cost < b.cost;
}
int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		memset(tree, -1, sizeof(tree));
		memset(arr, 0, sizeof(arr));
		int res = 0;
		if (n == 0)
			break;
		for (int i = 0; i < n*(n - 1) / 2; ++i)
			scanf("%d %d %d", &arr[i].a, &arr[i].b, &arr[i].cost);
		sort(arr, arr + n, cmp);
		for (int i = 0; i < n*(n - 1) / 2; ++i)   //每次找权值最小的边
		{ 
			int t1 = find(arr[i].a);   //判断是否在一个集合中
			int t2 = find(arr[i].b);
			if (t1 != t2)
			{
				tree[t1] = t2;
				res += arr[i].cost;
			}
		}
		printf("%d\n", res);
	}
	return 0;
}
