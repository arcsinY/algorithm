#include <stdio.h>
int main()
{
	int n; int a[101];
	int left[101], right[101];   //left[i]��ʾ�������ҿ�����a[i]��β������������еĳ��ȣ�right[i]��ʾ��������
	while (scanf("%d", &n) != EOF)
	{
		for (int i = 0; i < n; ++i)
			scanf("%d", &a[i]);
		for (int i = 0; i < n; ++i)    //��a[0]~a[i]��Ѱ��������
		{
			left[i] = 1;
			for (int j = 0; j <= i; ++j)
			{
				if (a[j] < a[i])   //����һ�������У���a[j]֮���a[i]
					left[i] = left[i] > left[j] + 1 ? left[i] : left[j] + 1;
			}
		}
		for (int i = n - 1; i >= 0; --i)
		{
			right[i] = 1;
			for (int j = n - 1; j >= i; --j)
			{
				if (a[j] < a[i])
					right[i] = right[i] > right[j] + 1 ? right[i] : right[j] + 1;
			}
		}
	}
	return 0;
}
