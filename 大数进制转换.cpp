#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <string>
#include <queue>
#include <map>
#include <limits.h>
#include <math.h>
using namespace std;

//原理来源：https://www.cnblogs.com/fightformylife/p/4022058.html

char s1[1000];     //第一个大数，高位在前，低位在后
int bin[4000];   //二进制
int ind = 0;    //结果数组的下标
void convert(int n, int m);  //n进制转二进制

int main()
{
	while (scanf("%s", s1) != EOF)
	{
		memset(bin, 0, sizeof(bin));
		convert(10,2);
		for (int i = ind-1; i >= 0; --i)
			printf("%d", bin[i]);
		printf("\n");
		ind = 0;
	}
	return 0;
}

void convert(int n, int m)   //n进制转为m进制(n>m)
{
	int len = strlen(s1);	//大数的长度
	int sum = 1;
	while (sum)
	{
		sum = 0;
		for (int i = 0; i < len; ++i)
		{
			int t = (s1[i] - '0') / m;   //当前位运算结果
			sum += t;
			if (i == len - 1)
			{
				bin[ind++] = (s1[i] - '0') % m;    //最后一位产生的余数是这一次运算的余数
			}
			else
			{
				s1[i + 1] += (s1[i]%2) * n;   //下一次的被除数
			}
			s1[i] = t+'0';   //这一位的商
		}
	}
}
