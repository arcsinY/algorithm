#include <stdio.h>

//�߶����������洢��������ĺͣ����Ӵ洢��������ĺͣ��Һ��Ӵ洢�Ұ������ĺ͡�
//���ã�����������ĳһ�ε�Ԫ��֮�ͣ�query��������ĳһԪ�أ�update����
//ʱ�临�Ӷȣ���ΪO(logn)������ʱ��ֱ�Ӹ��£�O(1)��������ѯʱ��ѭ����ͣ�O(n)����

int a[7] = { 0,11,23,54,27,80,67 };     //������a�����߶���

int tree[100];   //���߶���������ȫ��������ʵ�ʲ��ǣ���������洢��
                 //���ӱ�� = ���ڵ�*2���Һ��ӱ�� = ���ڵ�*2+1

void build(int n, int l, int r)   //�����߶���,�����Ϊtree[n]����a[l]~a[r]����
{
	if (l == r)    //�ݹ���ڡ��߶�����Ҷ�ӽ��
	{
		tree[n] = a[l];
		return;
	}
	int mid = (l + r) / 2;
	build(n * 2, l, mid);   //����������
	build(n * 2 + 1, mid + 1, r);   //������
	tree[n] = tree[n * 2] + tree[n * 2 + 1];    //��Ҷ�ӽ����������ӽ��֮��
}

int query(int n, int l, int r, int ll, int rr)   //tree[n]�洢����a[l]~a[r]�ĺͣ�Ҫ�����a[ll]~a[rr]�ĺ�
{
	if (l >= ll && r <= rr)   //�ݹ���ڡ�Ҫ�������������ǰ���䣬�������䶼Ҫ
		return tree[n];
	int t1 = 0, t2 = 0;
	int mid = (l + r) / 2;
	if (mid >= ll)   //���������д����Ҳ��֣���Ҫ��������������
		t1 = query(n * 2, l, mid, ll, rr);
	if (mid + 1 <= rr)   //���������д����Ҳ���
		t2 = query(n * 2 + 1, mid + 1, r, ll, rr);
	return t1 + t2;
}

void update(int n, int l, int r, int pos, int val)    //tree[n]�洢����a[l]~a[r]�ĺ�,Ҫ��a[pos]��Ϊval
{
	if (l == r)   //�ݹ���ڡ��ҵ���Ҫ���µ�Ҷ�ӽ��
	{
		tree[n] = val;
		return;
	}
	int mid = (l + r) / 2;
	if (mid >= pos)  //�������и���
		update(n * 2, l, mid, pos, val); 
	else
		update(n * 2 + 1, mid + 1, r, pos, val);
	tree[n] = tree[n * 2] + tree[n * 2 + 1];   //���·�Ҷ�ӽ��
}

int main()
{
	build(1, 1, 6);
	int res = query(1, 1, 6, 2, 5);   //����a[2]~a[5]�ĺ�
	printf("%d\n", res);
	update(1, 1, 6, 3, 55);   //��a[3]��Ϊ55
	res = query(1, 1, 6, 2, 5);
	printf("%d", res);
	return 0;
}
