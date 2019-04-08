#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
void bubbleSort(int* a, int n);  //n个数排序
int main()
{
	int a[10] = { 10,21,42,-21,65,23,77,23,87,90 };
	bubbleSort(a, 10);
	for (int i = 0; i < 10; ++i)
		printf("%d ", a[i]);
	return 0;
}

void bubbleSort(int* a, int n)
{
	for (int i = 0; i < n - 1; ++i)   //总n-1趟排序
	{
		for (int j = 0; j < n - i; ++j)    //最后i个数已经排好序了
		{
			if (a[j] < a[j + 1])   //小的往后交换
			{
				int t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		}
	}
}
