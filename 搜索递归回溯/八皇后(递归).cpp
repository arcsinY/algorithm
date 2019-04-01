#include <stdio.h>

void seek(int *q, int b);   //ȷ����b�еĻʺ�λ��
bool conflict(int *q, int n);   //�жϸ�λ���Ƿ��ͻ��n�ǵ�ǰ����-1,����ͻ����false

int sum = 0;   //��¼���м��ֽ�

void main()
{
	int q[8] = { 0 };    //�ʺ�λ�ã�q[0]�����һ�еĻʺ��ڵڼ���
	seek(q, 1);
	printf("����%d�ֽⷨ\n", sum);
}


void seek(int *q, int b)
{
	if (b > 8)   //�ڰ����Ѿ����úã�һ�ֽⷨ����
	{
		++sum;
		return;
	}
	for (int i = 1; i <= 8; ++i)      //ÿһ��seek�����˳��󣬷�����һ�㣬�ʺ�λ��+1����������
	{
		q[b - 1] = i;   //�����ڵ�i����
		if (!conflict(q, b - 1))   //�ж����λ�ò���ͻ���ݹ����seek������������һ���ʺ�
		{
				seek(q, b + 1);
				q[b - 1] = 0;  //���¾�����һ���ϵĻʺ�λ��
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
