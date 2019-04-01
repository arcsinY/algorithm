#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
 
//计算数字1~n的全排列
int a[100];    //一次排列中每位的数字
bool visited[100];   //记录某个数字是否用过
int count;  //一共的组合数
void dfs(int x, int n);  //放置第a[x]上的数字
int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		dfs(0, n);
	}
	return 0;
}

void dfs(int x, int n)
{
	if (x == n)  //放完了
	{
		++count;
		for (int i = 0; i < n; ++i)
			printf("%d ", a[i]);
		printf("\n");
		return;
	}
	for (int i = 1; i <= n; ++i)   //在这一位上放1~n
	{
		if (visited[i] == true)   //这个数用过了
			continue;
		a[x] = i;
		visited[i] = true;
		dfs(x + 1, n);
		visited[i] = false;   //一次组合完成，要在这一位上放另一个数
	}
}
