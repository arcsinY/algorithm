#include <stdio.h>
#include <string.h>
int select(int* a, int low, int high, int k)  //��a[low]��a[high]��ѡ����kС����
{
	int l = low;
	int h = high;
	int pivot = a[low];
	while (l < h)
	{
		while (l < h && a[h] > pivot)
			--h;
		a[l] = a[h];
		while (l < h && a[l] < pivot)
			++l;
		a[h] = a[l];
	}
	a[l] = pivot;
	if (l - low + 1 == k)  //��pivotС������k-1����pivot����Ҫ�ҵ�
		return pivot;
	else if (l - low + 1 < k)  //��pivotС��������k-1�������Ұ벿��Ѱ��
		return select(a, l + 1, high, k - (l - low + 1));
	else
		return select(a, low, l - 1, k);
}
int main()
{
	int n, k;
	int a[1000];
	while (scanf("%d %d", &n, &k) != EOF)
	{
		for (int i = 0; i < n; ++i)
			scanf("%d", &a[i]);
		int min_k = select(a, 0, n-1, k);
		printf("%d\n", min_k);
	}
	return 0;
}
