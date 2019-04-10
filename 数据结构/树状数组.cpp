#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//��״���飺�������߶�����ͬ�����ٶȸ���
//tree[i]�洢�����ĳһ����ͣ���i%(2*n) == 0����tree[i]�洢n�����ĺ�
//��ʽ����ʾ��tree[i] = a[i-x]+��+a[i],x��lowbit����

#define MAXN 1000
int tree[MAXN], a[MAXN];   //a������ԭʼ���飬tree��������״���飬֮���a����Ĳ�ѯ�͸��Ķ��Ƕ���tree����Ĳ���

int lowbit(int x)        //����x=2^k��k����x�Ķ����ƴӵ�λ��ʼ�ж��ٸ�������0
{
	return x&(-x);
}

void add(int x, int val)   //a[x]��ֵҪ����val,����treeҲ�����ַ���
{
	while (x < MAXN)
	{
		tree[x] += val;
		x += lowbit(x);
	}
}

int sum(int x)   //�����a[1]�ӵ�a[x]�ĺ�
{
	int res = 0;
	while (x > 0)
	{
		res += tree[x];
		x -= lowbit(x);
	}
	return res;
}

int main()
{
	
	return 0;
}

