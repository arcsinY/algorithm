#include <stdio.h>

//线段树：根结点存储整个数组的和，左孩子存储左半个数组的和，右孩子存储右半个数组的和。
//作用：计算数组中某一段的元素之和（query），更新某一元素（update）。
//时间复杂度：均为O(logn)。更新时比直接更新（O(1)）慢，查询时比循环求和（O(n)）快

int a[7] = { 0,11,23,54,27,80,67 };     //对数组a建立线段树

int tree[100];   //把线段树看作完全二叉树（实际不是），用数组存储。
                 //左孩子编号 = 父节点*2，右孩子编号 = 父节点*2+1

void build(int n, int l, int r)   //建立线段树,根结点为tree[n]，对a[l]~a[r]建树
{
	if (l == r)    //递归出口。线段树的叶子结点
	{
		tree[n] = a[l];
		return;
	}
	int mid = (l + r) / 2;
	build(n * 2, l, mid);   //建立左子树
	build(n * 2 + 1, mid + 1, r);   //右子树
	tree[n] = tree[n * 2] + tree[n * 2 + 1];    //非叶子结点等于左右子结点之和
}

int query(int n, int l, int r, int ll, int rr)   //tree[n]存储的是a[l]~a[r]的和，要求计算a[ll]~a[rr]的和
{
	if (l >= ll && r <= rr)   //递归出口。要计算区间包含当前区间，整个区间都要
		return tree[n];
	int t1 = 0, t2 = 0;
	int mid = (l + r) / 2;
	if (mid >= ll)   //左子树中有待查找部分，需要进入左子树查找
		t1 = query(n * 2, l, mid, ll, rr);
	if (mid + 1 <= rr)   //右子树中有带查找部分
		t2 = query(n * 2 + 1, mid + 1, r, ll, rr);
	return t1 + t2;
}

void update(int n, int l, int r, int pos, int val)    //tree[n]存储的是a[l]~a[r]的和,要将a[pos]改为val
{
	if (l == r)   //递归出口。找到了要更新的叶子结点
	{
		tree[n] = val;
		return;
	}
	int mid = (l + r) / 2;
	if (mid >= pos)  //在左孩子中更新
		update(n * 2, l, mid, pos, val); 
	else
		update(n * 2 + 1, mid + 1, r, pos, val);
	tree[n] = tree[n * 2] + tree[n * 2 + 1];   //更新非叶子结点
}

int main()
{
	build(1, 1, 6);
	int res = query(1, 1, 6, 2, 5);   //计算a[2]~a[5]的和
	printf("%d\n", res);
	update(1, 1, 6, 3, 55);   //将a[3]变为55
	res = query(1, 1, 6, 2, 5);
	printf("%d", res);
	return 0;
}
