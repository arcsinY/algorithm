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
#define MaxLen 1000
//原理来源：http://www.cnblogs.com/javawebsoa/archive/2013/08/01/3231078.html

int SubStract(int *p1, int *p2, int len1, int len2)   //大数减法，p1-p2,p1的长度位len1，p2的长度位len2
{
	int i;
	if (len1 < len2)
		return -1;
	if (len1 == len2)
	{                        //判断p1 > p2
		for (i = len1 - 1; i >= 0; i--)
		{
			if (p1[i] > p2[i])   //若大，则满足条件，可做减法
				break;
			else if (p1[i] < p2[i]) //否则返回-1
				return -1;
		}
	}
	for (i = 0; i <= len1 - 1; i++)  //从低位开始做减法,结果存在p1中
	{
		p1[i] -= p2[i];
		if (p1[i] < 0)          //若p1<0，则需要借位
		{
			p1[i] += 10;         //借1当10
			p1[i + 1]--;           //高位减1
		}
	}
	for (i = len1 - 1; i >= 0; i--)       //查找结果的最高位
		if (p1[i])                  //最高位第一个不为0
			return (i + 1);       //得到位数并返回
	return 0;                  //两数相等的时候返回0
}


int main()
{
	int n, k, i, j;             //n:测试数据组数
	int len1, len2;             //大数位数
	int nTimes;                 //两大数相差位数
	int nTemp;                  //Subtract函数返回值
	int num_a[MaxLen];          //被除数
	int num_b[MaxLen];          //除数
	int num_c[MaxLen];          //商
	char str1[MaxLen + 1];      //读入的第一个大数
	char str2[MaxLen + 1];      //读入的第二个大数

	scanf("%d", &n);
	while (n-- > 0)
	{
		scanf("%s", str1);        //以字符串形式读入大数
		scanf("%s", str2);
		memset(num_a, 0, sizeof(int)*MaxLen);   //数组清0
		memset(num_b, 0, sizeof(int)*MaxLen);
		memset(num_c, 0, sizeof(int)*MaxLen);
		len1 = strlen(str1);  //获得大数的位数
		len2 = strlen(str2);
		
		for (j = 0, i = len1 - 1; i >= 0; j++, i--)
			num_a[j] = str1[i] - '0';  //将字符串转换成对应的整数,颠倒存储
		for (j = 0, i = len2 - 1; i >= 0; j++, i--)
			num_b[j] = str2[i] - '0';

		if (len1 < len2)   //如果被除数小于除数，结果为0
		{
			printf("0\n");
			continue;   //利用continue直接跳出本次循环。 进入下一组测试
		}
		//位数对齐
		nTimes = len1 - len2;    //相差位数
		for (i = len1 - 1; i >= 0; i--)    //将除数扩大，使得除数和被除数位数相等
		{
			if (i >= nTimes)     //除数左移
				num_b[i] = num_b[i - nTimes];
			else                     //低位置0
				num_b[i] = 0;
		}
		len2 = len1;

		for (j = 0; j <= nTimes; j++)      //重复调用，同时记录减成功的次数，即为商
		{
			while ((nTemp = SubStract(num_a, num_b + j, len1, len2 - j)) >= 0)
			{
				len1 = nTemp;      //结果长度
				num_c[nTimes - j]++;//每成功减一次，将商的相应位加1
			}
		}

		//输出结果
		for (i = MaxLen - 1; num_c[i] == 0 && i >= 0; i--);//跳过高位0
		if (i >= 0)
			for (; i >= 0; i--)
				printf("%d", num_c[i]);
		else
			printf("0"); 
		printf("\n");
	}

	return 0;
}

