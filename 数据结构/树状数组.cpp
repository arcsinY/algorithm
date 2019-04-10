#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//树状数组：功能与线段树相同，但速度更快
//tree[i]存储数组的某一区间和，若i%(2*n) == 0，则tree[i]存储n个数的和
//形式化表示：tree[i] = a[i-x]+…+a[i],x用lowbit计算

#define MAXN 1000
int tree[MAXN], a[MAXN];   //a数组是原始数组，tree数组是树状数组，之后对a数组的查询和更改都是对于tree数组的操作

int lowbit(int x)        //计算x=2^k，k代表x的二进制从低位开始有多少个连续的0
{
	return x&(-x);
}

void add(int x, int val)   //a[x]的值要加上val,建立tree也用这种方法
{
	while (x < MAXN)
	{
		tree[x] += val;
		x += lowbit(x);
	}
}

int sum(int x)   //计算从a[1]加到a[x]的和
{
	int res = 0;
	while (x > 0)
	{
		res += tree[x];
		x -= lowbit(x);
	}
	return res;
}

int main()
{
	
	return 0;
}

