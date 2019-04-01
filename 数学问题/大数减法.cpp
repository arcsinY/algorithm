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

char s1[1000];     //��һ����������λ��ǰ����λ�ں�
char s2[1000];
int n2[1000] = { 0 };     //�ڶ�������ת��������飬��λ��ǰ����λ�ں�
int sub[1000] = { 0 };    //�洢�������λ��ǰ����λ�ں�

int main()
{
	while (scanf("%s %s", s1, s2) != EOF)
	{
		int sign = 0;   //�����ű�ǣ�Ϊ1ʱ����Ǹ���
		int len1 = strlen(s1), len2 = strlen(s2);
		//Ҫ�õ�һ�������ڵڶ�����
		if (len1 < len2)   //��һ����λ����
		{
			sign = 1;   //���Ϊ��,����������
			int t = len1;
			len1 = len2;
			len2 = t;
			char tc[1000];
			strcpy(tc, s1);
			strcpy(s1, s2);
			strcpy(s2, tc);
		}
		else if(len1 == len2)   //������λ����ͬ
		{
			for (int i = 0; i < len1; ++i)      //�Ӹ�λ��ʼ�Ƚ�
			{
				if (s1[i] == s2[i])   //��λ��ͬ���Ƚ���һλ
					continue;
				else if (s1[i] > s2[i])   //��һ�����󣬷���Ϊ��
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
		int len = len1 > len2 ? len1 : len2;   //ѡλ������
		for (int i = len1 - 1, j = 0; i >= 0; i--, j++)
			sub[j] = s1[i] - '0';   // ת����һ���� 
	    for (int i = len2 - 1, j = 0; i >= 0; i--, j++)
			n2[j] = s2[i] - '0';    // ������������� 
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
		for (i = len - 1; i >= 0 && sub[i] == 0; --i);   //�ҵ����λ��sub�е��±�
		if (sign)
			printf("-");
		while (i >= 0)
			printf("%d", sub[i--]);
		printf("\n");
	}
	return 0;
}

