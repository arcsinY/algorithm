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

char s1[1000];     //第一个大数，高位在前，低位在后
char s2[1000];
int n2[1000] = { 0 };     //第二个大数转化后的数组，低位在前，高位在后
int sub[1000] = { 0 };    //存储结果，低位在前，高位在后

int main()
{
	while (scanf("%s %s", s1, s2) != EOF)
	{
		int sign = 0;   //正负号标记，为1时结果是负数
		int len1 = strlen(s1), len2 = strlen(s2);
		//要让第一个数大于第二个数
		if (len1 < len2)   //第一个数位数少
		{
			sign = 1;   //结果为负,交换两个数
			int t = len1;
			len1 = len2;
			len2 = t;
			char tc[1000];
			strcpy(tc, s1);
			strcpy(s1, s2);
			strcpy(s2, tc);
		}
		else if(len1 == len2)   //两个数位数相同
		{
			for (int i = 0; i < len1; ++i)      //从高位开始比较
			{
				if (s1[i] == s2[i])   //该位相同，比较下一位
					continue;
				else if (s1[i] > s2[i])   //第一个数大，符号为正
				{
					sign = 0;
					break;
				}
				else
				{
					sign = 1;
					int t = len1;
					len1 = len2;
					len2 = t;
					char tc[1000];
					strcpy(tc, s1);
					strcpy(s1, s2);
					strcpy(s2, tc);
					break;
				}
			}
		}
		int len = len1 > len2 ? len1 : len2;   //选位数长的
		for (int i = len1 - 1, j = 0; i >= 0; i--, j++)
			sub[j] = s1[i] - '0';   // 转换第一个数 
	    for (int i = len2 - 1, j = 0; i >= 0; i--, j++)
			n2[j] = s2[i] - '0';    // 将两个大数相减 
		for (int i = 0; i < len; ++i)
		{
			sub[i] = sub[i] - n2[i];
			if (sub[i] < 0)
			{
				sub[i] += 10;
				--sub[i + 1];
			}
		}
		int i;
		for (i = len - 1; i >= 0 && sub[i] == 0; --i);   //找到最高位在sub中的下标
		if (sign)
			printf("-");
		while (i >= 0)
			printf("%d", sub[i--]);
		printf("\n");
	}
	return 0;
}

