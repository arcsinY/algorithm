#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <string>
#include <queue>
#include <limits.h>
#include <math.h>
using namespace std;
int res[10000];
int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		int index = 0;   //�����±�
		int up = 0;    //��λ
		res[0] = 1;
		for (int i = 1; i <= n; ++i)      //�׳�
		{
			for (int j = 0; j <= index; ++j)    //ÿ�γ˷�
			{
				int t = (res[j] * i + up) / 10;   //��������Ľ�λ
				res[j] = (res[j] * i + up) % 10;
				up = t;
			}
			while (up)
			{
				res[++index] = up % 10;
				up /= 10;
			}
		}
		for (int i = index; i >= 0; --i)   //���
		{
			printf("%d", res[i]);
		}
		printf("\n");
	}
	return 0;
}
