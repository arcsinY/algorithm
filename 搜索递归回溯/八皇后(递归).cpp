#include <stdio.h>

void seek(int *q, int b);   //确定第b列的皇后位置
bool conflict(int *q, int n);   //判断该位置是否冲突，n是当前列数-1,不冲突返回false

int sum = 0;   //记录共有几种解

void main()
{
	int q[8] = { 0 };    //皇后位置，q[0]代表第一列的皇后在第几行
	seek(q, 1);
	printf("共有%d种解法\n", sum);
}


void seek(int *q, int b)
{
	if (b > 8)   //第八列已经放置好，一种解法结束
	{
		++sum;
		return;
	}
	for (int i = 1; i <= 8; ++i)      //每一层seek函数退出后，返回上一层，皇后位置+1，继续尝试
	{
		q[b - 1] = i;   //放置在第i行上
		if (!conflict(q, b - 1))   //判断如果位置不冲突，递归调用seek函数，放置下一个皇后
		{
				seek(q, b + 1);
				q[b - 1] = 0;  //重新决定这一列上的皇后位置
		}
	}
}

bool conflict(int *q, int n)
{
	for (int i = 0; i < n; ++i)
	{
		if (q[i] == q[n] || q[i] - q[n] == i - n || q[i] - q[n] == n - i)
			return true;
	}
	return false;
}
