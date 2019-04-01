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
//ԭ����Դ��http://www.cnblogs.com/javawebsoa/archive/2013/08/01/3231078.html

int SubStract(int *p1, int *p2, int len1, int len2)   //����������p1-p2,p1�ĳ���λlen1��p2�ĳ���λlen2
{
	int i;
	if (len1 < len2)
		return -1;
	if (len1 == len2)
	{                        //�ж�p1 > p2
		for (i = len1 - 1; i >= 0; i--)
		{
			if (p1[i] > p2[i])   //������������������������
				break;
			else if (p1[i] < p2[i]) //���򷵻�-1
				return -1;
		}
	}
	for (i = 0; i <= len1 - 1; i++)  //�ӵ�λ��ʼ������,�������p1��
	{
		p1[i] -= p2[i];
		if (p1[i] < 0)          //��p1<0������Ҫ��λ
		{
			p1[i] += 10;         //��1��10
			p1[i + 1]--;           //��λ��1
		}
	}
	for (i = len1 - 1; i >= 0; i--)       //���ҽ�������λ
		if (p1[i])                  //���λ��һ����Ϊ0
			return (i + 1);       //�õ�λ��������
	return 0;                  //������ȵ�ʱ�򷵻�0
}


int main()
{
	int n, k, i, j;             //n:������������
	int len1, len2;             //����λ��
	int nTimes;                 //���������λ��
	int nTemp;                  //Subtract��������ֵ
	int num_a[MaxLen];          //������
	int num_b[MaxLen];          //����
	int num_c[MaxLen];          //��
	char str1[MaxLen + 1];      //����ĵ�һ������
	char str2[MaxLen + 1];      //����ĵڶ�������

	scanf("%d", &n);
	while (n-- > 0)
	{
		scanf("%s", str1);        //���ַ�����ʽ�������
		scanf("%s", str2);
		memset(num_a, 0, sizeof(int)*MaxLen);   //������0
		memset(num_b, 0, sizeof(int)*MaxLen);
		memset(num_c, 0, sizeof(int)*MaxLen);
		len1 = strlen(str1);  //��ô�����λ��
		len2 = strlen(str2);
		
		for (j = 0, i = len1 - 1; i >= 0; j++, i--)
			num_a[j] = str1[i] - '0';  //���ַ���ת���ɶ�Ӧ������,�ߵ��洢
		for (j = 0, i = len2 - 1; i >= 0; j++, i--)
			num_b[j] = str2[i] - '0';

		if (len1 < len2)   //���������С�ڳ��������Ϊ0
		{
			printf("0\n");
			continue;   //����continueֱ����������ѭ���� ������һ�����
		}
		//λ������
		nTimes = len1 - len2;    //���λ��
		for (i = len1 - 1; i >= 0; i--)    //����������ʹ�ó����ͱ�����λ�����
		{
			if (i >= nTimes)     //��������
				num_b[i] = num_b[i - nTimes];
			else                     //��λ��0
				num_b[i] = 0;
		}
		len2 = len1;

		for (j = 0; j <= nTimes; j++)      //�ظ����ã�ͬʱ��¼���ɹ��Ĵ�������Ϊ��
		{
			while ((nTemp = SubStract(num_a, num_b + j, len1, len2 - j)) >= 0)
			{
				len1 = nTemp;      //�������
				num_c[nTimes - j]++;//ÿ�ɹ���һ�Σ����̵���Ӧλ��1
			}
		}

		//������
		for (i = MaxLen - 1; num_c[i] == 0 && i >= 0; i--);//������λ0
		if (i >= 0)
			for (; i >= 0; i--)
				printf("%d", num_c[i]);
		else
			printf("0"); 
		printf("\n");
	}

	return 0;
}

