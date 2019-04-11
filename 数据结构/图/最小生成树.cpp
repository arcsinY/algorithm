#include<bits\stdc++.h>
using namespace std;
/*
	��³˹�����㷨��MST��ʹ�ò��鼯��ѯ��������Ƿ�ͬһ��������
	����:һ������n��������n�����㣬��n=0ʱ�������
		֮��n*(n-1)/2������a b c ����ӽ��a->b��·������Ϊc
	�������С��������·���ܳ�
*/
int tree[100];
edge arr[100];
typedef struct  //�ߵĽṹ��
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
		for (int i = 0; i < n*(n - 1) / 2; ++i)   //ÿ����Ȩֵ��С�ı�
		{ 
			int t1 = find(arr[i].a);   //�ж��Ƿ���һ��������
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
