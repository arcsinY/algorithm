//һ��N*M�ľ����ҳ����������Ԫ�غͲ�С��K�������С���Ӿ��󣨾�����Ԫ�ظ���Ϊ��������� 
//�����ڶ�̬�滮����С�Ӿ��󣬽�����������мӵ�һ���ϣ�����������ת��Ϊ��������
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
int martix[101][101];
int sum[101]; 
int shortest(int m, int k);
int main()
{
	int n, m, k;
	while (scanf("%d %d %d", &n, &m, &k) != EOF)
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
				scanf("%d", &martix[i][j]);
		}
		int area = INT_MAX;   //���
		for (int i = 0; i < n; ++i)   //��������
		{
			for (int j = 0; j < m; ++j)   //��������
				sum[j] = 0;
			for (int a = i; a < n; ++a)    //�ӵ�ǰ�кϲ������һ��
			{
				for (int b = 0; b < m; ++b)
					sum[b] += martix[a][b];
				int len = shortest(m, k);  //�Ӿ���Ŀ��
				if (len != INT_MAX)
				{
					if (len*(a - i + 1) < area)  //���������С
						area = len*(a - i + 1);
				}
			}
		}
		if (area == INT_MAX)
			printf("-1\n");
		else
			printf("%d\n", area);
	}
	return 0;
}

int shortest(int m,int k)   //�ڳ���Ϊm������sum����Ͳ�С��k�����������ĳ���
{
	int from = 0, to = 0;  //�����������յ�
	int len = INT_MAX;  //�����鳤��
	int x = 0;   //������Ԫ�غ�
	while (to < m)
	{
		while (x < k && to < m)   //�ҵ�һ��������
		{
			x += sum[to];
			++to;
		}
		while (x >= k && from < to - 1)
		{
			if (len > to - from)
				len = to - from;    //�ҵ����̵�
			x -= sum[from];
			++from;    //������
		}
		if (from == to - 1)
			return 1;
	}
	return len;
}
