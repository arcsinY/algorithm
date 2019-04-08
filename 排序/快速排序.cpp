#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
void QuickSort(int *a, int high, int low);
int partition(int* a, int high, int low);
int main()
{
	int a[10] = { 10,21,42,-21,65,23,77,23,87,90 };
	QuickSort(a, 9, 0);
	for (int i = 0; i < 10; ++i)
		printf("%d ", a[i]);
	return 0;
}

void QuickSort(int *a, int high, int low)
{
	if (low < high)
	{
		int pivot = partition(a, high, low);
		QuickSort(a, high, pivot + 1);
		QuickSort(a, pivot-1, low);
	}
}

int partition(int* a, int high, int low)
{
	int t = a[low];   //记录pivot
	while (low < high)
	{
		while (low < high && a[high] >= t)
			--high;
		a[low] = a[high];
		while (low < high && a[low] <= t)
			++low;
		a[high] = a[low];
	}
	a[low] = t;    //恢复pivot
	return low;    //返回的是pivot位置下标，不是pivot的值
}