#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
 
//��������1~n��ȫ����
int a[100];    //һ��������ÿλ������
bool visited[100];   //��¼ĳ�������Ƿ��ù�
int count;  //һ���������
void dfs(int x, int n);  //���õ�a[x]�ϵ�����
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
	if (x == n)  //������
	{
		++count;
		for (int i = 0; i < n; ++i)
			printf("%d ", a[i]);
		printf("\n");
		return;
	}
	for (int i = 1; i <= n; ++i)   //����һλ�Ϸ�1~n
	{
		if (visited[i] == true)   //������ù���
			continue;
		a[x] = i;
		visited[i] = true;
		dfs(x + 1, n);
		visited[i] = false;   //һ�������ɣ�Ҫ����һλ�Ϸ���һ����
	}
}
