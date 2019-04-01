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
int sum[1000] = { 0 };    //存储结果，低位在前，高位在后

int main()
{
	while (scanf("%s %s", s1, s2) != EOF)
	{
		int len1 = strlen(s1);
		int len2 = strlen(s2);
		int len = len1 > len2 ? len1 : len2;   //较大长度
		for (int i = len1 - 1, j = 0; i >= 0; i--, j++)   //第一个数存进sum
			sum[j] = s1[i] - '0';     
		for (int i = len2 - 1, j = 0; i >= 0; i--, j++)   //第二个数存进n2
			n2[j] = s2[i] - '0';
		for (int i = 0; i < len; ++i)
		{
			sum[i] += n2[i];
			if (sum[i] >= 10)  //有进位
			{
				sum[i] -= 10;
				++sum[i + 1];
			}
		}
		if (sum[len] != 0)
			++len;
		for (int i = len-1; i >= 0; --i)
			printf("%d", sum[i]);
		printf("\n");
		memset(n2, 0, sizeof(n2));
		memset(sum, 0, sizeof(sum));
	}
	return 0;
}

