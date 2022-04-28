#include <stdio.h>
#include <string.h>
int select(int* a, int low, int high, int k)  //从a[low]到a[high]中选出第k小的数
{
	int l = low;
	int h = high;
	int pivot = a[low];
	while (l < h) {
		while (l < h && a[h] > pivot) {
			--h;
		}
		a[l] = a[h];
		while (l < h && a[l] < pivot) {
			++l;
		}
		a[h] = a[l];
	}
	a[l] = pivot;
	//比pivot小的数有k-1个，pivot就是要找的
	if (l - low + 1 == k) {
		return pivot;
	}
	//比pivot小的数不到k-1个，在右半部分寻找
	if (l - low + 1 < k)  {
		return select(a, l + 1, high, k - (l - low + 1));	
	}
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
