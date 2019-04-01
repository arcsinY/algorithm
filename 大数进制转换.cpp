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

//ԭ����Դ��https://www.cnblogs.com/fightformylife/p/4022058.html

char s1[1000];     //��һ����������λ��ǰ����λ�ں�
int bin[4000];   //������
int ind = 0;    //���������±�
void convert(int n, int m);  //n����ת������

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

void convert(int n, int m)   //n����תΪm����(n>m)
{
	int len = strlen(s1);	//�����ĳ���
	int sum = 1;
	while (sum)
	{
		sum = 0;
		for (int i = 0; i < len; ++i)
		{
			int t = (s1[i] - '0') / m;   //��ǰλ������
			sum += t;
			if (i == len - 1)
			{
				bin[ind++] = (s1[i] - '0') % m;    //���һλ��������������һ�����������
			}
			else
			{
				s1[i + 1] += (s1[i]%2) * n;   //��һ�εı�����
			}
			s1[i] = t+'0';   //��һλ����
		}
	}
}
